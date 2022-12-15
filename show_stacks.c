/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:46:51 by alevra            #+#    #+#             */
/*   Updated: 2022/12/15 02:35:37 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	show_stack_row(t_stack *A, int row);

void	show_stacks(t_stack *A, t_stack *B)
{
	int	top_row;

	top_row = A->size;
	if (B->size > top_row)
		top_row = B->size;
	ft_printf("\n");
	while (top_row)
	{
		show_stack_row(A, top_row);
		show_stack_row(B, top_row);
		printf("\n");
		top_row--;
	}
	ft_printf("\tA\tB\n");
}

static void	show_stack_row(t_stack *A, int row)
{
	if (A->size >= row)
	{
		ft_printf("\t%d", A->tab[A->size - row ]);
	}
	else
		ft_printf("\t.");
}