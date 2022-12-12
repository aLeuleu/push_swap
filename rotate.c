/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:43:04 by alevra            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/15 21:39:08 by alevra           ###   ########lyon.fr   */
=======
/*   Updated: 2022/12/12 14:12:46 by alevra           ###   ########lyon.fr   */
>>>>>>> e04df7b (refactoring)
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
<<<<<<< HEAD
	//ft_printf("\trotate\n\tsize of stack : %d\n\tlast : %d\n\ttmp : %d\n",A->size, last, tmp);
	while (i < last)
	{
		//ft_printf("\ti : %d\n", i);
=======
	while (i < last)
	{
>>>>>>> e04df7b (refactoring)
		A->tab[i] = A->tab[i + 1];
		i++;
	}
	A->tab[last] = tmp;
}

<<<<<<< HEAD
void	rotate_reverse(t_stack *a)
=======
void	rotate_reverse(t_stack *A)
>>>>>>> e04df7b (refactoring)
{
	int	last;
	int	tmp;
	int	i;

	i = 0;
<<<<<<< HEAD
	last = a->size;
	tmp = a->tab[last - 1];
	while (i < last)
	{
		a->tab[last - i] = a->tab[last - i - 1];
		i++;
	}
	a->tab[0] = tmp;
=======
	last = A->size - 1;
	tmp = A->tab[last];
	while (i < last)
	{
		A->tab[last - i] = A->tab[last - i - 1];
		i++;
	}
	A->tab[0] = tmp;
>>>>>>> e04df7b (refactoring)
}