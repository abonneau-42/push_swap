/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:12:36 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/23 23:48:23 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tab(int *tab, int size) {
    int tmp;
    int i = 0;
    
    while (i < size - 1) {
        int j = 0;
        while (j < size - i - 1) {
            if (tab[j] > tab[j + 1]) {
                // Échanger les éléments
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


// Trouver l'index d'une valeur dans la pile A
t_dir	find_dir(t_stack *stack, int value)
{
	t_list	*tmp = stack->top_a;
	t_dir	cost;

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

void	push_swap_5(t_stack *stack)
{
	int	tab[5];
	size_t	i;
	t_dir dir;

	i = 0;
	t_list *tmp = stack->top_a;
	while (i < stack->size_a)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sort_tab(tab, 5);
	dir = find_dir(stack, tab[0]);
	apply_rotation(stack, &dir, ra, rra);
	pb(stack);
	dir = find_dir(stack, tab[1]);
	apply_rotation(stack, &dir, ra, rra);
	pb(stack);
	push_swap_3(stack);
	pa(stack);
	pa(stack);
}

int	push_swap_n(t_stack *stack, size_t n)
{
	int		*tab;
	size_t	i;
	t_dir dir;

	if (n > 3)
	{
		tab = malloc(sizeof(int) * n);
		if (!tab)
			return (0);
		t_list *tmp = stack->top_a;
		i = 0;
		while (i < stack->size_a)
		{
			tab[i] = tmp->value;
			tmp = tmp->next;
			i++;
		}
		sort_tab(tab, n);
	}
	i = 0;
	while (i < n - 3)
	{
		dir = find_dir(stack, tab[i]);
		apply_rotation(stack, &dir, ra, rra);
		pb(stack);
		i++;
	}
	if (n > 3)
		free(tab);
	push_swap_3(stack);
	i = 0;
	while (i < n - 3)
	{
		pa(stack);
		i++;
	}
	return (1);
}




