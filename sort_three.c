/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:31:48 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/11 10:16:41 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, 1);
	else if ((*a)->next == biggest_node)
		rra(a, 1);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, 1);
}
