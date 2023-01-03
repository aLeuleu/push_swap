/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:46:51 by alevra            #+#    #+#             */
/*   Updated: 2023/01/03 17:40:22 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	show_stack_row(t_stack *a, size_t row);

void	show_stacks(t_stacks_pair *stacks)
{
	size_t	top_row;
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	top_row = a->size;
	if (b->size > top_row)
		top_row = b->size;
	ft_printf("\n");
	while (top_row)
	{
		show_stack_row(a, top_row);
		show_stack_row(b, top_row);
		ft_printf("\n");
		top_row--;
	}
	ft_printf("\tA\tB\n");
}

static void	show_stack_row(t_stack *a, size_t row)
{
	if (a->size >= row)
		ft_printf("\t%d", a->tab[a->size - row]);
	else
		ft_printf("\t.");
}
