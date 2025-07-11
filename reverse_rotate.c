/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:57:29 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/11 10:12:03 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	before_last = last->prev;
	before_last->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	last->prev = NULL;
	*stack = last;
}

void	rra(t_stack_node **a, int print)
{
	if (stack_len(*a) < 2)
		return ;
	rev_rotate (a);
	if (print)
		write (1, "rra\n", 4);
}

void	rrb(t_stack_node **b, int print)
{
	if (stack_len(*b) < 2)
		return ;
	rev_rotate (b);
	if (print)
		write (1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, int print)
{
	if (stack_len(*a) < 2 && stack_len(*b) < 2)
		return ;
	rev_rotate (a);
	rev_rotate (b);
	if (print)
		write (1, "rrr\n", 4);
}
