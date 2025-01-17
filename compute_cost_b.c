/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cost_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:11:58 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/17 19:21:13 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dir	count_cost_b_to_value(t_stack *stack, int value)
{
	t_list 	*tmp;
	int 	i;
	int 	nearest_value;
	t_dir	cost;

	tmp = stack->top_b;
	i = 0;
	nearest_value = stack->top_b->value;
	cost.dir = 'n';
	cost.value = stack->size_b;
	while (i < stack->size_b)
	{
		if (tmp->value < value && abs(value - tmp->value) < abs(value - nearest_value))
		{
			nearest_value = tmp->value;
			cost.value = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (cost.value > stack->size_b / 2)
	{
		cost.value = stack->size_b - cost.value;
		cost.dir = 'p';
	}
	return (cost);
}





t_dir	count_cost_b_to_max(t_stack *stack)
{
	t_list 	*tmp;
	t_dir 	cost;

	tmp = stack->top_b;
	cost.value = 0;
	cost.dir = 'n';
	while (cost.value < stack->size_b)
	{
		if (tmp->value == stack->max_b)
			break;
		tmp = tmp->next;
		cost.value++;
	}
	if (cost.value > stack->size_b / 2)
	{
		cost.value = stack->size_b - cost.value;
		cost.dir = 'p';
	}
	return (cost);
}

t_dir	count_cost_b(t_stack *stack, t_list *lst)
{
	t_dir cost;

	if (lst->value > stack->min_b && lst->value < stack->max_b)
	{
		cost = count_cost_b_to_value(stack, lst->value);
	}
	else
	{
		cost = count_cost_b_to_max(stack);
		if (lst->value < stack->min_b)
			stack->min_b = lst->value;
		else if (lst->value > stack->max_b)
			stack->max_b = lst->value;
	}
	return (cost);
}