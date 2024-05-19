# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_test.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 14:29:07 by zslowian          #+#    #+#              #
#    Updated: 2024/05/19 16:48:13 by zslowian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cp ../ft_printf.h ./ft_printf.h
cp ../ft_printf.c ./ft_printf.c
cp ../ft_buffer.c ./ft_buffer.c
cp ../ft_parsef.c ./ft_parsef.c
cp ../ft_printf_utils.c ./ft_printf_utils.c
cp ../ft_render_char.c ./ft_render_char.c
cp ../ft_render_string.c ./ft_render_string.c

cc -Wall -Wextra -Werror *.c -o tests.out

./tests.out

rm ./tests.out
rm ./ft_printf.h
rm ./ft_printf.c
rm ./ft_buffer.c
rm ./ft_parsef.c
rm ./ft_printf_utils.c
rm ./ft_render_char.c
rm ./ft_render_string.c