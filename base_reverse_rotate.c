/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:18:07 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/13 19:06:46 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	if (stack->size_a < 2)
		return ;
	stack->top_a = stack->top_a->prev;
}

void	rrb(t_stack *stack)
{
	if (stack->size_b < 2)
		return ;
	stack->top_b = stack->top_b->prev;
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}