/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_values_by_rank.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:58:26 by alevra            #+#    #+#             */
/*   Updated: 2023/01/05 03:17:19 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_rank(t_stack *a, int index);

int	replace_values_by_rank(t_stack *a)
{
	int		*new_tab;
	size_t	i;

	i = 0;
	new_tab = malloc(sizeof(int) * a->size);
	if (!new_tab)
		return (0);
	while (i < (a->size))
	{
		new_tab[i] = get_rank(a, i);
		i++;
	}
	i = 0;
	while (i < (a->size))
	{
		a->tab[i] = new_tab[i];
		i++;
	}
	free(new_tab);
	return (1);
}

static int	get_rank(t_stack *a, int index)
{
	int		nb;
	int		res;
	size_t	i;

	nb = a->tab[index];
	i = 0;
	res = 0;
	while (i < (a->size))
	{
		if (a->tab[i] < nb)
			res++;
		i++;
	}
	return (res);
}
