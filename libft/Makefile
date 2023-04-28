# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 12:03:41 by lazanett          #+#    #+#              #
#    Updated: 2023/01/28 17:41:01 by lazanett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

CC = cc

RM = bin/rm -f

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalnum.c \
       ft_isalpha.c \
       ft_isascii.c \
       ft_isdigit.c \
       ft_isprint.c \
       ft_toupper.c \
       ft_tolower.c \
       ft_strncmp.c \
       ft_memcmp.c \
       ft_atoi.c \
       ft_strlcat.c \
       ft_strlcpy.c \
       ft_strlen.c \
       ft_calloc.c \
       ft_memset.c\
       ft_bzero.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_memchr.c \
       ft_strnstr.c \
       ft_strchr.c \
       ft_strrchr.c \
       ft_strdup.c \
       ft_strjoin.c \
       ft_strjoin1.c \
       ft_substr.c \
       ft_strtrim.c \
       ft_strmapi.c \
       ft_split.c \
       ft_itoa.c \
       ft_striteri.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \
       ft_lstnew.c\
       ft_lstadd_front.c\
       ft_lstsize.c\
       ft_lstlast.c\
       ft_lstadd_back.c\
       ft_lstdelone.c\
       ft_lstclear.c\
       ft_lstiter.c\
       ft_lstmap.c\
       ft_get_next_line.c\
       ft_print_nbr.c \
       ft_hexa_size.c\
       ft_put_hexa.c\
       ft_print_hexa.c\
       ft_printf.c\
       ft_put_u.c\
       ft_putchar.c\
       ft_putstr.c\
       ft_void_hexa.c\

OBJS	= ${SRCS:.c=.o}

$(NAME) : ${OBJS}
	ar rc ${NAME} ${OBJS}

all:	${NAME}

clean :
	/bin/rm -f ${OBJS}

fclean : clean
	/bin/rm -f ${NAME}

re : fclean all

.o .c:
	cc -Wall -Werror -Wextra -c $< -o ${<:.c = .o}

.PHONY:
	all re clean fclean 