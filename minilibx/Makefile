# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:15:29 by lguiller          #+#    #+#              #
#    Updated: 2018/03/28 16:37:04 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libmlx.a
SRC		= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m \
		  mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1	= $(SRC:.c=.o)
OBJ		= $(OBJ1:.m=.o)
FLAGS	= -O2

.PHONY: all compil clean re

all: $(NAME)

$(NAME): compil
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

compil:
	@gcc $(FLAGS) -c $(SRC)

clean:
	@/bin/rm -f $(OBJ) $(NAME)

re: clean all
