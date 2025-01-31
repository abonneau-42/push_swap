/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stack_limits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 03:20:10 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/31 03:21:43 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_stack_limits_b(t_stack *stack)
{
	t_list	*tmp;
	size_t	i;

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

void	update_stack_limits_a(t_stack *stack)
{
	t_list	*tmp;
	size_t	i;

	tmp = stack->top_a;
	i = 0;
	stack->max_a = stack->top_a->value;
	stack->min_a = stack->top_a->value;
	while (i < stack->size_a)
	{
		if (tmp->value > stack->max_a)
			stack->max_a = tmp->value;
		if (tmp->value < stack->min_a)
			stack->min_a = tmp->value;
		tmp = tmp->next;
		i++;
	}
}
