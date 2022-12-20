/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_gen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:41:42 by alevra            #+#    #+#             */
/*   Updated: 2022/12/20 15:02:03 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_node(t_node *node)
{
	if (node->stacks->commands)
		ft_freetab((void **)node->stacks->commands, node->depth - 1); //depth - 1 ? 
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
	t_node		*nodes[NB_COMMANDS];
	int			i;
	static char	*commands[] = {"sa", "sb", "ss"};

	i = 0;
	while (i < NB_COMMANDS)
	{
		nodes[i] = malloc(sizeof(t_node));
		nodes[i]->depth = parent->depth + 1;
		if (!nodes[i])
			return (free_all_nodes(*nodes, i), 0);
		execute_command(commands[i], parent->stacks, &(nodes[i]->stacks),
			nodes[i]->depth);
		if (!nodes[i]->stacks)
			return (free_all_nodes(*nodes, i), 0);
		nodes[i]->parent = parent;
		nodes[i]->stacks->commands[parent->depth] = commands[i];
		i++;
	}
	return (1);
}
