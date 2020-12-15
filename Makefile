# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 15:27:20 by cel-otma          #+#    #+#              #
#    Updated: 2019/12/21 23:47:03 by cel-otma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = fractol

CC = gcc

SRC = main.c\
		draw.c\
		control.c\
		init.c\
		fract_calcul.c

OBJS = $(SRC:.c=.o)

MLX = /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L $(MLX) -o $(NAME)

clean :
	@make clean -C libft
	@rm -rf $(OBJS)

fclean : clean
	@make fclean -C libft
	@rm -rf $(NAME)

re : fclean all
