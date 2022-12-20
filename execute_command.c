/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:39:20 by alevra            #+#    #+#             */
/*   Updated: 2022/12/20 14:54:54 by alevra           ###   ########lyon.fr   */
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
		ft_printf("depth(%d) >= stacks commands size (%d)\n", depth, stacks->commands_tab_size);
		if (!stacks->commands_tab_size)
			base_size = 10;
		new_commands = malloc(sizeof(char *) * (stacks->commands_tab_size * 2 + base_size));
		if (!new_commands)
			return(0);
		while (i < stacks->commands_tab_size)
		{
			new_commands[i] = stacks->commands[i];
		 	i++;
		}
		ft_printf("f2 command size : %d\n", stacks->commands_tab_size);			
		for (size_t k = 0; k < stacks->commands_tab_size; k++)
		{
			ft_printf("%d : %c\n", k, stacks->commands[k]);
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
	ft_printf("trying to append \"%s\" with depth : %d \n", command, depth);
	if (depth > stacks->commands_tab_size)
	{
		ft_printf("stack commands size : %d\n", stacks->commands_tab_size);
		if (!ft_realloc_stacks_command(stacks, depth))
			return (0);
		stacks->commands[depth] = ft_strdup(command);
	}
	ft_printf("..%d : ok !\n", depth);
	return (1);
}

int	execute_command(const char *command, t_stacks_pair *old_stacks,
		t_stacks_pair **new_stacks, size_t depth)
{
	t_stack			*a;
	t_stack			*b;
	t_stacks_pair	*res;

	a = stacks->a;
	b = stacks->b;
/* 	ft_printf(command);
	ft_printf("\n");
 */	if (command[0] == 'p')
		command_push(command, a, b);
	if (command[0] == 's')
		command_swap(command, a, b);
	if (command[0] == 'r')
		command_rotate(command, a, b);
	res = malloc(sizeof(t_stacks_pair));
	if (!res)
		return (NULL);
	cpy_stacks(stacks, res);
	//make sure cpy went OK
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
