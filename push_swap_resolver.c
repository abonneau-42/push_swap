/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_resolver.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:38:09 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/14 18:52:09 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa_ra(t_stack *stack)
{
	sa(stack);
	ra(stack);
}

void ra_sa(t_stack *stack)
{
	ra(stack);
	sa(stack);
}

int push_swap_resolver_simple(t_stack *stack)
{
	int	val1;
	int	val2;
	int	val3;
	void (*operation)(t_stack *);

	val1 = stack->top_a->value;
	val2 = stack->top_a->next->value;
	val3 = stack->top_a->next->next->value;
	

    void (*tab[2][2][2])(t_stack *) = {
        {
            {
                NULL, 		// 1 2 3
                &sa_ra    	// 1 3 2
            },
            {
                NULL,  		// impossible
                &rra      	// 2 3 1
            }
        },
        {
            {
                &sa,   		// 2 1 3
                NULL   		// impossible
            },
            {
                &ra, 		// 3 1 2
                &ra_sa   	// 3 2 1
            }
        }
    };

	operation = tab[val1 > val2][val1 > val3][val2 > val3];
    if (operation != NULL)
        operation(stack);
}

int push_swap_resolver_complex(t_stack *stack)
{
	int max;
	int min;
	
	pb(stack);
	max = stack->top_b->value;
	pb(stack);
	if (max < stack->top_b->value)
	{
		min = max;
		max = stack->top_b->value;
	}
	else
		min = stack->top_b->value;
	
	













	
}

int	push_swap_resolver(t_stack *stack)
{
	int i = 0;
	t_list *tmp = stack->top_a;

	while (i < stack->size_a)
	{
		printf("index[%i]=%i\n", i, tmp->value);
		tmp = tmp->next;
		i++;
	}


	
	if (stack->size_a == 2 && stack->top_a->value > stack->top_a->next->value)
		sa(stack);
	else if (stack->size_a == 3)
		push_swap_resolver_simple(stack);
	else
		push_swap_resolver_complex(stack);

	i = 0;
	tmp = stack->top_a;

	while (i < stack->size_a)
	{
		printf("index[%i]=%i\n", i, tmp->value);
		tmp = tmp->next;
		i++;
	}

	return (1);
}