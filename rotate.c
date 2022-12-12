/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:43:04 by alevra            #+#    #+#             */
/*   Updated: 2022/12/12 14:12:46 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *A)
{
	int	last;
	int	tmp;
	int	i;

	i = 0;
	last = A->size - 1;
	tmp = A->tab[0];
	while (i < last)
	{
		A->tab[i] = A->tab[i + 1];
		i++;
	}
	A->tab[last] = tmp;
}

void	rotate_reverse(t_stack *A)
{
	int	last;
	int	tmp;
	int	i;

	i = 0;
	last = A->size - 1;
	tmp = A->tab[last];
	while (i < last)
	{
		A->tab[last - i] = A->tab[last - i - 1];
		i++;
	}
	A->tab[0] = tmp;
}