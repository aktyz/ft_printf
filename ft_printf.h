/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
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
# define LOW_SYMBOLS "0123456789abcdef"
# define UP_SYMBOLS "0123456789ABCDEF"

//#include "libft.h" TODO: work it out
# include <limits.h> // INT_MAX, INT_MIN
# include <stdarg.h> // variadic macros
# include <stdbool.h> // bool
# include <stdlib.h> // malloc free
# include <unistd.h> // write
# include <stdio.h> // TODO: replace with ft_printf once all test pass correctly

/**
 * Enum structure to choose the base conversion of a number
 * to print
 *
 */
typedef enum e_base
{
	BASE_2 = 2,
	BASE_8 = 8,
	BASE_10 = 10,
	BASE_16 = 16,
}	t_base;

/**
 * Union structure to hold the value of a number to print
 * regardless of conversion
 *
 */
typedef union u_value
{
	long			l_value;
	unsigned long	ul_value;
}	t_value;

/**
 * Structure to hold all the possible formatting flags
 * passed to the ft_printf function in the format string
 *
 */
typedef struct s_format
{
	/**
	 * left-adjusted
	 */
	bool	minus;
	/**
	 * number sign (+ or -) before the number for signed conversion
	 */
	bool	plus;
	/**
	 * blank should be left before a positive number (or empty string)
	 * produced by a signed conversion
	 */
	bool	space;
	/**
	 * The value should be converted to an "alternative form"
	*/
	bool	hash;
	/**
	 * The value should be zero padded
	*/
	bool	zero_pad;
	/**
	 * Precision flag to know if we should look at the precision value or not
	*/
	bool	is_precision;
	// cspdiuxX% format specifiers
	char	specifier;
	t_base	base;
	bool	upper_case;
	// width and precision values
	int		width;
	int		precision;
	int		nbr_padding_spaces;
	int		nbr_padding_zeros;
	bool	is_number_negative;
	bool	is_number_negated;
	bool	nil;
	// lenght of the number string to be printed out
	int		nbr_length;
}	t_format;

/**
 * Structure holding all the necessary data used in this library
 * to print the string correctly
 *
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
	// Temporary buffer for handling number printing
	char		temp[64];
	// Value to print in the on chosen fd
	t_value		value_to_print;
}	t_data;

/**
 * Enum structure to hold possible errors that can be thrown at
 * different level of the ft_printf function
 *
*/
typedef enum e_error
{
	OK = 0,
	MALLOC_ERROR = -67,
	PARSE_ERROR = -87,
}	t_error;

/**
 * Shorthand for the unsigned char type
 *
 */
typedef unsigned char	t_byte;

bool	ft_in(const char *str, char c);
int		ft_strlen(const char *str);
int		ft_parsef(t_data *data);
int		ft_printf(const char *str, ...);
void	my_memset(void *ptr, t_byte value, size_t n);
void	ft_set_padding_zeros(t_data *data);
void	ft_negate_number(t_data *data, t_value int_value);
void	ft_write_buffer(t_data *data, char c);
void	ft_flush_buffer(t_data *data);
void	ft_putchar_buffer(char c, int precision, t_data *data);
void	ft_putstring_buffer(char *str, int precision, t_data *data);
void	ft_render_char(t_data *data, int c);
void	ft_render_string(t_data *data, char *str);
void	ft_render_number(t_data *data);
void	ft_itoa_buffer(t_data *data, t_value int_value);

void	print_my_structure(char *ft_name, t_data *data);
void	print_width_precision(char *ft_name, t_data *data);

#endif
