/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/05/18 21:18:10 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/18 21:18:10 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_initialize_data(t_data *data, const char *format);
void		ft_render_format(t_data *data);

/**
 * Function replicating the behaviour of stdio.h
 * printf()
 *
 */
int	ft_printf(const char *str, ...)
{
	t_data	data;

	va_start(data.arg_ptr, str);
	if (ft_initialize_data(&data, str))
		return (MALLOC_ERROR);
	while (*data.str != '\0')
	{
		if (*data.str == '%' && *(++data.str))
		{
			if (ft_parsef(&data))
				return (PARSE_ERROR);
			ft_render_format(&data);
		}
		else
			ft_write_buffer(&data, *data.str);
		++data.str;
	}
	ft_flush_buffer(&data);
	va_end(data.arg_ptr);
	free(data.buffer);
	return (data.nbr_chars);
}

/**
 * Function that is initializing t_data structure to hold
 * all the necessary information for printf to work
 * properly
 *
 */
static int	ft_initialize_data(t_data *data, const char *format_string)
{
	data->nbr_chars = 0;
	data->str = format_string;
	data->buffer = malloc(BUF_SIZE * sizeof(char));
	if (NULL == data->buffer)
		return (MALLOC_ERROR);
	data->buffer_index = 0;
	my_memset(data->buffer, 0, BUF_SIZE * sizeof(char));
	return (OK);
}

/**
 * Function switching between correct wrappers depending on
 * the format specifier: "cspdiuxX%"
 */
void	ft_render_format(t_data *data)
{
	char	specifier;
	t_value	int_value;

	specifier = data->format.specifier;
	int_value.l_value = 0;
	if (specifier == '%')
		ft_render_char(data, '%');
	else if (specifier == 'c')
		ft_render_char(data, va_arg(data->arg_ptr, int));
	else if (specifier == 's')
		ft_render_string(data, va_arg(data->arg_ptr, char *));
	if (ft_in("pdiuxX", specifier))
	{
		if (ft_in("di", specifier))
		{
			int_value.l_value = (long) va_arg(data->arg_ptr, int);
			if (int_value.l_value < 0)
				data->format.is_number_negative = true;
		}
		else if (specifier == 'p')
			int_value.ul_value = (unsigned long) va_arg(data->arg_ptr, void *);
		else if (ft_in("uxX", specifier))
			int_value.ul_value = (unsigned long) va_arg(data->arg_ptr, unsigned int);
		ft_render_number(data, int_value);
	}
}
