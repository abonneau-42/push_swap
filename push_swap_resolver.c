/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_resolver.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:38:09 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/20 20:28:39 by abonneau         ###   ########.fr       */
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

void sb_rb(t_stack *stack)
{
	sb(stack);
	rb(stack);
}

void rb_sb(t_stack *stack)
{
	rb(stack);
	sb(stack);
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

int push_swap_resolver_simple_b(t_stack *stack, t_list *top)
{
	int	val1;
	int	val2;
	int	val3;
	void (*operation)(t_stack *);

	val1 = top->value;
	val2 = top->next->value;
	val3 = top->next->next->value;
	
    void (*tab[2][2][2])(t_stack *) = {
        {
            {
                NULL, 		// 1 2 3
                &sb_rb    	// 1 3 2
            },
            {
                NULL,  		// impossible
                &rrb      	// 2 3 1
            }
        },
        {
            {
                &sb,   		// 2 1 3
                NULL   		// impossible
            },
            {
                &rb, 		// 3 1 2
                &rb_sb  	// 3 2 1
            }
        }
    };

	operation = tab[val1 > val2][val1 > val3][val2 > val3];
    if (operation != NULL)
        operation(stack);
}

int push_swap_resolver_simple_a(t_stack *stack, t_list *top)
{
	int	val1;
	int	val2;
	int	val3;
	void (*operation)(t_stack *);

	val1 = top->value;
	val2 = top->next->value;
	val3 = top->next->next->value;
	
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


// peut le faire encore plus tot
void	findbest_move(t_stack *stack, int size, t_dir *dirs)
{
	t_list *tmp = stack->top_a;
	t_dir 	cost_a;
	t_dir	cost_b;
	int	total_cost = (stack->size_a + stack->size_b) * 4;
	int total_cost_tmp = (stack->size_a + stack->size_b) * 4;

	dirs[0].value = (stack->size_a + stack->size_b) * 2;
	dirs[1].value = (stack->size_a + stack->size_b) * 2;
	while (size--)
	{
		cost_a = count_cost_to_push_value(stack, tmp->value);
		cost_b = count_cost_b(stack, tmp);
		if (cost_a.dir == cost_b.dir)
			total_cost = ft_max(cost_a.value, cost_b.value);
		else
			total_cost = cost_a.value + cost_b.value;
		if (total_cost < total_cost_tmp)
		{
			total_cost_tmp = total_cost;
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


void	find_new_limit(t_stack *stack)
{
	t_list *tmp = stack->top_b;
	int 	i;

	i = 0;
	stack->max_b = stack->top_b->value;
	stack->min_b = stack->top_b->value;
	while (i < stack->size_b)
	{
		if (tmp->value > stack->max_b)
			stack->max_b = tmp->value;
		if (tmp->value < stack->min_b)
			stack->min_b = tmp->value;
		tmp = tmp->next;
		i++;
	}
}


int push_swap_resolver_complex(t_stack *stack)
{	
	pb(stack);
	pb(stack);
	
	t_dir	dirs[2];
	
	while (stack->size_a)
	{
		find_new_limit(stack);
		//print_stack_b(stack);
		findbest_move(stack, stack->size_a, dirs);
		
		int common_action;

		common_action = 0;
		
		
		if (dirs[0].dir == dirs[1].dir)
		{
			common_action = ft_min(dirs[0].value, dirs[1].value);
			// printf("dirs[0].value=%i\n", dirs[0].value);
			// printf("dirs[1].value=%i\n", dirs[1].value);
			// printf("common_action=%i\n", ft_min(dirs[0].value, dirs[1].value));
			common_action_handler(stack, common_action, dirs[0].dir);
			dirs[0].value = dirs[0].value - common_action;
			dirs[1].value = dirs[1].value - common_action;
		}

		if (dirs[0].dir == 'n')
		{
			while (dirs[0].value)
			{
				ra(stack);
				dirs[0].value--;
			}
		}
		else
		{
			while (dirs[0].value)
			{
				rra(stack);
				dirs[0].value--;
			}
		}

		if (dirs[1].dir == 'n')
		{
			while (dirs[1].value)
			{
				rb(stack);
				dirs[1].value--;
			}
		}
		else
		{
			while (dirs[1].value)
			{
				rrb(stack);
				dirs[1].value--;
			}
		}
		
		pb(stack);
	}

	find_new_limit(stack);
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
	// print_stack_b(stack);

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
		push_swap_resolver_simple_a(stack, stack->top_a);
	else
		push_swap_resolver_complex(stack);


	// print_stack_a(stack);
	return (1);
}