/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:40:04 by alevra            #+#    #+#             */
/*   Updated: 2022/12/12 17:47:49 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_radix_max_index(t_stack *A);
static void	radix_sort_by_index(int index, t_stack *A, t_stack *B);
static int	get_rank(t_stack *A, int index);
static		replace_values_by_rank(t_stack *A);

int	radix_sort(t_stack *A, t_stack *B)
{
	int	i;
	int	index;

	// replace_values_by_rank(A);
	index = get_radix_max_index(A);
	i = 0;
	while (i < index)
	{
		radix_sort_by_index(i++, A, B);
		show_stacks(A, B);
	}
	show_stacks(A, B);
	while (B->size)
		execute_command("pa", A, B);
}

static	replace_values_by_rank(t_stack *A)
{
	int	*new_tab[A->size];
	int	i;

	i = 0;
	while (i < (A->size))
	{
		new_tab[i] = get_rank(A, i);
		i++;
	}
}

static int	get_rank(t_stack *A, int index)
{
	int	nb;
	int	res;
	int	i;

	nb = A->tab[index];
	i = 0;
	while (i < (A->size))
		if (A->tab[i++] < nb)
			res++;
	return (res);
}

static void	radix_sort_by_index(int index, t_stack *A, t_stack *B)
{
	int	i;

	i = 0;
	while (i < A->size)
		// if bit == 0, push the whole byte in b
		if ((A->tab[i++] >> index) % 2 == 0)
			execute_command("pb", A, B);
	
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
