# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afahs <afahs@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/22 23:33:50 by afahs             #+#    #+#              #
#    Updated: 2025/06/23 06:19:41 by afahs            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror  -lbsd

SRCS = push_swap.c \
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

OBJS = $(SRCS:.c=.o)

all: $(NAME)  clean

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
