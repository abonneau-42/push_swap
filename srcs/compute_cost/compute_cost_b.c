/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cost_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:11:58 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/22 17:03:34 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_position(t_stack *stack, int value,
	int *nearest_min_value, int *nearest_max_value)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	tmp = stack->top_b;
	*nearest_min_value = stack->min_b;
	*nearest_max_value = stack->max_b;
	while (i < stack->size_b)
	{
		if (tmp->value < value
			&& abs(value - tmp->value) < abs(value - *nearest_min_value))
			*nearest_min_value = tmp->value;
		if (tmp->value > value
			&& abs(tmp->value - value) < abs(*nearest_max_value - value))
			*nearest_max_value = tmp->value;
		tmp = tmp->next;
		i++;
	}
}

t_dir	count_cost_b_to_value(t_stack *stack, int value)
{
	t_list	*tmp;
	int		nearest_min_value;
	int		nearest_max_value;
	t_dir	cost;
	int		i;

	i = 0;
	tmp = stack->top_b;
	find_position(stack, value, &nearest_min_value, &nearest_max_value);
	while (nearest_min_value != tmp->value)
	{
		tmp = tmp->next;
		i++;
	}
	cost.dir = 'n';
	cost.value = i;
	return (cost);
}

t_dir	count_cost_b_to_max(t_stack *stack)
{
	t_list	*tmp;
	t_dir	cost;

	tmp = stack->top_b;
	cost.value = 0;
	cost.dir = 'n';
	while (cost.value < stack->size_b)
	{
		if (tmp->value == stack->max_b)
			break ;
		tmp = tmp->next;
		cost.value++;
	}
	return (cost);
}

t_dir	count_cost_b(t_stack *stack, t_list *lst)
{
	t_dir	cost;

	if (lst->value > stack->min_b && lst->value < stack->max_b)
		cost = count_cost_b_to_value(stack, lst->value);
	else
		cost = count_cost_b_to_max(stack);
	return (cost);
}
