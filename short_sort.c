/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:45:33 by alevra            #+#    #+#             */
/*   Updated: 2022/12/14 15:24:40 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_stack *a, t_stack *b)
{
	int min_pos;
	int	min;
	
	while (a->size != 0)
	{
		min = get_min_stack(a);
		min_pos = get_min_pos_stack(a);
		if (a->tab[0] > a->tab[1])
			execute_command("sa", a ,b);
		min_pos = get_min_pos_stack(a);
		if (min_pos + 1 < (a->size) / 2)
		{
			while (a->tab[0] != min)
				execute_command("ra", a, b);
		}
		else
		{
			while (a->tab[0] != min)
				execute_command("rra", a, b);
		}
		execute_command("pb", a, b);
	}
	while (b->size > 0)
		execute_command("pa", a, b);
}