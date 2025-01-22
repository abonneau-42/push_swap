/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_resolver_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:01:13 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/22 15:02:50 by abonneau         ###   ########.fr       */
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
	int	common_action;

	common_action = 0;
	if (dirs[0].dir == dirs[1].dir)
	{
		common_action = ft_min(dirs[0].value, dirs[1].value);
		common_action_handler(stack, common_action, dirs[0].dir);
		dirs[0].value -= common_action;
		dirs[1].value -= common_action;
	}
}