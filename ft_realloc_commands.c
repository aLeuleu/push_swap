/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:21:02 by alevra            #+#    #+#             */
/*   Updated: 2022/12/20 16:21:45 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_realloc_stacks_command(t_stacks_pair *stacks, size_t depth)
{
	char	**new_commands;
	size_t	i;
	size_t	base_size;
	
	base_size = 0;
	i = 0;
	if (depth >= stacks->commands_tab_size)
	{
		if (!stacks->commands_tab_size)
			base_size = 10;
		new_commands = malloc(sizeof(char *) * (stacks->commands_tab_size * 2 + base_size));
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
