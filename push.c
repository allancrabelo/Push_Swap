/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:41:03 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/04 17:34:28 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node	**dest, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->next = *dest;
	if (*dest)
		(*dest)->prev = node_to_push;
	node_to_push->prev = NULL;
	*dest = node_to_push;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	if (!*b)
		return ;
	push (a, b);
	write (1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	if (!*a)
		return ;
	push (b, a);
	write (1, "pb\n", 3);
}
