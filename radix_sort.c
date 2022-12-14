/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:40:04 by alevra            #+#    #+#             */
/*   Updated: 2022/12/14 17:04:37 by alevra           ###   ########lyon.fr   */
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
}


static void	radix_sort_by_index(int index, t_stack *A, t_stack *B)
{
	int	i;
	int target;
	int	size;

	size = A->size;
	i = 0;
	while (i < size)
	{
		if ((A->tab[i] >> index) % 2 == 0)
		{
			target = A->tab[i];
			while (A->tab[0] != target)
			{
				execute_command("ra", A ,B);
			}
			execute_command("pb", A, B);
			size -= (i + 1);
			i = -1;
		}
		i++;
	}
	while (B->size)
		execute_command("pa", A, B);
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
