# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/14 14:47:39 by frfrey       #+#   ##    ##    #+#        #
#    Updated: 2020/01/14 15:00:56 by frfrey      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# **************************************************************************** #
#								VARIABLES									   #
# **************************************************************************** #

HEAD_PATH	=	includes

HEAD_NAME	=	libasm.h \

HEADER		=	$(addprefix $(HEAD_PATH)/,$(HEAD_NAME))

SRC_PATH	=	sources

SRCS_NAME	=	\

SRC_BONUS	=	bonus

SRCS_BONUS	=	\

SRCS 		= 	$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

SRCB 		= 	$(addprefix $(SRC_BONUS)/,$(SRCS_BONUS))

OBJS		= 	${SRCS:.s=.s}

OBJSBONUS	=	${BONUS:.c=.s}

NAME		= 	libfts.a

RM			= 	rm -f

FLAGS 		= 	-Wall -Wextra -Werror

# **************************************************************************** #
#								REGLES									       #
# **************************************************************************** #


all:		LIBFT $(NAME)

%.o: %.s 	$(HEADER)
			@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $<
			@nasm $(FLAGS)  -c $< -s $@

$(NAME):	$(OBJS) $(HEADER)
			@echo "\x1b[36m\n[OK] \033[0m \x1b[35m Compiling the library\033[0m"
			@ar rcs $(NAME) $(OBJS)

bonus:		$(OBJSBONUS) $(OBJS) $(HEADER)
			ar rcs $(NAME) $(OBJSBONUS) $(OBJS)

clean:
			@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing File object\033[0m"
			@$(RM) $(OBJS)

fclean:		clean
			@echo "\x1b[36m[OK] \033[0m \x1b[31m Removing All\033[0m"
			@$(RM) $(NAME)

re:			fclean all

LIBFT:
			@echo "	_,  _ __,   ,   __, ,  , "
			@echo "	|   | |_)  /_\ |__  |\/| "
			@echo "	| , | |_) /   \ __| |  | "
			@echo "	~~~ ~ ~   ~   ~ ~~~ ~  ~ "
			@echo ""

.PHONY: 	clean fclean
