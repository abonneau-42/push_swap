/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:55:33 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/22 15:56:53 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb_rb(t_stack *stack)
{
	sb(stack);
	rb(stack);
}

void	rb_sb(t_stack *stack)
{
	rb(stack);
	sb(stack);
}

void	sa_ra(t_stack *stack)
{
	sa(stack);
	ra(stack);
}

void	ra_sa(t_stack *stack)
{
	ra(stack);
	sa(stack);
}
