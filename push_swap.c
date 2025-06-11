/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:18:45 by aaugusto          #+#    #+#             */
/*   Updated: 2025/06/11 15:55:14 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack_node	*a;// pilha original que sera ordenada
	t_stack_node	*b;// pilha incial vazia
	
	a = NULL;// zero as pilhas
	b = NULL;
	//tenho de validar se o que entra como argumento
	//./push_swap && ./push_swap ""
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_error(1));
	//preciso tratar o caso de que ele entre com forma de arg unico
	else if (argc == 2)
		argv = split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	return (0);
}
