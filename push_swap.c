/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:08:51 by alevra            #+#    #+#             */
/*   Updated: 2022/12/17 19:34:43 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stacks_pair	*init_stack(t_stack **a, t_stack **b)
{
	t_stacks_pair	*res;

	res = malloc(sizeof(t_stacks_pair));
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	(*b)->size = 0;
	(*a)->size = 0;
	res->a = *a;
	res->b = *b;
	if (!res || !res->a || !res->b)
	{
		if (res)
		{
			if (res->a)
				free(res->a);
			if (res->b)
				free(res->b);
			free(res);
		}
		return (NULL);
	}
	return (res);
}

static int	malloc_stacks_tab_and_set_size(t_stacks_pair *stacks, int value)
{
	stacks->a->tab = malloc(sizeof(int) * value);
	if (!stacks->a->tab)
		return (0);
	stacks->b->tab = malloc(sizeof(int) * value);
	if (!stacks->b->tab)
		return (free(stacks->a->tab), 0);
	stacks->a->size = value - 1;
	stacks->a->tab[stacks->a->size] = 9999;
	return (1);
}

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

static void	sort_stacks(t_stacks_pair *stacks)
{
	if (is_stack_sorted(stacks->a))
		return ;
	replace_values_by_rank(stacks->a);
	if (stacks->a->size < 10)
		short_sort(stacks);
	else
		radix_sort(stacks);
}

int	main(int argc, char const *argv[])
{
	t_stacks_pair	*stacks;
	t_stack			*a;
	t_stack			*b;

	stacks = init_stack(&a, &b);
	if (argc == 1 || !stacks)
		return (0);
	if (argc > 2 && malloc_stacks_tab_and_set_size(stacks, argc))
	{
		while (argc > 1)
		{
			a->tab[argc - 2] = ft_atoi(argv[argc - 1]);
			argc--;
		}
	}
	else if (argc == 2)
		handle_mono_arg(stacks, argv[1]);
	sort_stacks(stacks);
	return (ft_freestacks(stacks), 0);
}
