/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_resolver.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneau <abonneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:38:09 by abonneau          #+#    #+#             */
/*   Updated: 2025/01/23 02:17:54 by abonneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack_a(t_stack *stack)
{
    t_list *tmp;
	size_t i = 0;

    tmp = stack->top_a;
    while (i < stack->size_a)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
		i++;
    }
}

void print_stack_b(t_stack *stack)
{
    t_list *tmp;
	size_t i = 0;

    tmp = stack->top_b;
    while (i < stack->size_b)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
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

void	compute_best_move(t_stack *stack, t_list *tmp, t_move_data *move_data)
{
	t_dir	cost_a;
	t_dir	cost_b;

	cost_a = count_cost_to_push_value(stack, tmp->value);
	cost_b = count_cost_b(stack, tmp);
	update_best_move(move_data, TRUE, cost_a, cost_b);
	cost_a = invert_rotation(cost_a, stack->size_a);
	cost_b = invert_rotation(cost_b, stack->size_b);
	update_best_move(move_data, TRUE, cost_a, cost_b);
	cost_a = find_best_rotation(cost_a, stack->size_a, 'n');
	cost_b = find_best_rotation(cost_b, stack->size_b, 'n');
	update_best_move(move_data, FALSE, cost_a, cost_b);
}

void	findbest_move(t_stack *stack, int size, t_move_data *move_data)
{
	t_list	*tmp;

	tmp = stack->top_a;
	move_data->total_cost_tmp = MAX_COST;
	move_data->dirs[0].value = MAX_COST;
	move_data->dirs[1].value = MAX_COST;
	while (size--)
	{
		compute_best_move(stack, tmp, move_data);
		tmp = tmp->next;
	}
}

void    find_position_a(t_stack *stack, int value,
    int *nearest_min_value, int *nearest_max_value)
{
    size_t    i;
    t_list    *tmp;

    i = 0;
    tmp = stack->top_a;
    *nearest_min_value = stack->min_a;
    *nearest_max_value = stack->max_a;
	// printf("min_a = %d\n", stack->min_a);
	// printf("max_a = %d\n", stack->max_a);
    while (i < stack->size_a)
    {
		if (tmp->value < value
			&& abs(value - tmp->value) < abs(value - *nearest_min_value))
			*nearest_min_value = tmp->value;
		if (tmp->value > value
			&& abs(tmp->value - value) < abs(*nearest_max_value - value))
			*nearest_max_value = tmp->value;

		
        // if (tmp->value < value
        //     && abs(value - tmp->value) < abs(value - *nearest_min_value))
        //     *nearest_min_value = tmp->value;
        // if (tmp->value > value
        //     && abs(tmp->value - value) < abs(*nearest_max_value - value))
        //     *nearest_max_value = tmp->value;
        tmp = tmp->next;
        i++;
    }
}

t_dir    count_cost_b_to_value_a(t_stack *stack, int value)
{
	static int decrement = 3;
    t_list    *tmp;
    t_dir    cost;
    size_t       i;

    i = 0;
    tmp = stack->top_a;
	cost = (t_dir){.value=0, .dir='p'};
	// if (stack->size_a == 3)
	// {
	// 	// if (value < tmp->prev->value)
	// 	// 	return ((t_dir){.value=1, .dir='p'});
	// 	return (cost);
	// }
	while (value < tmp->prev->value && decrement)
	{
		tmp = tmp->prev;
		i++;
		cost = (t_dir){.value=i, .dir='p'};
		decrement--;
		if (i == stack->size_a)
			break ;
	}
    return (cost);
}

void	push_swap_resolver_complex(t_stack *stack)
{
	t_dir		max;
	t_move_data	move_data;
	int			valuep;
	t_dir		cost;

	pb(stack);
	pb(stack);
	while (stack->size_a - 3)
	{
		update_stack_limits(stack);
		findbest_move(stack, stack->size_a, &move_data);
		handle_common_actions(stack, move_data.dirs);
		apply_rotation(stack, &move_data.dirs[0], ra, rra);
		apply_rotation(stack, &move_data.dirs[1], rb, rrb);
		pb(stack);
	}
	update_stack_limits(stack);
	max = find_best_rotation(count_cost_b_to_max(stack), stack->size_b, 'p');
	apply_rotation(stack, &max, rb, rrb);

	push_swap_3(stack);
	update_stack_limits_a(stack);
	//print_stack_a(stack);
    while (stack->size_b)
    {
		cost.dir = 'n';
		cost.value = 0;
        valuep = stack->top_b->value;
		// printf("valuep = %d\n", valuep);
        cost = count_cost_b_to_value_a(stack, valuep);
		// printf("cost.value = %lu\n", cost.value);
		apply_rotation(stack, &cost, ra, rra);
		// apply_moves(stack, &cost.value, ra);
        pa(stack);
		update_stack_limits_a(stack);
		//print_stack_a(stack);
    }

	while (stack->top_a->value > stack->top_a->prev->value)
		rra(stack);

	// update_stack_limits(stack);
	// max = find_best_rotation(count_cost_a_to_max(stack), stack->size_b, 'p');
	// apply_rotation(stack, &max, ra, rra);
	
	// return ;

	// //print_stack_a(stack);
	// //print_stack_b(stack);
	// while (stack->size_b)
	// 	pa(stack);
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
		push_swap_3(stack);
	else
		push_swap_resolver_complex(stack);
	return (1);
}
