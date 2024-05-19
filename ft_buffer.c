/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:06:20 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/19 14:20:38 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_buffer(t_data *data, char c)
{
	if (data->buffer_index == BUF_SIZE)
	{
		ft_flush_buffer(data);
	}
	data->buffer[data->buffer_index++] = c;
}

void	ft_flush_buffer(t_data *data)
{
	data->nbr_chars += write(STDOUT_FILENO, data->buffer, data->buffer_index);
	my_memset(data->buffer, 0, BUF_SIZE);
	data->buffer_index = 0;
}

void	ft_putchar_buffer(char c, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	while (precision--)
		ft_write_buffer(data, c);
}
