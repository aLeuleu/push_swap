/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:40:04 by alevra            #+#    #+#             */
/*   Updated: 2022/12/17 11:37:23 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_radix_max_index(t_stack *a);
static void	radix_sort_by_index(int index, t_stack *a, t_stack *b);


int	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	index;
	
	index = get_radix_max_index(a);
	i = 0;
	while (i < index)
		radix_sort_by_index(i++, a, b);
	return (0);
}


static void	radix_sort_by_index(int index, t_stack *a, t_stack *b)
{
	int	i;
	int	size;

	//ft_printf("\n\tindex : %d\n\n", index);
	size = a->size;
	i = 0;
	while (i < size)
	{
		if ((a->tab[0] >> index) % 2 == 0)
		{
			execute_command("pb", a, b);
			//show_stacks(A, B); // debug
		}
		else
		{
			execute_command("ra", a ,b);
			//show_stacks(A, B); // debug
		}
		i++;
	}
	while (b->size)
	{
		execute_command("pa", a, b);
	}
}

static int	get_radix_max_index(t_stack *a)
{
	size_t	i;
	int	max;

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
