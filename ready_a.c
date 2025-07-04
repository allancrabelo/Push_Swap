/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 09:31:31 by aaugusto          #+#    #+#             */
/*   Updated: 2025/06/22 18:32:11 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i; 
	int	median;

	i = 0; 
	if (!stack) //Verifica se a stack esta vazia
		return ;
	median = stack_len(stack) / 2; //Calcula o meio da stack dividindo o tamanho da stack em 2
	while (stack) //Loopa a stack
	{
		stack->index = i; //Atribui ao campo de index do node o index atual
		if (i <= median) //Verifica se o index atual esta acima ou abaixo do meio
			stack->above_median = true; //Se estiver acima, o campo above_median fica a true
		else
			stack->above_median = false; //Se nao, fica false
		stack = stack->next; 
		++i; 
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b; 
	t_stack_node	*target_node;
	long			closest_smallest;
    
	while (a)
	{
		closest_smallest = LONG_MIN; //No inicio, o melhor 'match' e o minimo long
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr 
				&& current_b->nbr > closest_smallest) //Tem de encontrar o "closest smallest number" ou seja o valor de b tem de ser menor que o valor de a e maior que o melhor match
			{
				closest_smallest = current_b->nbr; //Se for o closest smallest number, atualiza a variavel que o guarda para o valor do b atual
				target_node = current_b; //Atribui a variavel que guarda o target node o node de b atual
			}
			current_b = current_b->next; //Continua a iterar a stack
		}
		if (closest_smallest == LONG_MIN) //Se o closest smallest for o LONG_MIN quer dizer que nao encontrou nenhum menor
			a->target = find_max(b); //Entao, encontra o maior valor em b e faz com que o node com esse valor seja o target node
		else
			a->target = target_node; //Se nao, muda o valor de target seja a variavel target node
		a = a->next; //Continua para o proximo node de a 
	}
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;
	int	a_cost;
	int	b_cost;

	len_a = stack_len(a);
	len_b = stack_len(b);
	
	while (a)
	{
		a_cost = a->index;
		if (!(a->above_median))
			a_cost = len_a - a->index;

		b_cost = a->target->index;
		if (!(a->target->above_median))
			b_cost = len_b - a->target->index;

		if ((a->above_median && a->target->above_median))
			a->push_cost = ft_max(a_cost, b_cost); //rr
		else if (!(a->above_median) && !(a->target->above_median))
			a->push_cost = ft_max(a_cost, b_cost); //rrr
		else
			a->push_cost = a_cost + b_cost; //separadas

		a = a->next;
	}
}


void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack) //Loopa a stack
	{
		if (stack->push_cost < cheapest_value) //Verifica se o push cost do node atual e menos que o node mais barato ate agora
		{
			cheapest_value = stack->push_cost; //Se sim, atualiza o valor para o push cost do node atual
			cheapest_node = stack; //Atribui a variavel o node mais barato
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true; //No fim, mete o bool 'cheapest' do node mais barato a true 
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}