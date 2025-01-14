/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:47:59 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/14 04:16:44 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	int	*a_values;
	char **tab;
	
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		if (!tab)
			return (0);
		a_values = malloc(sizeof(int) * count_tab_size(tab));
		argv = tab;
	}
	else
		a_values = malloc(sizeof(int) * (argc - 1));
	if (!a_values)
		return (0);
	if (!push_swap_parser(argc, argv, a_values))
	{
		write(2, "Error\n", 6);
		free(a_values);
		return (0);
	}
	if (argc < 3)
	{
		free(a_values);
		return (0);
	}
	stack.size_a = argc - 1;
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
}


