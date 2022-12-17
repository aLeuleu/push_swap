/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:54:13 by alevra            #+#    #+#             */
/*   Updated: 2022/12/17 14:54:17 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_reverse_sorted(t_stack *A)
{
	size_t	i;
	int		is_rsorted;

	i = 0;
	is_rsorted = 1;
	while (i + 1 < A->size - 1)
	{
		if (A->tab[i + 1] > A->tab[i])
			is_rsorted = 0;
		i++;
	}
	return (is_rsorted);
}

int	is_stack_sorted(t_stack *A)
{
	size_t	i;
	int		is_sorted;

	i = 0;
	is_sorted = 1;
	if (A->size == 0)
		return (1);
	while (i + 1 < A->size - 1)
	{
		if (A->tab[i + 1] < A->tab[i])
			is_sorted = 0;
		i++;
	}
	return (is_sorted);
}
