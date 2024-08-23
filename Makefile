NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_buffer.c ft_parsef.c ft_render_number_utils.c \
		ft_printf_utils.c ft_printf.c ft_render_char.c \
		ft_render_number.c ft_render_string.c

OBJS = $(SRCS:.c=.o)

HEADER = ./

%.o : %.c
	@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

$(NAME): $(OBJS)
	@ar cr $(NAME) $(OBJS)
	@echo "libftprintf.a created"

bonus: $(OBJS)
	@ar cr $(NAME) $(OBJS)
	@echo "libftprintf.a bonus created"

all: $(NAME)

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -f $(OBJS)

tests:
	@(cd .tests; bash .tests.sh)

re: fclean all

.PHONY: all clean fclean re tests
