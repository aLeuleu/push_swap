/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:45:33 by alevra            #+#    #+#             */
/*   Updated: 2022/12/23 17:32:44 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sort(t_stacks_pair *stacks)
{
	int			min;
	size_t		depth;

	depth = 0;
	while (stacks->a->size != 0)
	{
		min = get_min(stacks->a);
		if (stacks->a->tab[0] == get_max(stacks->a) && stacks->a->tab[1] == min)
			execute_command("ra", stacks, &stacks, depth++);
		if (stacks->a->tab[0] > stacks->a->tab[1])
			execute_command("sa", stacks, &stacks, depth++);
		if (get_min_pos_stack(stacks->a) + 1 < (stacks->a->size) / 2)
			while (stacks->a->tab[0] != min)
				execute_command("ra", stacks, &stacks, depth++);
		else
			while (stacks->a->tab[0] != min)
				execute_command("rra", stacks, &stacks, depth++);
		if (is_stack_sorted(stacks->a))
			break ;
		else
			execute_command("pb", stacks, &stacks, depth++);
	}
	while (stacks->b->size > 0)
		execute_command("pa", stacks, &stacks, depth++);
	execute_command("END", stacks, &stacks, depth++);
}
