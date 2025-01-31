/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:12:36 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/31 13:46:28 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	push_swap_3(t_stack	*stack)
{
	int	values[3];

	values[0] = stack->top_a->value;
	values[1] = stack->top_a->next->value;
	values[2] = stack->top_a->next->next->value;
	if (values[0] > values[1] && values[1] > values[2])
		ra_sa(stack);
	else if (values[0] > values[2] && values[2] > values[1])
		ra(stack);
	else if (values[1] > values[0] && values[0] > values[2])
		rra(stack);
	else if (values[1] > values[2] && values[2] > values[0])
		sa_ra(stack);
	else if (values[2] > values[0] && values[0] > values[1])
		sa(stack);
}

t_dir	find_dir(t_stack *stack, int value)
{
	t_list	*tmp;
	t_dir	cost;

	tmp = stack->top_a;
	cost = (t_dir){.value = 0, .dir = 'n'};
	while (tmp)
	{
		if (tmp->value == value)
			return (cost);
		tmp = tmp->next;
		cost.value++;
	}
	cost = find_best_rotation(cost, stack->size_a, 'p');
	return (cost);
}

void	push_swap_n_sorter(t_stack *stack, size_t n, int *tab)
{
	size_t	i;
	t_dir	dir;

	i = 0;
	while (i < n - 3)
	{
		dir = find_dir(stack, tab[i]);
		apply_rotation(stack, &dir, ra, rra);
		pb(stack);
		i++;
	}
	free(tab);
	push_swap_3(stack);
	i = 0;
	while (i++ < n - 3)
		pa(stack);
}

int	push_swap_n(t_stack *stack, size_t n)
{
	int		*tab;
	size_t	i;
	t_list	*tmp;

	tab = malloc(sizeof(int) * n);
	if (!tab)
		return (0);
	tmp = stack->top_a;
	i = 0;
	while (i < stack->size_a)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sort_tab(tab, n);
	push_swap_n_sorter(stack, n, tab);
	return (1);
}
