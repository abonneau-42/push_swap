/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:47:59 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/13 19:00:38 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int j;
	t_stack	stack;

	j = 0;
	if (argc < 3) 
		return (0);
	stack.size_a = argc - 1;
	stack.size_b = 0;
	stack.top_a = NULL;
	stack.top_b = NULL;
	stack.a = malloc(sizeof(t_list) * stack.size_a);
	stack.b = malloc(sizeof(t_list) * stack.size_a);
	if (!stack.a || !stack.b)
		return (0);
	if (!create_bidir_list(stack.a, argv, stack.size_a))
		return (0);
	stack.top_a = stack.a[0];
	
	t_list *tmp = stack.top_a;
	
	while (j < stack.size_a)
	{
		printf("value = %d\n", tmp->value);
		tmp = tmp->next;
		j++;
	}

	pb(&stack);
	pb(&stack);
	pb(&stack);

	printf("pb-next------------\n");

	j = 0;

	tmp = stack.top_a;

	while (j < stack.size_a)
	{
		printf("value = %d\n", tmp->value);
		tmp = tmp->next;
		j++;
	}

	printf("stackb------------\n");
	
	j = 0;
	
	tmp = stack.top_b;

	
	while (j < stack.size_b)
	{
		printf("value = %i\n", tmp->value);
		tmp = tmp->next;
		j++;
	}
}
