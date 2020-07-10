# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psabreto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/19 17:23:48 by psabreto          #+#    #+#              #
#    Updated: 2020/07/10 16:39:49 by psabreto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJECTS = ft_printf.o x_littel.o x_big.o p_function.o u_function.o ft_printf_part2.o put_0_or_32.o \
put_dif.o put_dif_xx.o put_0_or_32_s.o put_dif_s.o put_0_or_32_p.o put_dif_p.o

OBJ_LIBFT = a_ft_atoi.o a_ft_isascii.o a_ft_isdigit.o a_ft_putnbr_fd.o a_ft_putchar_fd.o \
a_ft_putstr_fd.o a_ft_strlen.o a_ft_isalpha.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJ_LIBFT)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	clang -c $(CFLAGS) -I./ -o $@ $<

clean:
	rm -f $(OBJECTS) $(OBJ_LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	gcc -shared -o libftprintf.so $(OBJECTS) $(OBJ_LIBFT)

.PHONY: all clean fclean re
