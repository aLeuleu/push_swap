/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:39:20 by alevra            #+#    #+#             */
/*   Updated: 2022/12/20 16:16:19 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	command_push(const char *command, t_stack *a, t_stack *b);
static void	command_swap(const char *command, t_stack *a, t_stack *b);
static void	command_rotate(const char *command, t_stack *a, t_stack *b);

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

static int	append_command(const char *command, t_stacks_pair *stacks,
		size_t depth)
{
	if (depth >= stacks->commands_tab_size)
	{
		if (!ft_realloc_stacks_command(stacks, depth))
			return (0);
	}
	stacks->commands[depth] = ft_strdup(command);
	return (1);
}

int	execute_command(const char *command, t_stacks_pair *old_stacks,
		t_stacks_pair **new_stacks, size_t depth)
{
	t_stack			*a;
	t_stack			*b;
	t_stacks_pair	*res;

	if (old_stacks == *new_stacks)
		res = *new_stacks;
	else
		res = stacks_dup(old_stacks);
	if (!res)
		return (0);
	a = res->a;
	b = res->b;
	if (command[0] == 'p')
		command_push(command, a, b);
	if (command[0] == 's')
		command_swap(command, a, b);
	if (command[0] == 'r')
		command_rotate(command, a, b);
	if (!append_command(command, res, depth))
		return (0);
	*new_stacks = res;
	return (1);
}

static void	command_push(const char *command, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(command, "pa", ft_strlen(command)))
		push(b, a);
	if (!ft_strncmp(command, "pb", ft_strlen(command)))
		push(a, b);
}

static void	command_swap(const char *command, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(command, "sa", ft_strlen(command)))
		swap(a);
	if (!ft_strncmp(command, "sb", ft_strlen(command)))
		swap(b);
	if (!ft_strncmp(command, "sb", ft_strlen(command)))
	{
		swap(a);
		swap(b);
	}
}

static void	command_rotate(const char *command, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(command, "ra", ft_strlen(command)))
		rotate(a);
	if (!ft_strncmp(command, "rb", ft_strlen(command)))
		rotate(b);
	if (!ft_strncmp(command, "rra", ft_strlen(command)))
		rotate_reverse(a);
	if (!ft_strncmp(command, "rrb", ft_strlen(command)))
		rotate_reverse(b);
	if (!ft_strncmp(command, "rrr", ft_strlen(command)))
	{
		rotate_reverse(a);
		rotate_reverse(b);
	}
}
