/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:52:30 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/22 15:59:42 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_free(t_stack *stack, int *a_values)
{
	t_list	*tmp;

	tmp = stack->top_a;
	free(a_values);
	tmp = stack->top_a;
	while (stack->size_a)
	{
		tmp = tmp->next;
		free(stack->top_a);
		stack->top_a = tmp;
		stack->size_a--;
	}
	free(stack->a);
	free(stack->b);
}
