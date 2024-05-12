/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:23:32 by zslowian          #+#    #+#             */
/*   Updated: 2024/04/03 21:23:32 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_initialize_data(t_data *data, const char *format);

int	ft_printf(const char *format, ...)
{
	t_data	data;
	va_start(data.arg_ptr, format);
	if (ft_initialize_data(&data, format))
		return -1;
	while (*data.str != '\0')
	{
		if (*data.str == '%' &&  *(++data.str))
		{
			if (ft_parsef(&data))
				return (PARSE_ERROR);
			render_format(&data);
		}
		else
			write_buffer(&data, *data.str);
		++data.str;
	}
	flush_buffer(&data);
	va_end(data.arg_ptr);
	free(data.buffer);
	return (data.nbr_chars);
}

static int	ft_initialize_data(t_data *data, const char *format)
{
	data -> nbr_chars = 0;
	data -> str = format;
	data -> buffer = malloc(BUF_SIZE * sizeof(char));
	if (NULL == data -> buffer)
		return MALLOC_ERROR;
	data -> buffer_index = 0;
	//ft_memset(data -> buffer, 0, BUF_SIZE * sizeof(char));//TODO: replace with included Libft
	my_memset(data -> buffer, 0, BUF_SIZE * sizeof(char));
	return (OK);
}
