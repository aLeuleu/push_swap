/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:45:33 by alevra            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/15 15:48:07 by alevra           ###   ########lyon.fr   */
=======
/*   Updated: 2022/12/12 15:56:00 by alevra           ###   ########lyon.fr   */
>>>>>>> e04df7b (refactoring)
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_stack *a, t_stack *b)
{
<<<<<<< HEAD
	size_t min_pos;
	int	min;
	
	while (a->size != 0)
	{
		min = get_min_stack(a);
		min_pos = get_min_pos_stack(a);
=======
	int min_pos;
	int	min;
	
	printf("short sort\n"); //debug
	while (a->size != 0 || !is_stack_sorted(a))
	{
		min = get_min_stack(a);
		min_pos = get_min_pos_stack(a);
		if (a->tab[0] > a->tab[1])
			execute_command("sa", a ,b);
		min_pos = get_min_pos_stack(a);
>>>>>>> e04df7b (refactoring)
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
<<<<<<< HEAD
		//show_stacks(a, b);
	}
	while (b->size > 0)
		execute_command("pa", a, b);
=======
	}
	while (b->size > 0)
		printf("%d ", execute_command("pa", a, b));
>>>>>>> e04df7b (refactoring)
}