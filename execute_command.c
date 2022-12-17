/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:39:20 by alevra            #+#    #+#             */
/*   Updated: 2022/12/17 20:16:53 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		command_push(const char *command, t_stack *a, t_stack *b);
static void		command_swap(const char *command, t_stack *a, t_stack *b);
static void		command_rotate(const char *command, t_stack *a, t_stack *b);

t_stacks_pair	*execute_command(const char *command, t_stacks_pair *stacks)
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
