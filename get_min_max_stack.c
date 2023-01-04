/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:06:49 by alevra            #+#    #+#             */
/*   Updated: 2023/01/04 18:11:16 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *a)
{
	size_t	i;
	int		max;

	max = a->tab[0];
	i = 1;
	while (i < (a->size))
	{
		if (a->tab[i] > max)
			max = a->tab[i];
		i++;
	}
	return (max);
}

size_t	get_max_pos_stack(t_stack *a)
{
	size_t	i;
	int		max;
	size_t	pos;

	max = a->tab[0];
	pos = 0;
	i = 1;
	while (i < (a->size))
	{
		if (a->tab[i] > max)
		{
			max = a->tab[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	get_min(t_stack *a)
{
	size_t	i;
	int		min;

	min = a->tab[0];
	i = 1;
	while (i < (a->size))
	{
		if (a->tab[i] < min)
			min = a->tab[i];
		i++;
	}
	return (min);
}

size_t	get_min_pos_stack(t_stack *a)
{
	size_t	i;
	int		min;
	size_t	pos;

	min = a->tab[0];
	pos = 0;
	i = 1;
	while (i < (a->size))
	{
		if (a->tab[i] < min)
		{
			min = a->tab[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}
