/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:45:33 by alevra            #+#    #+#             */
/*   Updated: 2022/12/17 18:39:03 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_stacks_pair *stacks)
{
	size_t	min_pos;
	int		min;
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	while (a->size != 0)
	{
		min = get_min_stack(a);
		min_pos = get_min_pos_stack(a);
		if (min_pos + 1 < (a->size) / 2)
		{
			while (a->tab[0] != min)
				execute_command("ra", stacks);
		}
		else
		{
			while (a->tab[0] != min)
				execute_command("rra", stacks);
		}
		execute_command("pb", stacks);
	}
	while (b->size > 0)
		execute_command("pa", stacks);
}
