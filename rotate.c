/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:05:04 by aaugusto          #+#    #+#             */
/*   Updated: 2025/06/19 17:21:54 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	if (!stack || !(*stack))
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	return ;
}

top -> 1 -> 2 -> 3

top -> 2 
