/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:02:15 by aaugusto          #+#    #+#             */
/*   Updated: 2025/06/11 15:37:41 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int		nbr;//numero da pilha
	int		index;// posicao do numero para saber qual menor e maior
	int		push_cost;// custo para mover para algum lugar
	bool	above_median;// se estiver acima da mediana da pilha
	bool	cheapest;//marca o menor custo da operacao
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
	
}	t_stack_node;

//Handle Errors
int	ft_error(int error);

//Others
char	**split(char *string, char character);

#endif
