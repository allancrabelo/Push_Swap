/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:47:08 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/03 18:38:18 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node) //Enquanto o node no topo de 'b' nao for o target do node mais barato e o node no topo de 'a' nao for o node mais barato
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node) //Enquanto o node no topo de 'b' nao for o target do node mais barato e o node no topo de 'a' nao for o node mais barato
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	move_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a); 
	if (cheapest_node->above_median 
		&& cheapest_node->target->above_median) //Se ambos o node mais barato de 'a' e o seu target node em 'b' estiverem acima do meio
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) 
		&& !(cheapest_node->target->above_median)) //Se ambos o node mais barato de 'a' e o seu target node em 'b' estiverem abaixo do meio
		rev_rotate_both(a, b, cheapest_node);
	move_to_top(a, cheapest_node, 'a'); //Asegurar que o node mais barato esta no topo da stack 'a'
	move_to_top(b, cheapest_node->target, 'b'); //Asegurar que o target do node de 'a' esta no topo da stack 'b'
	pb(b, a);
}

static void	move_to_a(t_stack_node **a, t_stack_node **b)
{
	move_to_top(a, (*b)->target, 'a'); //Asegurar que o target do node de 'b' esta no topo da stack 'a'
	pa(a, b); 
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr) //Loopa ate o minimo estar no topo
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	
	if (len_a-- > 3 && !sorted(*a)) //Se a stack 'a' tiver mais de 3 nodes e nao estiverem organizados
		pb(b, a);
	if (len_a-- > 3 && !sorted(*a)) //Se a stack 'a' ainda tiver mais de 3 nodes e nao estiverem organizados
		pb(b, a);
	while (len_a-- > 3 && !sorted(*a)) //Loopa enquanto a stack tem mais de 3 nodes e nao estao organizados
	{
		init_nodes_a(*a, *b); //Inicializa os nodes
		move_to_b(a, b); //Move o node mais barato em 'a', para uma lista organizada descendente em 'b'
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b); //Inicializa os nodes
		move_to_a(a, b); //Move os nodes de volta para a stack 'a', ficando organizados
	}
	current_index(*a);
	min_on_top(a); //Mover o menor numero par o topo de 'a'
}