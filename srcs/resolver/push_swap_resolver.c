/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_resolver.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:38:09 by abonneau          #+#    #+#             */
/*   Updated: 2025/02/08 23:04:54 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compute_best_move(t_stack *stack, t_list *tmp, t_move_data *move_data)
{
	t_dir	cost_a;
	t_dir	cost_b;

	cost_a = count_cost_to_push_value(stack, tmp->value);
	cost_b = count_cost_b(stack, tmp);
	update_best_move(move_data, TRUE, cost_a, cost_b);
	cost_a = invert_rotation(cost_a, stack->size_a);
	cost_b = invert_rotation(cost_b, stack->size_b);
	update_best_move(move_data, TRUE, cost_a, cost_b);
	cost_a = find_best_rotation(cost_a, stack->size_a, 'n');
	cost_b = find_best_rotation(cost_b, stack->size_b, 'n');
	update_best_move(move_data, FALSE, cost_a, cost_b);
}

void	findbest_move(t_stack *stack, int size, t_move_data *move_data)
{
	t_list	*tmp;

	tmp = stack->top_a;
	move_data->total_cost_tmp = MAX_COST;
	move_data->dirs[0].value = MAX_COST;
	move_data->dirs[1].value = MAX_COST;
	while (size--)
	{
		compute_best_move(stack, tmp, move_data);
		tmp = tmp->next;
	}
}

void	push_swap_resolver_complex_pa(t_stack *stack, int i)
{
	t_dir		max;
	t_dir		cost;

	update_stack_limits_b(stack);
	max = find_best_rotation(count_cost_b_to_max(stack), stack->size_b, 'p');
	apply_rotation(stack, &max, rb, rrb);
	push_swap_n(stack, i);
	update_stack_limits_a(stack);
	while (stack->size_b)
	{
		cost = count_cost_b_to_a(stack, stack->top_b->value, i);
		apply_rotation(stack, &cost, ra, rra);
		pa(stack);
		update_stack_limits_a(stack);
	}
	while (stack->top_a->value > stack->top_a->prev->value)
		rra(stack);
}

void	push_swap_resolver_complex(t_stack *stack)
{
	t_move_data	move_data;
	int			i;

	if (stack->size_a < 100)
		i = 3;
	else
		i = stack->size_a * FACTOR_STACK_A;
	if (stack->size_a > 4)
		pb(stack);
	pb(stack);
	while (stack->size_a - i)
	{
		update_stack_limits_b(stack);
		findbest_move(stack, stack->size_a, &move_data);
		handle_common_actions(stack, move_data.dirs);
		apply_rotation(stack, &move_data.dirs[0], ra, rra);
		apply_rotation(stack, &move_data.dirs[1], rb, rrb);
		pb(stack);
	}
	push_swap_resolver_complex_pa(stack, i);
}

int	push_swap_resolver(t_stack *stack)
{
	if (stack->size_a == 2)
	{
		if (stack->top_a->value > stack->top_a->next->value)
			sa(stack);
		else
			return (1);
	}
	else if (stack->size_a == 3)
		push_swap_3(stack);
	else
		push_swap_resolver_complex(stack);
	return (1);
}
