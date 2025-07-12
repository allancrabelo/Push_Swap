/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:03:46 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/11 10:17:12 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min_node;

	if (!a || !*a)
		return ;
	min_node = find_min(*a);
	while (*a != min_node)
		rra(a, 1);
	pb(b, a, 1);
	sort_three(a);
	pa(a, b, 1);
}
