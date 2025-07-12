/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:47:08 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/11 10:14:56 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node)
		rr(a, b, 1);
	current_index(*a);
	current_index(*b);
}

void	move_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		rev_rotate_both(a, b, cheapest_node);
	move_to_top(a, cheapest_node, 'a');
	move_to_top(b, cheapest_node->target, 'b');
	pb(b, a, 1);
}

static void	move_to_a(t_stack_node **a, t_stack_node **b)
{
	move_to_top(a, (*b)->target, 'a');
	pa(a, b, 1);
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !sorted(*a))
		pb(b, a, 1);
	if (len_a-- > 3 && !sorted(*a))
		pb(b, a, 1);
	while (len_a-- > 3 && !sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
