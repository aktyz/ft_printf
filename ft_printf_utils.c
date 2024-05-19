/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:18:44 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/18 21:18:44 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	my_memset(void *ptr, t_byte value, size_t n)
{
	t_byte	*ptr_byte;

	ptr_byte = (t_byte *)ptr;
	while (n)
	{
		*ptr_byte++ = value;
		--n;
	}
}

bool	ft_in(const char *str, char c)
{
	if (str == 0)
		return (false);
	while (*str)
	{
		if (*str == c)
			return (true);
		++str;
	}
	return (false);
}
