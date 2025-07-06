/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 09:31:31 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/06 15:32:40 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			closest_smallest;

	while (a)
	{
		closest_smallest = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr
				&& current_b->nbr > closest_smallest)
			{
				closest_smallest = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_smallest == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;
	int	a_cost;
	int	b_cost;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a_cost = a->index;
		if (!(a->above_median))
			a_cost = len_a - a->index;
		b_cost = a->target->index;
		if (!(a->target->above_median))
			b_cost = len_b - a->target->index;
		if ((a->above_median && a->target->above_median))
			a->push_cost = ft_max(a_cost, b_cost);
		else if (!(a->above_median) && !(a->target->above_median))
			a->push_cost = ft_max(a_cost, b_cost);
		else
			a->push_cost = a_cost + b_cost;
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
