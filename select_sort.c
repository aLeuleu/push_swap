/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:45:33 by alevra            #+#    #+#             */
/*   Updated: 2022/12/22 14:39:56 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sort(t_stacks_pair *stacks)
{
	size_t	min_pos;
	int		min;
	t_stack	*a;
	t_stack	*b;
	size_t		depth;

	depth=0;
	a = stacks->a;
	b = stacks->b;
	show_stacks(stacks);
	while (a->size != 0)
	{
		min = get_min_stack(a);
		min_pos = get_min_pos_stack(a);
		if (a->tab[0] == get_max_stack(a) && a->tab[a->size ] == min)
			execute_command("rra", stacks, &stacks, depth++);
		if (a->size >= 3 && a->tab[0] > a->tab[1])
			execute_command("sa", stacks, &stacks, depth++);
		if (min_pos + 1 < (a->size) / 2)
			while (a->tab[0] != min)
				execute_command("ra", stacks, &stacks, depth++);
		else
			while (a->tab[0] != min)
				execute_command("rra", stacks, &stacks, depth++);
		if (is_stack_sorted(stacks->a))
			break ;
		else
			execute_command("pb", stacks, &stacks, depth++);
	}
	while (b->size > 0)
		execute_command("pa", stacks, &stacks, depth++);
	execute_command("END", stacks, &stacks, depth++);
}
