/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:57:50 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/22 15:57:16 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_moves(t_stack *stack, int *value, void(*rotate)(t_stack *))
{
	while (*value)
	{
		rotate(stack);
		(*value)--;
	}
}

void	common_action_handler(t_stack *stack, int common_action, char direction)
{
	if (direction == 'n')
		apply_moves(stack, &common_action, rr);
	else
		apply_moves(stack, &common_action, rrr);
}

void	apply_rotation(t_stack *stack, t_dir *dir,
	void (*rotate)(t_stack *), void (*reverse_rotate)(t_stack *))
{
	if (dir->dir == 'n')
		apply_moves(stack, &dir->value, rotate);
	else
		apply_moves(stack, &dir->value, reverse_rotate);
}
