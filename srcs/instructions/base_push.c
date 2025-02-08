/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:57:31 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/22 15:48:36 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	int		tmp;
	t_list	*new_top_b;

	if (stack->size_b == 0)
		return ;
	tmp = stack->top_b->value;
	if (stack->size_b == 1)
		new_top_b = NULL;
	else
	{
		(stack->top_b->prev)->next = stack->top_b->next;
		(stack->top_b->next)->prev = stack->top_b->prev;
		new_top_b = stack->top_b->next;
	}
	free(stack->top_b);
	stack->top_b = new_top_b;
	lstadd_bidir_front(&stack->top_a, tmp);
	stack->size_a++;
	stack->size_b--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	int		tmp;
	t_list	*new_top_a;

	if (stack->size_a == 0)
		return ;
	tmp = stack->top_a->value;
	if (stack->size_a == 1)
		new_top_a = NULL;
	else
	{
		(stack->top_a->prev)->next = stack->top_a->next;
		(stack->top_a->next)->prev = stack->top_a->prev;
		new_top_a = stack->top_a->next;
	}
	free(stack->top_a);
	stack->top_a = new_top_a;
	lstadd_bidir_front(&stack->top_b, tmp);
	stack->size_a--;
	stack->size_b++;
	write(1, "pb\n", 3);
}
