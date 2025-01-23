# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 13:06:53 by abonneau          #+#    #+#              #
#    Updated: 2025/01/23 19:14:58 by abonneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -I . -g3
DDIR = ./.build/
HEADER = push_swap.h
SRCS = 			apply_moves.c \
				base_push.c \
				base_reverse_rotate.c \
				base_rotate.c \
				base_swap.c \
				compute_cost_a.c \
				compute_cost_b.c \
				create_bidir_list.c \
				ft_atoi.c \
				ft_split.c \
				lstadd_bidir_front.c \
				math_utility.c \
				push_swap_free.c \
				push_swap_parser.c \
				push_swap_resolver_utils.c \
				push_swap_resolver.c \
				push_swap.c \
				reverse_swap.c \
				stack_initialiser.c \
				utility.c \
				push_swap_5.c \

OBJS = $(addprefix $(DDIR),$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(DDIR)%.o: %.c $(HEADER) Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(DDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
