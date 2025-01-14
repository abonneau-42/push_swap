/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:37:45 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/14 17:31:13 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp;
	
	if (stack->size_a < 2)
		return ;
	tmp = stack->top_a->value;
	stack->top_a->value = stack->top_a->next->value;
	stack->top_a->next->value = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	int	tmp;
	
	if (stack->size_b < 2)
		return ;
	tmp = stack->top_b->value;
	stack->top_b->value = stack->top_b->next->value;
	stack->top_b->next->value = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	write(1, "ss\n", 3);
}