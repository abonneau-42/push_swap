/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_resolver.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:38:09 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/22 15:45:56 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_3(t_stack	*stack)
{
	int	values[3];

	values[0] = stack->top_a->value;
	values[1] = stack->top_a->next->value;
	values[2] = stack->top_a->next->next->value;
	if (values[0] > values[1] && values[1] > values[2])
		ra_sa(stack);
	else if (values[0] > values[2] && values[2] > values[1])
		ra(stack);
	else if (values[1] > values[0] && values[0] > values[2])
		rra(stack);
	else if (values[1] > values[2] && values[2] > values[0])
		sa_ra(stack);
	else if (values[2] > values[0] && values[0] > values[1])
		sa(stack);
}

void	compute_best_move(t_stack *stack, t_list *tmp, t_move_data *move_data)
{
	t_dir	cost_a;
	t_dir	cost_b;

	cost_a = count_cost_to_push_value(stack, tmp->value);
	cost_b = count_cost_b(stack, tmp);
	update_best_move(move_data, true, cost_a, cost_b);
	cost_a = invert_rotation(stack, cost_a, stack->size_a);
	cost_b = invert_rotation(stack, cost_b, stack->size_b);
	update_best_move(move_data, true, cost_a, cost_b);
	cost_a = find_best_rotation(stack, cost_a, stack->size_a, 'n');
	cost_b = find_best_rotation(stack, cost_b, stack->size_b, 'n');
	update_best_move(move_data, false, cost_a, cost_b);
}

void	findbest_move(t_stack *stack, int size, t_move_data *move_data)
{
	t_list	*tmp;
	t_dir	cost_a;
	t_dir	cost_b;

	tmp = stack->top_a;
	move_data->total_cost_tmp = (stack->size_a + stack->size_b) * 4;
	move_data->dirs[0].value = (stack->size_a + stack->size_b) * 2;
	move_data->dirs[1].value = (stack->size_a + stack->size_b) * 2;
	while (size--)
	{
		compute_best_move(stack, tmp, move_data);
		tmp = tmp->next;
	}
}

int	push_swap_resolver_complex(t_stack *stack)
{
	t_dir		max;
	t_move_data	move_data;

	pb(stack);
	pb(stack);
	while (stack->size_a)
	{
		update_stack_limits(stack);
		findbest_move(stack, stack->size_a, &move_data);
		handle_common_actions(stack, move_data.dirs);
		apply_rotation(stack, &move_data.dirs[0], ra, rra);
		apply_rotation(stack, &move_data.dirs[1], rb, rrb);
		pb(stack);
	}
	update_stack_limits(stack);
	max = find_best_rotation(stack,
			count_cost_b_to_max(stack), stack->size_b, 'p');
	apply_rotation(stack, &max, rb, rrb);
	while (stack->size_b)
		pa(stack);
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
