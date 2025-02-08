/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:18:04 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/22 12:55:40 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	if (stack->size_a < 2)
		return ;
	stack->top_a = stack->top_a->next;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	if (stack->size_b < 2)
		return ;
	stack->top_b = stack->top_b->next;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	if (stack->size_a < 2)
		return ;
	stack->top_a = stack->top_a->next;
	if (stack->size_b < 2)
		return ;
	stack->top_b = stack->top_b->next;
	write(1, "rr\n", 3);
}
