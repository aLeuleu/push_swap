/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:41:37 by alevra            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/15 15:41:27 by alevra           ###   ########lyon.fr   */
=======
/*   Updated: 2022/12/12 13:41:46 by alevra           ###   ########lyon.fr   */
>>>>>>> e04df7b (refactoring)
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
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
=======
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
>>>>>>> e04df7b (refactoring)
}