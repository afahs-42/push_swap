# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afahs <afahs@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/22 23:33:50 by afahs             #+#    #+#              #
#    Updated: 2025/07/05 02:13:51 by afahs            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += -s

NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	push_swap.c \
		ops/push_ops.c \
		ops/rev_rot_ops.c \
		ops/rot_ops.c \
		ops/swap_ops.c \
		utils/check_utils.c \
		utils/move_utils.c \
		utils/position_utils.c \
		utils/random_utils.c \
		utils/sort_utils.c \
		utils/stack_utils.c \
		utils/split_utils.c \
    	utils/b_utils.c \
	   
SRC_B = bonus/checker.c \
		ops/push_ops.c \
       	ops/rev_rot_ops.c \
       	ops/rot_ops.c \
       	ops/swap_ops.c \
	   	gnl/gnl.c\
	   	gnl/gnl_utils.c\
       	utils/check_utils.c \
		utils/move_utils.c \
		utils/position_utils.c \
		utils/random_utils.c \
		utils/sort_utils.c \
		utils/stack_utils.c \
		utils/split_utils.c \
    	utils/b_utils.c \

OBJS = $(SRCS:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(BONUS) : $(OBJ_B)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJ_B)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
       
all: $(NAME)

bonus : $(BONUS)

clean:
	rm -f $(OBJS) $(OBJ_B)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
