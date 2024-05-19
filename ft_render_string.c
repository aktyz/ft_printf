/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:53:41 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/19 19:58:25 by zslowian         ###   ########.fr       */
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
	//printf("(ft_render_string) My string to be printed instead of %%s: %s", str);
	ft_set_nbr_padding_spaces(data, str);
	//printf("(ft_render_string) My string to be printed instead of %%s: %s", str);
	//print_my_structure("ft_render_string", data);
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
		//printf("I should be here because there is no minus flag set\n\n");
		if (data->format.precision)
			ft_putstring_buffer(str, data->format.precision, data);
		else
		{
			//printf("(ft_render_string) I should be here with %s", str);
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
