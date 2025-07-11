/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:27:45 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/11 10:17:41 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos_min(t_stack_node *stack)
{
	t_stack_node	*tmp;
	int				pos;
	int				min_pos;
	int				min_val;

	pos = 0;
	min_pos = 0;
	min_val = stack->nbr;
	tmp = stack;
	while (tmp)
	{
		if (tmp->nbr < min_val)
		{
			min_val = tmp->nbr;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

void	rotate_to_min(t_stack_node **stack)
{
	int	len;
	int	pos;

	len = stack_len(*stack);
	pos = get_pos_min(*stack);
	if (pos <= len / 2)
	{
		while (pos--)
			ra(stack, 1);
	}
	else
	{
		pos = len - pos;
		while (pos--)
			rra(stack, 1);
	}
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	if (!a || !*a)
		return ;
	rotate_to_min(a);
	pb(b, a, 1);
	rotate_to_min(a);
	pb(b, a, 1);
	sort_three(a);
	pa(a, b, 1);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, 1);
	pa(a, b, 1);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, 1);
}
