/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:41:37 by alevra            #+#    #+#             */
/*   Updated: 2022/12/17 15:07:36 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *a, t_stack *b)
{
	size_t	i;

	i = 1;
	b->size++;
	while (i < b->size)
	{
		b->tab[b->size - i] = b->tab[b->size - (i + 1)];
		i++;
	}
	i = 0;
	b->tab[0] = a->tab[0];
	while ((i) < a->size)
	{
		a->tab[i] = a->tab[i + 1];
		i++;
	}
	a->tab[a->size] = 999;
	a->size--;
}
