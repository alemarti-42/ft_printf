# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alemarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 20:30:12 by alemarti          #+#    #+#              #
#    Updated: 2021/07/06 19:53:38 by alemarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c

LIB_SRCS	= ft_memset.c	 	\
			  ft_bzero.c 		\
			  ft_memcpy.c 		\
			  ft_memccpy.c 		\
			  ft_memmove.c 		\
			  ft_memchr.c 		\
			  ft_memcmp.c  		\
			  ft_strlen.c  		\
			  ft_strlcpy.c  	\
			  ft_strlcat.c  	\
			  ft_strchr.c  		\
			  ft_strrchr.c  	\
			  ft_strnstr.c  	\
			  ft_strncmp.c  	\
			  ft_atoi.c  		\
			  ft_isalpha.c  	\
			  ft_isdigit.c  	\
			  ft_isalnum.c  	\
			  ft_isascii.c  	\
			  ft_isprint.c  	\
			  ft_toupper.c  	\
			  ft_tolower.c  	\
			  ft_calloc.c 		\
			  ft_strdup.c 		\
			  ft_substr.c 		\
			  ft_strjoin.c		\
			  ft_strtrim.c		\
			  ft_split.c		\
			  ft_itoa.c			\
			  ft_strmapi.c		\
			  ft_putchar_fd.c	\
			  ft_putstr_fd.c	\
			  ft_putendl_fd.c	\
			  ft_putnbr_fd.c	\
			  ft_lstnew.c		\
			  ft_lstadd_front.c	\
			  ft_lstsize.c		\
			  ft_lstlast.c		\
			  ft_lstadd_back.c	\
			  ft_lstdelone.c	\
			  ft_lstclear.c		\
			  ft_lstiter.c		\
			  ft_lstmap.c

OBJS		= ${SRCS:.c=.o}
LIB_OBJS	= ${LIB_SRCS:.c=.o}

NAME		= ft_printf.a
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra

all:		${NAME}

${NAME}:	${OBJS}
			ar rc	${NAME} ${OBJS}

libft:		${LIB_OBJS}

${LIB_OBJS}:
			make -C ./libft/ ft_printf

clean:
			@${RM} ${OBJS} ${LIB_OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re

test_builtin:	
			${CC} ${CFLAGS} tests/main_builtin.c -o test.out
			./test.out
			@rm test.out
