/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:40:04 by alevra            #+#    #+#             */
/*   Updated: 2022/12/14 14:03:30 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_radix_max_index(t_stack *A);
static void	radix_sort_by_index(int index, t_stack *A, t_stack *B);
static int	get_rank(t_stack *A, int index);
static		replace_values_by_rank(t_stack *A);

int	radix_sort(t_stack *A, t_stack *B)
{
	int	i;
	int	index;

	// replace_values_by_rank(A);
	index = get_radix_max_index(A);
	ft_printf("Max index : %d\n", index);
	i = 0;
	while (i < index)
	{
		radix_sort_by_index(i++, A, B);
		show_stacks(A, B);
	}
	show_stacks(A, B);
	while (B->size)
		execute_command("pa", A, B);
}

static	replace_values_by_rank(t_stack *A)
{
	int	new_tab[A->size];
	int	i;

	i = 0;
	while (i < (A->size))
	{
		new_tab[i] = get_rank(A, i);
		i++;
	}
    /* 
    i = 0;
    while (i < (A->size))
        A->tab[i] = new_tab[i];
     */
}

static int	get_rank(t_stack *A, int index)
{
	int	nb;
	int	res;
	int	i;

	nb = A->tab[index];
	i = 0;
	while (i < (A->size))
		if (A->tab[i++] < nb)
			res++;
	return (res);
}

static void	radix_sort_by_index(int index, t_stack *A, t_stack *B)
{
	int	i;
	int target;
	int	size;

	size = A->size;
	i = 0;
	ft_printf("sorting index : %d\n", index);
	while (i < size)
	{
		if ((A->tab[i] >> index) % 2 == 0)
		{
			target = A->tab[i];
			ft_printf("to push in b : %b - %d\n", target, target);
			while (A->tab[0] != target)
			{
				execute_command("ra", A ,B);
			}
			execute_command("pb", A, B);
			size -= (i + 1);
			i = -1;
		}
		else
			ft_printf("seems good to me : %b - %d\n", A->tab[i],A->tab[i]);
		i++;	
	}
	while (B->size)
		execute_command("pa", A, B);
}

static int	get_radix_max_index(t_stack *A)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (i < (A->size))
	{
		while ((A->tab[i] >> max) != 0)
			max++;
		i++;
	}
	return (max);
}
