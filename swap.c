/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:32:30 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/11 10:12:37 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack_node **a, int print)
{
	if (stack_len(*a) < 2)
		return ;
	swap(a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, int print)
{
	if (stack_len(*b) < 2)
		return ;
	swap(b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, int print)
{
	if (stack_len(*a) < 2 || stack_len(*b) < 2)
		return ;
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
}
