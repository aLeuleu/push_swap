/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_gen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:41:42 by alevra            #+#    #+#             */
/*   Updated: 2022/12/17 20:10:03 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_node(t_node *node)
{
	if (node->commands)
		ft_freetab(node->commands, node->depth);
	free(node);
}

static void	free_all_nodes(t_node *nodes, int pos)
{
	if (nodes)
		while (pos)
			free_node(&nodes[pos--]);
	free(nodes);
}

int	create_new_gen(t_node *parent, int nb_commands)
{
	t_node	*nodes[NB_COMMANDS];
	int		i;

	i = 0;
	while (i < NB_COMMANDS)
	{
		nodes[i] = malloc(sizeof(t_node));
		if (!nodes[i])
			return(free_all_nodes(*nodes, i), 0);
		i++;
		nodes[i]->stacks = execute_command(COMMANDS[i], parent->stacks);
	}
	return (1);
}