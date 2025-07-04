/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:05:04 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/04 17:36:39 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = find_last(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack_node **a)
{
	if (stack_len(*a) < 2)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	if (stack_len(*b) < 2)
		return ;
	rotate (b);
	write (1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	if (stack_len(*a) < 2 && stack_len(*b) < 2)
		return ;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
