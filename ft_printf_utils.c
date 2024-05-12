/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:44:53 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/12 14:44:53 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	my_memset(void *ptr, int value, size_t n)
{
	byte	*ptr_byte;

	ptr_byte = (byte *)ptr;
	while (n)
	{
		*ptr_byte++ = 0;
		--n;
	}
}

bool	ft_in(const char *str, char c)
{
	if(str == 0)
		return false;
	while (*str)
	{
		if (*str == c)
			return true;
		++str;
	}
	return false;
}
