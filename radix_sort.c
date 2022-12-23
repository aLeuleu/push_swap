/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:40:04 by alevra            #+#    #+#             */
/*   Updated: 2022/12/23 17:35:47 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		get_radix_max_index(t_stack *a);
static size_t	radix_sort_by_index(int index, t_stacks_pair *stacks,
					size_t depth);

int	radix_sort(t_stacks_pair *stacks)
{
	int		i;
	int		index;
	t_stack	*a;
	size_t	depth;

	depth = 0;
	a = stacks->a;
	index = get_radix_max_index(a);
	i = 0;
	while (i < index)
		depth = radix_sort_by_index(i++, stacks, depth);
	execute_command("END", stacks, &stacks, depth++);
	return (0);
}

static size_t	radix_sort_by_index(int index, t_stacks_pair *stacks,
		size_t depth)
{
	int		i;
	int		size;
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	size = a->size;
	i = 0;
	while (i < size)
	{
		if ((a->tab[0] >> index) % 2 == 0)
			execute_command("pb", stacks, &stacks, depth++);
		else
			execute_command("ra", stacks, &stacks, depth++);
		i++;
	}
	while (b->size)
		execute_command("pa", stacks, &stacks, depth++);
	return (depth);
}

static int	get_radix_max_index(t_stack *a)
{
	size_t	i;
	int		max;

	max = 0;
	i = 0;
	while (i < (a->size))
	{
		while ((a->tab[i] >> max) != 0)
			max++;
		i++;
	}
	return (max);
}
