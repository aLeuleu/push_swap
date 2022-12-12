/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:06:49 by alevra            #+#    #+#             */
/*   Updated: 2022/12/12 16:07:29 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_stack(t_stack *A)
{
	int	i;
	int	max;

	max = A->tab[0];
	i = 1;
	while (i < (A->size))
	{
		if (A->tab[i] > max)
			max = A->tab[i];
		i++;
	}
	return (max);
}

int	get_max_pos_stack(t_stack *A)
{
	int	i;
	int	max;
	int	pos;

	max = A->tab[0];
	pos = 0;
	i = 1;
	while (i < (A->size))
	{
		if (A->tab[i] > max)
		{
			max = A->tab[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	get_min_stack(t_stack *A)
{
	int	i;
	int	min;

	min = A->tab[0];
	i = 1;
	while (i < (A->size))
	{
		if (A->tab[i] < min)
			min = A->tab[i];
		i++;
	}
	return (min);
}

int	get_min_pos_stack(t_stack *A)
{
	int	i;
	int	min;
	int	pos;

	min = A->tab[0];
	pos = 0;
	i = 1;
	while (i < (A->size))
	{
		if (A->tab[i] < min)
		{
			min = A->tab[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}
