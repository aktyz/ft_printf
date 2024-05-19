/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsef.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:18:30 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/18 21:18:30 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_flags(t_data *data);
static void	ft_get_value(t_data *data, int *value);
static int	my_atoi(t_data *data);

int	ft_parsef(t_data *data)
{
	// ft_memset(data -> format, 0,
	//sizeof(t_format));//TODO: replace with included Libft
	my_memset(&data->format, 0, sizeof(t_format));
	data->format.precision = -1;
	ft_parse_flags(data);
	ft_get_value(data, &data->format.width);
	if (*data->str == '.' && *(++data->str))
		ft_get_value(data, &data->format.precision);
	if (!ft_in(SPECIFIERS, *data->str))
		return (PARSE_ERROR);
	else
	{
		data->format.specifier = *data->str;
		if (ft_in("diu", data->format.specifier))
			data->format.base = BASE_10;
		else if (ft_in("xXp", data->format.specifier))
		{
			data->format.base = BASE_16;
			if ('X' == data->format.specifier)
				data->format.upper_case = true;
		}
	}
	return (OK);
}

static void	ft_parse_flags(t_data *data)
{
	char	flag;

	while (ft_in(FLAGS, *data->str))
	{
		flag = *data->str;
		if ('0' == flag)
			data->format.zero_pad = true;
		else if ('+' == flag)
			data->format.plus = true;
		else if (' ' == flag)
			data->format.space = true;
		else if ('-' == flag)
			data->format.minus = true;
		else if ('#' == flag)
			data->format.hash = true;
		++data->str;
	}
}

static void	ft_get_value(t_data *data, int *value)
{
	if (*data->str == '*')
	{
		*value = va_arg(data->arg_ptr, int);
		++data->str;
	}
	else
		*value = my_atoi(data);
	//*value = ft_atoi(data); //TODO: replace with included Libft
}

static int	my_atoi(t_data *data)
{
	int	value;

	value = 0;
	while (ft_in(NUMBERS, *data->str))
		value = (value * 10) + (*data->str++ - '0');
	return (value);
}
