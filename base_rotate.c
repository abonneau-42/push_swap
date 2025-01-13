/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:18:04 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/13 19:06:07 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	if (stack->size_a < 2)
		return ;
	stack->top_a = stack->top_a->next;
}

void	rb(t_stack *stack)
{
	if (stack->size_b < 2)
		return ;
	stack->top_b = stack->top_b->next;
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}