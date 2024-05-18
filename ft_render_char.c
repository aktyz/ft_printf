/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:30:08 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/18 21:24:22 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_render_char(t_data *data, int c)
{
	int	width;

	width = data->format.width;
	if (width > 1)
	{
		if (data->format.minus)
		{
			ft_putchar_buffer((char)c, 1, data);
			ft_putchar_buffer(' ', width - 1, data);
		}
		else
		{
			ft_putchar_buffer(' ', width - 1, data);
			ft_putchar_buffer((char)c, 1, data);
		}
	}
	ft_putchar_buffer((char)c, 1, data);
}
