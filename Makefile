# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 21:25:28 by Loui :)           #+#    #+#              #
#    Updated: 2021/11/01 21:26:03 by Loui :)          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_hexa_len.c ft_printf.c ft_putchar_printf.c ft_putstr_printf.c \
ft_write_d_i.c ft_write_p.c ft_write_u.c ft_write_x.c ft_write_upperx.c

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = gcc
HEADERS = ft_printf.h
OBJ = ${SRC:.c=.o}

$(NAME): $(OBJ) 
	cd libft && $(MAKE) all
	ar -rcs $(NAME) $(OBJ) $@ $^

clean:
	cd libft && $(MAKE) clean
	rm -f $(OBJ)

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME)
	
all: $(NAME)

re: fclean all

.PHONY: all clean fclean re