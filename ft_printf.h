/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:38:59 by zslowian          #+#    #+#             */
/*   Updated: 2024/04/03 21:38:59 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#define BUF_SIZE	(1 << 12)
#define FLAGS		"+ 0-#"
#define NUMBERS		"0123456789"
#define SPECIFIERS	"cspdiuxX%"

#include "libft.h"
#include <stdlib.h> // malloc free
#include <unistd.h> // write
#include <stdarg.h> // variadic macros
#include <limits.h> // INT_MAX, INT_MIN

typedef struct s_format
{
	// flags
	bool	minus;
	bool	plus;
	bool	space;
	bool	hash;
	bool	zero_pad;
	// cspdiuxX% format specifiers
	char	specifier;
	e_base	base;
	bool	upper_case;
	// width and precision values
	int		width;
	int		precision;

}	t_format;

typedef struct s_data
{
	const char	*str;
	t_format	format;
	va_list		arg_ptr;
	int			nbr_chars;
	char		*buffer;
	int			buffer_index;
}	t_data;

typedef enum
{
	OK = 0,
	MALLOC_ERROR = -67,
	PARSE_ERROR = -87,
}	e_error;

typedef enum
{
	BASE_2 = 2,
	BASE_8 = 8,
	BASE_10 = 10,
	BASE_16 = 16,
}	e_base;

typedef unsigned char	byte;

bool	ft_in(const char *str, char c);
int		ft_parsef(t_data *data);
int		ft_printf(const char *, ...);
void	my_memset(void *ptr, int value, size_t n);

#endif
