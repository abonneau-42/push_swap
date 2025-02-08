CC = cc
NAME = push_swap

BUILD_DIR = .build
INCLUDES_DIR = ./includes
HEADER = push_swap.h

CFLAGS = -Wall -Werror -Wextra -I $(INCLUDES_DIR)
INCLUDES_FILES = $(addprefix $(INCLUDES_DIR)/, $(HEADER))

SRCS_DIR = srcs
SRCS_FILES = 	utils/apply_moves.c \
				instructions/base_push.c \
				instructions/base_reverse_rotate.c \
				instructions/base_rotate.c \
				instructions/base_swap.c \
				compute_cost/compute_cost_a.c \
				compute_cost/compute_cost_b.c \
				initialiser/create_bidir_list.c \
				utils/ft_atoi.c \
				utils/ft_split.c \
				utils/lstadd_bidir_front.c \
				utils/math_utility.c \
				initialiser/push_swap_free.c \
				parser/push_swap_parser.c \
				resolver/push_swap_resolver_utils.c \
				resolver/push_swap_resolver.c \
				push_swap.c \
				instructions/reverse_swap.c \
				initialiser/stack_initialiser.c \
				utils/utility.c \
				resolver/push_swap_n.c \
				resolver/update_stack_limits.c \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES_FILES) Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re