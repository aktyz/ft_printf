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
# define PADDING_SPACE " "

//#include "libft.h" TODO: work it out
# include <limits.h> // INT_MAX, INT_MIN
# include <stdarg.h> // variadic macros
# include <stdbool.h>
# include <stdlib.h> // malloc free
# include <unistd.h> // write
# include <stdio.h>

typedef enum e_base
{
	BASE_2 = 2,
	BASE_8 = 8,
	BASE_10 = 10,
	BASE_16 = 16,
}	t_base;

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
	t_base	base;
	bool	upper_case;
	// width and precision values
	int		width;
	int		precision;
	int		nbr_padding_spaces;

}	t_format;
/**
 * Major ft_printf library structure holding all the necessary data
 * to output the string correctly to the STD_OUT
 */
typedef struct s_data
{
	// Format string - first argument to the printf function
	const char	*str;
	// ft_printf library structure holding all the formatting flags
	t_format	format;
	// My variable list of arguments
	va_list		arg_ptr;
	// Number of chars output in the end (returned from ft_printf)
	int			nbr_chars;
	// Pointer to my 4K memory buffer
	char		*buffer;
	// Index of the next empty int slot in tbe memory buffer
	int			buffer_index;
}	t_data;

typedef enum e_error
{
	OK = 0,
	MALLOC_ERROR = -67,
	PARSE_ERROR = -87,
}	t_error;

typedef unsigned char	t_byte;

bool	ft_in(const char *str, char c);
int		ft_strlen(const char *str);
int		ft_parsef(t_data *data);
int		ft_printf(const char *str, ...);
void	my_memset(void *ptr, t_byte value, size_t n);
void	ft_write_buffer(t_data *data, char c);
void	ft_flush_buffer(t_data *data);
void	ft_putchar_buffer(char c, int precision, t_data *data);
void	ft_putstring_buffer(char *str, int precision, t_data *data);
void	ft_render_char(t_data *data, int c);
void	ft_render_string(t_data *data, char *str);

void	print_my_structure(char *ft_name, t_data *data);
void	print_width_precision(char *ft_name, t_data *data);

#endif
