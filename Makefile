# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 10:45:17 by lazanett          #+#    #+#              #
#    Updated: 2023/04/21 10:17:45 by lazanett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = cc

RM = bin/rm -f

CFLAGS = -Wall -Wextra -Werror -g3

PATH_LIB = libft

SRCS =  parsing.c \
		main.c \
		ope.c \
		ope2.c \
		ope3.c \
		ope4.c \
		utils.c \
		small_sort.c \
		index.c \
		utils_list.c \
		algo.c \
		pos.c \
		cost.c \
		move.c \
		
		
OBJS	= ${SRCS:.c=.o}

LIBFT = $(PATH_LIB)/libft.a

$(LIBFT) :
	@make -s -C $(PATH_LIB)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	
	
all : ${LIBFT} ${NAME}

clean :
	make -C $(PATH_LIB) clean
	/bin/rm -f ${OBJS}

fclean : clean
	make -C $(PATH_LIB) fclean
	/bin/rm -f ${NAME}

re : fclean all

.o .c :
	$(CC) $(CFLAGS) -c $< -o ${<:.c = .o}

.PHONY :
	all re clean fclean 
