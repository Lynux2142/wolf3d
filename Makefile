# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 12:18:12 by lguiller          #+#    #+#              #
#    Updated: 2018/03/28 17:12:22 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

NAME		= wolf3d
SRCS1		= main.c test.c
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS1))
OBJS		= $(addprefix $(OBJS_DIR), $(SRCS1:.c=.o))
SRCS_DIR	= srcs/
OBJS_DIR	= objs/
INC			= includes/
LIBFT		= libft/libft.a
MINILIBX	= minilibx/libmlx.a
FLAGS		= -Wall -Wextra -Werror
FRAMEWORK	= -framework OpenGL -framework Appkit

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

.PHONY: all title libft minilibx clean fclean re

all: title libft minilibx $(NAME)

libft:
	@make -C libft

minilibx:
	@make -C minilibx

$(NAME): $(OBJS)
	@gcc $(FLAGS) $(FRAMEWORK) $(MINILIBX) $(OBJS) $(LIBFT) -o $(NAME)
	@echo $(_CLEAR)$(_YELLOW)"building - "$(_GREEN)"wolf3d"$(_END)
	@echo $(_GREEN)"Done."$(_END)$(_SHOW_CURS)


$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@gcc $(FLAGS) -I $(INC) -c $^ -o $@
	@printf $(_HIDE_CURS)$(_CLEAR)$(_YELLOW)"building - "$(_GREEN)
	@printf $@ | cut -c6- | cut -d'.' -f1
	@printf $(_UP)$(_CUT)$(_END)

clean:
	@make -C libft clean
	@make -C minilibx clean
	@/bin/rm -f $(OBJS)

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean all

title:
	@echo $(_RED)
	@echo "==========================================================================="
	@echo
	@echo "       :::       :::  ::::::::  :::        :::::::::: ::::::::  :::::::::  "
	@echo "      :+:       :+: :+:    :+: :+:        :+:       :+:    :+: :+:    :+:  "
	@echo "     +:+       +:+ +:+    +:+ +:+        +:+              +:+ +:+    +:+   "
	@echo "    +#+  +:+  +#+ +#+    +:+ +#+        :#::+::#      +#++:  +#+    +:+    "
	@echo "   +#+ +#+#+ +#+ +#+    +#+ +#+        +#+              +#+ +#+    +#+     "
	@echo "   #+#+# #+#+#  #+#    #+# #+#        #+#       #+#    #+# #+#    #+#      "
	@echo "   ###   ###    ########  ########## ###        ########  #########        "
	@echo
	@echo "==========================================================================="
	@echo $(_END)
