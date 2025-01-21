/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cost_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:16:58 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/21 19:15:47 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dir count_cost_to_push_value(t_stack *stack, int value)
{
	t_list 	*tmp;
	t_dir 	cost;

	tmp = stack->top_a;
	cost.value = 0;
	cost.dir = 'n';
	while (cost.value < stack->size_a)
	{
		if (tmp->value == value)
			break;
		tmp = tmp->next;
		cost.value++;
	}
	return (cost);
}