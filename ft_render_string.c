/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:53:41 by zslowian          #+#    #+#             */
/*   Updated: 2024/08/18 19:46:19 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_render_string(t_data *data, char *str);
static void	ft_set_nbr_padding_spaces(t_data *data, char *s);

/**
 * Wrapper around ft_putstring_buffer function
 * to handle the left adjustment and potential
 * padding
 *
 */
void	ft_render_string(t_data *data, char *str)
{
	if (str == NULL)
	{
		str = "(null)";
	}
	ft_set_nbr_padding_spaces(data, str);
	// The error happens somewhere here -> TODO: find it and repair
	if (data->format.minus)
	{
		if (data->format.precision)
			ft_putstring_buffer(str, data->format.precision, data);
		else
			ft_putstring_buffer(str, ft_strlen(str), data);
		ft_putstring_buffer(PADDING_SPACE, data->format.nbr_padding_spaces,
			data);
	}
	else
	{
		ft_putstring_buffer(PADDING_SPACE, data->format.nbr_padding_spaces,
			data);
		if (data->format.precision)
			ft_putstring_buffer(str, data->format.precision, data);
		else
		{
			ft_putstring_buffer(str, ft_strlen(str), data);
		}
	}
}

/**
 * Calculate and set the number of padding spaces
 * in the memory of data structure
 *
 */
static void	ft_set_nbr_padding_spaces(t_data *data, char *str)
{
	int	length;

	length = ft_strlen(str);
	if (data->format.width > 0)
	{
		if (data->format.precision > 0)
		{
			if (data->format.precision >= length)
				data->format.nbr_padding_spaces = data->format.width - length;
			else if (data->format.precision < length)
				data->format.nbr_padding_spaces = data->format.width
					- data->format.precision;
		}
		else
			data->format.nbr_padding_spaces = data->format.width - length;
	}
}
