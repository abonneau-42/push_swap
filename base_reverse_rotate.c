/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:18:07 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/20 20:06:39 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	if (stack->size_a < 2)
		return ;
	stack->top_a = stack->top_a->prev;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	if (stack->size_b < 2)
		return ;
	stack->top_b = stack->top_b->prev;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
{
	if (stack->size_a < 2)
		return ;
	stack->top_a = stack->top_a->prev;
	if (stack->size_b < 2)
		return ;
	stack->top_b = stack->top_b->prev;
	write(1, "rrr\n", 4);
}