/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:47:59 by abonneau          #+#    #+#             */
/*   Updated: 2025/02/08 23:21:26 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		*a_values;

	if (push_swap_pre_parser(&stack, argc, argv, &a_values) != VALID_PARAMS)
		return (1);
	if (!stack_initialiser(&stack, a_values))
	{
		push_swap_free(&stack, a_values);
		return (2);
	}
	push_swap_resolver(&stack);
	push_swap_free(&stack, a_values);
	return (0);
}
