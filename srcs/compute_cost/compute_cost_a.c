/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cost_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:16:58 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/31 03:18:36 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dir	count_cost_to_push_value(t_stack *stack, int value)
{
	t_list	*tmp;
	t_dir	cost;

	tmp = stack->top_a;
	cost.value = 0;
	cost.dir = 'n';
	while (cost.value < stack->size_a)
	{
		if (tmp->value == value)
			break ;
		tmp = tmp->next;
		cost.value++;
	}
	return (cost);
}

t_dir	count_cost_b_to_a(t_stack *stack, int value, int init_decrement)
{
	static int	decrement = -2147483648;
	t_list		*tmp;
	t_dir		cost;
	size_t		i;

	if (decrement == -2147483648)
		decrement = init_decrement;
	i = 0;
	tmp = stack->top_a;
	cost = (t_dir){.value = 0, .dir = 'p'};
	while (value < tmp->prev->value && decrement)
	{
		tmp = tmp->prev;
		i++;
		cost = (t_dir){.value = i, .dir = 'p'};
		decrement--;
		if (i == stack->size_a)
			break ;
	}
	return (cost);
}
