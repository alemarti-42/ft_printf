# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alemarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 20:30:12 by alemarti          #+#    #+#              #
#    Updated: 2021/08/11 16:15:13 by alemarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c		\
			  printf_utils.c	\
			  parse_utils.c		\
			  format_utils.c	\
			  string_utils.c	\
			  char_utils.c		\
			  decimal_utils.c	\
			  hexa_utils.c		\
			  pointer_utils.c

OBJS		= ${SRCS:.c=.o}
LIBFT		= libft.a

NAME		= libftprintf.a

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra

all:		${NAME}

bonus:		all

${NAME}:	${OBJS} ${LIBFT}
			ar rc ${NAME} ${OBJS} ${LIBFT}
			ranlib ${NAME}

${LIBFT}:
			make -C ./libft/ all
			mv libft/${LIBFT} .

clean:
			@${RM} ${OBJS} ${LIBFT} 
			make -C ./libft/ clean


fclean:		clean
			@${RM} ${NAME}
			make -C ./libft/ fclean

re:			fclean all

PHONY:		all clean fclean re
