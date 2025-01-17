/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_resolver.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:38:09 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/17 21:08:32 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_a(t_stack *stack)
{
	int i = 0;
	t_list *tmp = stack->top_a;

	while (i < stack->size_a)
	{
		printf("[A] index[%i]=%i\n", i, tmp->value);
		tmp = tmp->next;
		i++;
	}
}

void	print_stack_b(t_stack *stack)
{
	int i = 0;
	t_list *tmp = stack->top_b;

	while (i < stack->size_b)
	{
		printf("[B] index[%i]=%i\n", i, tmp->value);
		tmp = tmp->next;
		i++;
	}
}

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

// Do not warn about returning a pointer (or in C++, a reference) to a variable that goes out of scope after the function returns.
void	findbest_move(t_stack *stack, int size, t_dir *dirs)
{
	t_list *tmp = stack->top_a;
	t_dir 	cost_a;
	t_dir	cost_b;

	dirs[0].value = (stack->size_a + stack->size_b) * 2;
	dirs[1].value = (stack->size_a + stack->size_b) * 2;
	while (size--)
	{
		cost_a = count_cost_to_push_value(stack, tmp->value);
		cost_b = count_cost_b(stack, tmp);
		if (dirs[0].value + dirs[1].value > cost_a.value + cost_b.value)
		{
			dirs[0] = cost_a;
			dirs[1] = cost_b;	
		}
		tmp = tmp->next;
	}
}

void common_action_handler(t_stack *stack, int common_action, char direction)
{
	if (direction == 'n')
	{
		while (common_action)
		{
			rr(stack);
			common_action--;
		}
	}
	else
	{
		while (common_action)
		{
			rrr(stack);
			common_action--;
		}
	}
}



int push_swap_resolver_complex(t_stack *stack)
{	
	pb(stack);
	stack->max_b = stack->top_b->value;
	//print_stack_b(stack);
	pb(stack);
	if (stack->max_b < stack->top_b->value)
	{
		stack->min_b = stack->max_b;
		stack->max_b = stack->top_b->value;
	}
	else
		stack->min_b = stack->top_b->value;
	
	t_dir	dirs[2];
	
	while (stack->size_a)
	{
		//print_stack_b(stack);
		findbest_move(stack, stack->size_a, dirs);
		
		int common_action;

		common_action = 0;
		/*
		if (dirs[0].dir == dirs[1].dir)
		{
			common_action = ft_min(dirs[0].value, dirs[1].value);
			common_action_handler(stack, common_action, dirs[0].dir);
		}*/

		if (dirs[0].dir == 'n')
		{
			while (dirs[0].value - common_action)
			{
				ra(stack);
				dirs[0].value--;
			}
		}
		else
		{
			while (dirs[0].value - common_action)
			{
				rra(stack);
				dirs[0].value--;
			}
		}

		if (dirs[1].dir == 'n')
		{
			while (dirs[1].value - common_action)
			{
				rb(stack);
				dirs[1].value--;
			}
		}
		else
		{
			while (dirs[1].value - common_action)
			{
				rrb(stack);
				dirs[1].value--;
			}
		}
		
		pb(stack);
	}
	//print_stack_b(stack);

	
	t_dir max;
	
	max = count_cost_b_to_max(stack);
	if (max.dir == 'n')
	{
		while (max.value)
		{
			rb(stack);
			max.value--;
		}
	}
	else
	{
		while (max.value)
		{
			rrb(stack);
			max.value--;
		}
	}

	//print_stack_b(stack);

	int j = stack->size_b;
	while (j)
	{
		pa(stack);
		//print_stack_a(stack);
		j--;
	}
}



int	push_swap_resolver(t_stack *stack)
{	
	if (stack->size_a == 2)
	{
		if (stack->top_a->value > stack->top_a->next->value)
			sa(stack);
		else
			return (1);
	}
	else if (stack->size_a == 3)
		push_swap_resolver_simple(stack);
	else
		push_swap_resolver_complex(stack);


	print_stack_a(stack);
	return (1);
}