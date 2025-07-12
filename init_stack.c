/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:56:18 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/11 17:22:21 by aaugusto         ###   ########.fr       */
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

void	init_stack_a(t_stack_node **a, char **argv, int is_split)
{
	long	n;
	int		i;

	i = 0;
	if (!argv)
		return ;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			error(a, argv, is_split);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error(a, argv, is_split);
		if (duplicate_check(*a, (int)n))
			error(a, argv, is_split);
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
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (node_for_top->above_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}
