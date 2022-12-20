/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:08:51 by alevra            #+#    #+#             */
/*   Updated: 2022/12/20 22:39:04 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_mono_arg(t_stacks_pair *stacks, const char *argv1)
{
	int		j;
	char	**splits;

	j = 0;
	splits = (ft_split(argv1, ' '));
	while (*(splits++))
		stacks->a->size++;
	splits -= stacks->a->size;
	malloc_stacks_tab_and_set_size(stacks, stacks->a->size + 1);
	while (splits[j] != 0)
	{
		stacks->a->tab[j] = ft_atoi(splits[j]);
		free(splits[j]);
		j++;
	}
	free(splits);
}

static int	sort_stacks(t_stacks_pair *stacks)
{
	if (is_stack_sorted(stacks->a))
		return (1);
	replace_values_by_rank(stacks->a);
	if (stacks->a->size < 10)
		short_sort(stacks);
	else
		radix_sort(stacks);
	return (1);
}

static void	opti_and_print_commands(t_stacks_pair *stacks)
{
	size_t	i;

	//opti command (not implemented yet)
	i = 0;
	// show_stacks(stacks);
	if (stacks)
	{
		while (ft_strncmp(stacks->commands[i], "END", 4))
		{
			ft_printf(stacks->commands[i]);
			ft_printf("\n");
			i++;
		}
	}
}

int	main(int argc, char const *argv[])
{
	t_stacks_pair	*stacks;
	t_stack			*a;
	t_stack			*b;

	if (argc == 1)
		return (0);
	stacks = init_stacks_pair(&a, &b);
	if (!stacks)
		return (ft_printf("Error\n"));
	if (argc > 2 && malloc_stacks_tab_and_set_size(stacks, argc))
	{
		while (argc > 1)
		{
			a->tab[argc - 2] = ft_atoi(argv[argc - 1]);
			argc--;
			a->size++;
		}
		a->tab[stacks->a->size] = 9999;
	}
	else if (argc == 2)
		handle_mono_arg(stacks, argv[1]);
	if (!sort_stacks(stacks))
		return (ft_printf("Error\n"));
	opti_and_print_commands(stacks);
	return (ft_freestacks(stacks), 0);
}
