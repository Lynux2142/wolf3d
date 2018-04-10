# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 16:09:56 by lguiller          #+#    #+#              #
#    Updated: 2018/04/10 10:06:55 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

OPE_SYS		= $(shell uname)
NAME		= wolf3d
SRCS1		= main.c stock.c free_funct.c check_map.c
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS1))
OBJS		= $(addprefix $(OBJS_DIR), $(SRCS1:.c=.o))
MINILIBX	= $(MLX_DIR)/libmlx.a
LIBFT		= libft/libft.a
SRCS_DIR	= srcs/
OBJS_DIR	= objs/
FLAGS		= -Wall -Wextra -Werror -O2

ifeq ($(OPE_SYS), Linux)
	INCLUDES	= -I includes -I libft -I minilibx -I /usr/include
	MLX_DIR		= minilibx_X11
	FRAMEWORK	= -L$(MLX_DIR) -lmlx -L/usr/lib -lxext -lX11 -lm
else
	INCLUDES	= -I includes -I libft -I minilibx -I /usr/include
	MLX_DIR		= minilibx
	FRAMEWORK	= -framework OpenGL -framework Appkit
endif

##################
##    COLORS    ##
##################

_BLACK		= "\033[30m"
_RED		= "\033[31m"
_GREEN		= "\033[32m"
_YELLOW		= "\033[33m"
_BLUE		= "\033[34m"
_VIOLET		= "\033[35m"
_CYAN		= "\033[36m"
_WHITE		= "\033[37m"
_END		= "\033[0m"
_CLEAR		= "\033[2K"
_HIDE_CURS	= "\033[?25l"
_SHOW_CURS	= "\033[?25h"
_UP			= "\033[A"
_CUT		= "\033[k"

##################
##   TARGETS    ##
##################

.PHONY: all title libft minilibx create_dir clean fclean re

all: title libft minilibx $(NAME)

create_dir:
	@./.check_dir.sh $(OBJS_DIR)

libft:
	@make -C libft

minilibx:
	@make -C $(MLX_DIR)

$(NAME): create_dir $(OBJS)
	@gcc $(FLAGS) $(OBJS) $(LIBFT) $(FRAMEWORK) $(MINILIBX) -o $(NAME)
	@echo $(_CLEAR)$(_YELLOW)"building - "$(_GREEN)"wolf3d"$(_END)
	@echo $(_GREEN)"Done."$(_END)$(_SHOW_CURS)


$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@gcc $(FLAGS) $(INCLUDES) -c $^ -o $@
	@printf $(_HIDE_CURS)$(_CLEAR)$(_YELLOW)"building - "$(_GREEN)
	@printf $@ | cut -c6- | cut -d'.' -f1
	@printf $(_END)
	@printf $(_UP)$(_CUT)

clean:
	@make -C libft clean
	@make -C $(MLX_DIR) clean
	@/bin/rm -f $(OBJS)

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean all

title:
	@echo $(_RED)
	@echo "==============================================================================="
	@echo
	@echo "       :::       :::  ::::::::  :::        ::::::::::     ::::::::  :::::::::  "
	@echo "      :+:       :+: :+:    :+: :+:        :+:           :+:    :+: :+:    :+:  "
	@echo "     +:+       +:+ +:+    +:+ +:+        +:+                  +:+ +:+    +:+   "
	@echo "    +#+  +:+  +#+ +#+    +:+ +#+        :#::+::#          +#++:  +#+    +:+    "
	@echo "   +#+ +#+#+ +#+ +#+    +#+ +#+        +#+                  +#+ +#+    +#+     "
	@echo "   #+#+# #+#+#  #+#    #+# #+#        #+#           #+#    #+# #+#    #+#      "
	@echo "   ###   ###    ########  ########## ###            ########  #########        "
	@echo
	@echo "==============================================================================="
	@echo $(_END)
