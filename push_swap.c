/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:08:51 by alevra            #+#    #+#             */
/*   Updated: 2023/01/05 07:06:04 by alevra           ###   ########lyon.fr   */
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
	if (!sort_stacks(stacks) && argc > 1)
		return (ft_printf("Error\n"));
	return (ft_freestacks(stacks), 0);
}
