/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:40:04 by alevra            #+#    #+#             */
/*   Updated: 2022/12/15 04:03:42 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_radix_max_index(t_stack *A);
static void	radix_sort_by_index(int index, t_stack *A, t_stack *B);


int	radix_sort(t_stack *A, t_stack *B)
{
	int	i;
	int	index;
	
	index = get_radix_max_index(A);
	i = 0;
	while (i < index)
		radix_sort_by_index(i++, A, B);
	return (0);
}


static void	radix_sort_by_index(int index, t_stack *A, t_stack *B)
{
	int	i;
	int target;
	int	size;

	//ft_printf("\n\tindex : %d\n\n", index);
	size = A->size;
	i = 0;
	while (i < size)
	{
		if ((A->tab[0] >> index) % 2 == 0)
		{
			execute_command("pb", A, B);
			//show_stacks(A, B); // debug
		}
		else
		{
			execute_command("ra", A ,B);
			//show_stacks(A, B); // debug
		}
		i++;
	}
	while (B->size)
	{
		execute_command("pa", A, B);
	}
}

static int	get_radix_max_index(t_stack *A)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (i < (A->size))
	{
		while ((A->tab[i] >> max) != 0)
			max++;
		i++;
	}
	return (max);
}
