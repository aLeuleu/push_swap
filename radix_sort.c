/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:40:04 by alevra            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/15 21:31:59 by alevra           ###   ########lyon.fr   */
=======
/*   Updated: 2022/12/12 20:13:17 by alevra           ###   ########lyon.fr   */
>>>>>>> e04df7b (refactoring)
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
static int	get_radix_max_index(t_stack *a);
static void	radix_sort_by_index(int index, t_stack *a, t_stack *b);


int	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	index;
	
	index = get_radix_max_index(a);
	i = 0;
	while (i < index)
		radix_sort_by_index(i++, a, b);
	return (0);
}


static void	radix_sort_by_index(int index, t_stack *a, t_stack *b)
{
	int	i;
	int	size;

	//ft_printf("\n\tindex : %d\n\n", index);
	size = a->size;
	i = 0;
	while (i < size)
	{
		if ((a->tab[0] >> index) % 2 == 0)
		{
			execute_command("pb", a, b);
			//show_stacks(A, B); // debug
		}
		else
		{
			execute_command("ra", a ,b);
			//show_stacks(A, B); // debug
		}
		i++;
	}
	while (b->size)
	{
		execute_command("pa", a, b);
	}
}

static int	get_radix_max_index(t_stack *a)
{
	size_t	i;
=======
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

	i = 0;
	while (i < A->size)
		// if bit == 0, push the whole byte in b
		if ((A->tab[i++] >> index) % 2 == 0)
			execute_command("pb", A, B);
	
}

static int	get_radix_max_index(t_stack *A)
{
	int	i;
>>>>>>> e04df7b (refactoring)
	int	max;

	max = 0;
	i = 0;
<<<<<<< HEAD
	while (i < (a->size))
	{
		while ((a->tab[i] >> max) != 0)
=======
	while (i < (A->size))
	{
		while ((A->tab[i] >> max) != 0)
>>>>>>> e04df7b (refactoring)
			max++;
		i++;
	}
	return (max);
}
