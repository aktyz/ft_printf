/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:06:20 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/19 15:36:49 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_buffer(t_data *data, char c);
void	ft_flush_buffer(t_data *data);
void	ft_putchar_buffer(char c, int precision, t_data *data);
void	ft_putstring_buffer(char *str, int precision, t_data *data);

/**
 * Function to write a Character c in the
 * memory buffer
 *
 **/
void	ft_write_buffer(t_data *data, char c)
{
	if (data->buffer_index == BUF_SIZE)
	{
		ft_flush_buffer(data);
	}
	data->buffer[data->buffer_index++] = c;
}

/**
 * Function to clean the buffer
 * (buffer memory set to 0 aka NULLs)
 *
 **/
void	ft_flush_buffer(t_data *data)
{
	data->nbr_chars += write(STDOUT_FILENO, data->buffer, data->buffer_index);
	my_memset(data->buffer, 0, BUF_SIZE);
	data->buffer_index = 0;
}

/**
 * Function to put into the buffer one Character c
 * taking field width (here precision) into account
 *
 **/
void	ft_putchar_buffer(char c, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	while (precision--)
		ft_write_buffer(data, c);
}

/**
 * Function to put into the buffer a String str
 * taking field width (here precision) into account
 *
 **/
void	ft_putstring_buffer(char *str, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	while (precision-- && *str)
		ft_write_buffer(data, *str++);
}
