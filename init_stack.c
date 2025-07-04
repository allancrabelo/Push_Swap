/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:56:18 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/04 18:00:01 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			error (a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error (a);
		if (duplicate_check(*a, (int)n))
			error (a);
		append_node(a, (int)n);
		i++;
	}
	current_index(*a);
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	move_to_top(t_stack_node **stack, t_stack_node *node_for_top,
													char stack_name)
{
	while (*stack != node_for_top)
	{
		if (stack_name == 'a')
		{
			if (node_for_top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (node_for_top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
