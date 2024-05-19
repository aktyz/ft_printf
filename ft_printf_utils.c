/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:36:08 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/19 15:36:08 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	my_memset(void *ptr, t_byte value, size_t n);
bool	ft_in(const char *str, char c);
int		ft_strlen(const char *str);

/**
 * Set the memory under pointer ptr of size n
 * with unsigned char value
 *
 */
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

/**
 * Check if Character c is one of chars
 * inside string str
 *
 */
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

/**
 * Return length of string str
 *
 */
int	ft_strlen(const char *str)
{
	if (str == NULL || !*str)
		return (0);
	return (ft_strlen(str + 1) + 1);
}
