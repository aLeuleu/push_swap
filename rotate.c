/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:43:04 by alevra            #+#    #+#             */
/*   Updated: 2023/01/04 18:12:16 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *a)
{
	int	last;
	int	tmp;
	int	i;

	i = 0;
	last = a->size - 1;
	tmp = a->tab[0];
	while (i < last)
	{
		a->tab[i] = a->tab[i + 1];
		i++;
	}
	a->tab[last] = tmp;
}

void	rotate_reverse(t_stack *a)
{
	int	last;
	int	tmp;
	int	i;

	i = 0;
	last = a->size;
	tmp = a->tab[last - 1];
	while (i < last)
	{
		a->tab[last - i] = a->tab[last - i - 1];
		i++;
	}
	a->tab[0] = tmp;
}
