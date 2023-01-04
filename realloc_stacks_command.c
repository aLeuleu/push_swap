/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_stacks_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:34:25 by alevra            #+#    #+#             */
/*   Updated: 2023/01/04 05:09:42 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	realloc_stacks_command(t_stacks_pair *stacks, size_t depth)
{
	char	**new_commands;
	size_t	i;
	size_t	base_size;

	base_size = 0;
	i = 0;
	if (depth >= stacks->commands_tab_size)
	{
		if (stacks->commands_tab_size <= 1)
			base_size = 1;
		new_commands = malloc(sizeof(char *)
				* (stacks->commands_tab_size * 2 + base_size));
		if (!new_commands)
			return (0);
		while (i < stacks->commands_tab_size)
		{
			new_commands[i] = ft_strdup(stacks->commands[i]);
			i++;
		}	
		ft_freetab((void **)stacks->commands, (stacks->commands_tab_size - 1));
		stacks->commands = new_commands;
		stacks->commands_tab_size = (stacks->commands_tab_size * 2) + base_size;
	}
	return (1);
}
