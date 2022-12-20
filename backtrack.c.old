/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:06:07 by alevra            #+#    #+#             */
/*   Updated: 2022/12/20 19:24:02 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_first_node(t_stacks_pair *stacks)
{
	t_node	*first_node;

	first_node = malloc(sizeof(t_node));
	if (!first_node)
		return (NULL);
	first_node->depth = 0;
	first_node->parent = NULL;
	first_node->stacks = stacks;
}

int	backtrack(t_stacks_pair *stacks)
{
	t_node	*first_node;

	first_node = create_first_node(stacks);
	if (!first_node)
		return (0);
	return(1);
	//stacks should point to the solution
}