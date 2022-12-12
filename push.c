/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:41:37 by alevra            #+#    #+#             */
/*   Updated: 2022/12/12 13:41:46 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *A, t_stack *B)
{
	int	i;

	i = 1;
	B->size++;
	while (i < B->size)
	{
		B->tab[B->size - i] = B->tab[B->size - (i + 1)];
		i++;
	}
	i = 0;
	B->tab[0] = A->tab[0];
	while ((i+1) < A->size)
	{
		A->tab[i] = A->tab[i + 1];
		i++;
	}
	A->size--;
}