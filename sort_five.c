/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:27:45 by aaugusto          #+#    #+#             */
/*   Updated: 2025/06/22 16:54:00 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min_node;

	if (!a || !*a)
		return ;
	min_node = find_min(*a);
	while(*a != min_node)
		ra(a);
	pb(b, a);
	min_node = find_min(*a);
	while(*a != min_node)
		ra(a);
	pb(b, a);
	sort_three(a);
	pa(a, b);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
	pa(a,b);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}