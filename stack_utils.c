/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:04:21 by aaugusto          #+#    #+#             */
/*   Updated: 2025/06/20 18:42:20 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	stack_len(t_stack_node *stack)
{
	int				len;
	t_stack_node	*node;
	
	len = 0;
	node = stack;
	while(node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while(stack->next)
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_min(t_stack_node **stack)
{
	t_stack_node	*min;
	t_stack_node	*node;
	
	min = *stack;
	node = *stack;
	
	while (node)
	{
		if (min->nbr > node->nbr)
			min = node;
		node = node->next;
	}
	return (min);
}

t_stack_node	*find_max(t_stack_node **stack)
{
	t_stack_node	*max;
	t_stack_node	*node;
	
	max = *stack;
	node = *stack;
	
	while (node)
	{
		if (max->nbr < node->nbr)
			max = node;
		node = node->next;
	}
	return (max);
}
