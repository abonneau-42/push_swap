/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialiser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:57:08 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/22 15:55:24 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_initialiser(t_stack *stack, int *a_values)
{
	stack->size_b = 0;
	stack->top_a = NULL;
	stack->top_b = NULL;
	stack->a = malloc(sizeof(t_list) * stack->size_a);
	stack->b = malloc(sizeof(t_list) * stack->size_a);
	if (!stack->a || !stack->b
		|| !create_bidir_list(stack->a, a_values, stack->size_a))
	{
		free(a_values);
		return (0);
	}
	stack->top_a = stack->a[0];
	return (1);
}
