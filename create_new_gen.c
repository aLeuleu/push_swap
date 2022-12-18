/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_gen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:41:42 by alevra            #+#    #+#             */
/*   Updated: 2022/12/18 03:35:03 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_node(t_node *node)
{
	if (node->commands)
		ft_freetab((void **)node->commands, node->depth);
	free(node);
}

static void	free_all_nodes(t_node *nodes, int pos)
{
	if (nodes)
		while (pos)
			free_node(&nodes[pos--]);
	free(nodes);
}

int	create_new_gen(t_node *parent)
{
	t_node *nodes[NB_COMMANDS];
	int i;
	static char *commands[] = {"sa", "sb", "ss"};

	i = 0;
	while (i < NB_COMMANDS)
	{
		nodes[i] = malloc(sizeof(t_node));
		if (!nodes[i])
			return (free_all_nodes(*nodes, i), 0);
		nodes[i]->stacks = execute_command(commands[i], parent->stacks);
		if (!nodes[i]->stacks)
			return (free_all_nodes(*nodes, i), 0);
		nodes[i]->depth = parent->depth + 1;
		nodes[i]->parent = parent;
		nodes[i]->commands[parent->depth] = commands[i];
		i++;
	}
	return (1);
}