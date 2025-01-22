/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_resolver_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:01:13 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/22 16:40:40 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dir	invert_rotation(t_stack *stack, t_dir cost, int stack_size)
{
	cost.value = stack_size - cost.value;
	cost.dir = 'p';
	return (cost);
}

t_dir	find_best_rotation(t_stack *stack, t_dir cost, int stack_size, char dir)
{
	if (cost.value > stack_size / 2)
	{
		cost.value = stack_size - cost.value;
		cost.dir = dir;
	}
	return (cost);
}

void	update_stack_limits(t_stack *stack)
{
	t_list	*tmp;
	int		i;

	tmp = stack->top_b;
	i = 0;
	stack->max_b = stack->top_b->value;
	stack->min_b = stack->top_b->value;
	while (i < stack->size_b)
	{
		if (tmp->value > stack->max_b)
			stack->max_b = tmp->value;
		if (tmp->value < stack->min_b)
			stack->min_b = tmp->value;
		tmp = tmp->next;
		i++;
	}
}

void	handle_common_actions(t_stack *stack, t_dir *dirs)
{
	long	common_action;

	common_action = 0;
	if (dirs[0].dir == dirs[1].dir)
	{
		common_action = ft_min(dirs[0].value, dirs[1].value);
		common_action_handler(stack, common_action, dirs[0].dir);
		dirs[0].value -= common_action;
		dirs[1].value -= common_action;
	}
}

void	update_best_move(t_move_data *move_data, t_bool is_double_rotation,
	t_dir cost_a, t_dir cost_b)
{
	long	total_cost;

	total_cost = MAX_COST;
	if (is_double_rotation)
		total_cost = ft_max(cost_a.value, cost_b.value);
	else
		total_cost = cost_a.value + cost_b.value;
	if (total_cost < move_data->total_cost_tmp)
	{
		move_data->total_cost_tmp = total_cost;
		move_data->dirs[0] = cost_a;
		move_data->dirs[1] = cost_b;
	}
}
