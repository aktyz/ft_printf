/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:28:24 by zslowian          #+#    #+#             */
/*   Updated: 2024/08/23 19:34:10 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_negate_number(t_data *data, t_value int_value);

void	ft_negate_number(t_data *data, t_value int_value)
{
	int_value.l_value = -(int_value.l_value);
	ft_putchar_buffer('-', 1, data);
	data->format.is_number_negated = true;
	ft_itoa_buffer(data, int_value);
}
