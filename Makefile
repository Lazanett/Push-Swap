# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 10:45:17 by lazanett          #+#    #+#              #
#    Updated: 2023/05/15 13:16:45 by lazanett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

cc = cc

CFLAGS = -Wall -Werror -Wextra -g3

PATH_LIB = libft

SRC = src/parsing.c \
		src/main.c \
		src/ope.c \
		src/ope2.c \
		src/ope3.c \
		src/ope4.c \
		src/utils.c \
		src/small_sort.c \
		src/index.c \
		src/utils_list.c \
		src/utils_struc.c \
		src/algo.c \
		src/pos.c \
		src/cost.c \
		src/move.c \
		src/free.c \

SRC_BONUS = src/ope.c \
			src/ope2.c \
			src/ope3.c \
			src/ope4.c \
			src/utils.c \
			src/small_sort.c \
			src/index.c \
			src/utils_list.c \
			src/utils_struc.c \
			src/algo.c \
			src/pos.c \
			src/cost.c \
			src/move.c \
			src/free.c \
			src/parsing.c \
			bonus/main_bonus.c \
			bonus/operation1.c \
			bonus/operation2.c \


LIB = $(PATH_LIB)/libft.a

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(LIB) $(NAME)

bonus: $(LIB) $(NAME_BONUS)

$(NAME) : $(OBJ) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo "\n Compilation OK\n"

$(NAME_BONUS) : $(OBJ_BONUS) 
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIB)
	@echo "\n Compilation Bonus OK\n"

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIB) :
	@make -s -C $(PATH_LIB)

clean :
	@make -s -C $(PATH_LIB) clean
	@ rm -f $(OBJ) 
	@ rm -f $(OBJ_BONUS)

fclean : clean
	@make -s -C $(PATH_LIB) fclean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re : fclean all
	
.PHONY : all clean fclean re
