/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:47:50 by abonneau          #+#    #+#             */
/*   Updated: 2025/02/08 23:23:55 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_COST 17179869184
# define FACTOR_STACK_A 0.04

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef enum e_push_swap_error
{
	VALID_PARAMS = 0,
	MALOC_FAILURE = 1,
	ARGS_NOT_VALID = 2,
	ALREADY_SORTED = 3,
}	t_push_swap_error;

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_stack
{
	t_list	*top_a;
	t_list	*top_b;
	t_list	**a;
	t_list	**b;
	size_t	size_a;
	size_t	size_b;
	int		max_b;
	int		min_b;
	int		max_a;
	int		min_a;
}	t_stack;

typedef struct s_dir
{
	size_t	value;
	char	dir;
}	t_dir;

typedef struct s_move_data
{
	size_t	total_cost_tmp;
	t_dir	dirs[2];
}	t_move_data;

long	ft_atoi(const char *nptr);
int		create_bidir_list(t_list **a, int *a_values, size_t size_a);
void	lstadd_bidir_front(t_list **top, int value);
int		push_swap_parser(int argc, char **argv, int *a_values);
char	**ft_split(const char *s, char c);
int		free_char_tab(char **char_tab);
int		count_tab_size(char **tab);
int		push_swap_resolver(t_stack *stack);
long	ft_abs(int number);
int		ft_min(int first, int second);
int		ft_max(int first, int second);
void	push_swap_3(t_stack	*stack);
int		push_swap_n(t_stack *stack, size_t n);

int		is_number(char *str);
size_t	ft_strlen(const char *s);

t_dir	count_cost_to_push_value(t_stack *stack, int value);
t_dir	count_cost_b_to_max(t_stack *stack);
t_dir	count_cost_b_to_value(t_stack *stack, int value);
t_dir	count_cost_b(t_stack *stack, t_list *lst);
t_dir	count_cost_b_to_a(t_stack *stack, int value, int init_decrement);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

void	pa(t_stack *stack);
void	pb(t_stack *stack);

void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

void	sb_rb(t_stack *stack);
void	rb_sb(t_stack *stack);
void	sa_ra(t_stack *stack);
void	ra_sa(t_stack *stack);

void	push_swap_free(t_stack *stack, int *a_values);
int		stack_initialiser(t_stack *stack, int *a_values);
int		push_swap_pre_parser(t_stack *stack, int argc,
			char **argv, int **a_values);

void	apply_moves(t_stack *stack, size_t *value, void (*rotate)(t_stack *));
void	common_action_handler(t_stack *stack,
			size_t common_action, char direction);
void	apply_rotation(t_stack *stack, t_dir *dir,
			void (*rotate)(t_stack *), void (*reverse_rotate)(t_stack *));

t_dir	invert_rotation(t_dir cost, int stack_size);
t_dir	find_best_rotation(t_dir cost,
			size_t stack_size, char dir);

void	update_stack_limits_b(t_stack *stack);
void	handle_common_actions(t_stack *stack, t_dir *dirs);
void	update_best_move(t_move_data *move_data,
			t_bool is_double_rotation, t_dir cost_a, t_dir cost_b);
void	update_stack_limits_a(t_stack *stack);
#endif