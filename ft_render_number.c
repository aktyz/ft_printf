/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:48:27 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/21 18:48:27 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Wrapper around ft_putnumber_buffer function
 * to handle the left adjustment and all the flags
 *
 */
void	ft_render_number(t_data *data, t_value int_value)
{
	ft_itoa_buffer(data, int_value);
	ft_set_padding_zeros(data);
	ft_set_padding_spaces(data);
	if (data->format.left_justified)
	{}
	else
	{}
}
