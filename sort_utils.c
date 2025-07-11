/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:42:16 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/11 10:17:56 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node)
		rrr(a, b, 1);
	current_index(*a);
	current_index(*b);
}
