# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 18:08:13 by vgejno            #+#    #+#              #
#    Updated: 2022/05/30 19:31:06 by vgejno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
SRCS	= $(wildcard *.c)
OBJC	= ${SRCS:.c=.o}
CC		= -gcc
FLAGS	= -Wall -Werror -Wall
RM		= rm -f

all: $(NAME)

$(NAME): ${OBJC}
		${CC} ${FLAGS} -o $@ $^

.c.o:
		${CC} ${FLAGC} -c $< -o ${<:.c=.o}

clean:
		${RM} ${OBJC}

fclean: clean
		${RM} ${NAME}

re: 	fclean all

.PHONY:
		clean fclean re

