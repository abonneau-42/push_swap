/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:47:59 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/14 17:33:18 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	int	*a_values;
	char **tab;
	
	stack.size_a = argc - 1;
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		if (!tab)
			return (0);
		stack.size_a = count_tab_size(tab);
		a_values = malloc(sizeof(int) * stack.size_a);
		argv = tab;
	}
	else
		a_values = malloc(sizeof(int) * stack.size_a);
	if (!a_values)
		return (0);
	if (!push_swap_parser(argc, argv, a_values))
	{
		write(2, "Error\n", 6);
		free(a_values);
		return (0);
	}
	if (stack.size_a < 2)
	{
		free(a_values);
		return (0);
	}

	
	stack.size_b = 0;
	stack.top_a = NULL;
	stack.top_b = NULL;
	stack.a = malloc(sizeof(t_list) * stack.size_a);
	stack.b = malloc(sizeof(t_list) * stack.size_a);
	if (!stack.a || !stack.b || !create_bidir_list(stack.a, a_values, stack.size_a))
	{
		free(a_values);
		return (0);
	}
	stack.top_a = stack.a[0];

	push_swap_resolver(&stack);

	
}


