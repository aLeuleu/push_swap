/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:08:51 by alevra            #+#    #+#             */
/*   Updated: 2023/01/04 23:16:54 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_args(size_t size, char const *argv[]);
static int		handle_mono_arg(t_stacks_pair *stacks, const char *argv1);
static void		error(void);

static int	check_args(size_t size, char const *argv[])
{
	size_t		i;
	long long	res;

	i = 0;
	while (i < size)
	{
		res = ft_atoll(argv[i]);
		if (!ft_isnumber(argv[i])
			|| how_many_appearance((char *)argv[i++], (char **)argv) > 1
			|| ft_overflow_int(res))
			return (0);
	}
	return (1);
}

static int	handle_mono_arg(t_stacks_pair *stacks, const char *argv1)
{
	int		j;
	char	**splits;

	j = 0;
	splits = (ft_split(argv1, ' '));
	while (*(splits++))
		stacks->a->size++;
	splits -= (stacks->a->size + 1);
	if (!check_args(stacks->a->size, (const char **)splits))
		return (0);
	malloc_stacks_tab_and_set_size(stacks, stacks->a->size + 1);
	while (splits[j] != 0)
	{
		stacks->a->tab[j] = ft_atoi(splits[j]);
		free(splits[j]);
		j++;
	}
	free(splits);
	return (1);
}

static void	error(void)
{
	write(2, "Error\n", ft_strlen("Error\n"));
}

int	main(int argc, char const *argv[])
{
	t_stacks_pair	*stacks;
	t_stack			*a;
	t_stack			*b;

	stacks = init_stacks_pair(&a, &b);
	if (!stacks)
		return (error(), 0);
	if (argc > 2)
	{
		if (!check_args(argc - 1, argv +1))
			return (error(), 0);
		malloc_stacks_tab_and_set_size(stacks, argc);
		while (argc > 1)
		{
			a->tab[argc - 2] = ft_atoi(argv[argc - 1]);
			argc--;
			a->size++;
		}
	}
	else if (argc == 2)
		if (!handle_mono_arg(stacks, argv[1]))
			return (error(), 0);
	if (!sort_stacks(stacks) && stacks->commands_tab_size > 1 && argc > 1)
		return (ft_printf("Error\n"));
	return (print_commands(stacks), ft_freestacks(stacks), 0);
}

/*

Mallocated : 
	stacks :   0x0000000100300050
	stacks a : 0x0000000100300070
	stacks b : 0x0000000100300080
Mallocated :
    stacks a tab : 0x00000001006015e0
    stacks b tab : 0x00000001006015e0
depth : 0
depth : 1
freeing : 0x0000000100600460 (tab : 0x0000000100600450, pos : 0)
depth : 2
depth : 3
freeing : 0x0000000100100360 (tab : 0x0000000100601400, pos : 2)
freeing : 0x0000000100600450 (tab : 0x0000000100601400, pos : 1)
freeing : 0x0000000100601110 (tab : 0x0000000100601400, pos : 0)
depth : 4
freeing : 0x0000000100201c80 (tab : 0x0000000100601350, pos : 5)
freeing : 0x0000000100201c70 (tab : 0x0000000100601350, pos : 4)
freeing : 0x0000000100601110 (tab : 0x0000000100601350, pos : 3)
freeing : 0x0000000100600180 (tab : 0x0000000100601350, pos : 2)
freeing : 0x0000000100601120 (tab : 0x0000000100601350, pos : 1)
freeing : 0x0000000100600460 (tab : 0x0000000100601350, pos : 0)
4
pb
ra
4
pa
freeing : 0x0000000100601250 (tab : 0x0000000100200540, pos : 10)
freeing : 0x0000000100601120 (tab : 0x0000000100200540, pos : 9)
freeing : 0x0000000100601110 (tab : 0x0000000100200540, pos : 8)

*/