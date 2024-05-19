/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/05/18 21:19:07 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/18 21:19:07 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUF_SIZE 4096
# define FLAGS "+ 0-#"
# define NUMBERS "0123456789"
# define SPECIFIERS "cspdiuxX%"

//#include "libft.h" TODO: work it out
# include <limits.h> // INT_MAX, INT_MIN
# include <stdarg.h> // variadic macros
# include <stdbool.h>
# include <stdlib.h> // malloc free
# include <unistd.h> // write

typedef enum
{
	BASE_2 = 2,
	BASE_8 = 8,
	BASE_10 = 10,
	BASE_16 = 16,
}	e_base;

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

typedef unsigned char	t_byte;

bool	ft_in(const char *str, char c);
int		ft_parsef(t_data *data);
int		ft_printf(const char *, ...);
void	my_memset(void *ptr, t_byte value, size_t n);
void	ft_write_buffer(t_data *data, char c);
void	ft_flush_buffer(t_data *data);
void	ft_putchar_buffer(char c, int precision, t_data *data);
void	ft_render_char(t_data *data, int c);

#endif