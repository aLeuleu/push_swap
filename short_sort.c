/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:45:33 by alevra            #+#    #+#             */
/*   Updated: 2022/12/21 00:08:40 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_stacks_pair *stacks)
{
	size_t	min_pos;
	int		min;
	t_stack	*a;
	t_stack	*b;
	size_t		depth;

	depth=0;
	a = stacks->a;
	b = stacks->b;
	while (a->size != 0)
	{
		min = get_min_stack(a);
		min_pos = get_min_pos_stack(a);
		if (min_pos + 1 < (a->size) / 2)
			while (a->tab[0] != min)
				execute_command("ra", stacks, &stacks, depth++);
		else
			while (a->tab[0] != min)
				execute_command("rra", stacks, &stacks, depth++);
		execute_command("pb", stacks, &stacks, depth++);
	}
	while (b->size > 0)
		execute_command("pa", stacks, &stacks, depth++);
	execute_command("END", stacks, &stacks, depth++);
}

void	quicksort_stacks(t_stacks_pair *stacks)
{
	size_t		pivot_pos;
	int			pivot;
	size_t		depth;
	int			i;
	int			

	i = 0;
	depth = 0;
	pivot_pos = stacks->a->size / 2;
	pivot = stacks->a->tab[pivot_pos];
	while (i < stacks->a->size)
	{
		if (stacks->a->tab[i] > pivot)
			
	}
	execute_command("END", stacks, &stacks, depth++);
	execute_command("END", stacks, &stacks, depth++);
}