/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:08:51 by alevra            #+#    #+#             */
/*   Updated: 2022/12/17 14:18:48 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_rank(t_stack *A, int index);
static void	replace_values_by_rank(t_stack *A);
static void ft_freestacks(t_stack *a, t_stack *b);
static void	ft_freestack(t_stack *a);

static void	init_stack(t_stack **a, t_stack **b)
{
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	(*b)->size = 0;
	(*a)->size = 0;
}

static int	malloc_stack_tab_and_set_size(t_stack *a, t_stack *b, int value)
{
	a->tab = malloc(sizeof(int) * value);
	b->tab = malloc(sizeof(int) * value);
	a->size = value - 1;
	a->tab[a->size] = 9999;
	return (1);
}

static void	handle_mono_arg(t_stack *a, t_stack *b, const char *argv1)
{
	int		j;
	char	**splits;

	j = 0;
	splits = (ft_split(argv1, ' '));
	while (*splits) // a ameliorer comme ci dessous
	{
		a->size++;
		splits++;
	}
	/* 
	while (*(splits++))
		a->size++;
	 */
	splits -= a->size;
	malloc_stack_tab_and_set_size(a, b, a->size + 1);
	while (splits[j] != 0)
	{
		a->tab[j] = ft_atoi(splits[j]);
		free(splits[j]);
		j++;
	}
	free(splits);
}

int	main(int argc, char const *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return(0);
	init_stack(&a, &b);
	if (argc > 2 && malloc_stack_tab_and_set_size(a, b, argc))
		while (argc > 1)
		{
			a->tab[argc - 2] = ft_atoi(argv[argc - 1]);
			argc--;
		}
	else if (argc == 2)
		handle_mono_arg(a, b, argv[1]);
	if (is_stack_reverse_sorted(a))
		return (0);
	replace_values_by_rank(a);
	if (a->size < 10)
		short_sort(a, b);
	else
		radix_sort(a, b);
	ft_freestacks(a, b);
	return (0);
}

static void ft_freestacks(t_stack *a, t_stack *b)
{
	ft_freestack(a);
	ft_freestack(b);
}

static void	ft_freestack(t_stack *a)
{
	free (a->tab);
	free(a);
}

static void	replace_values_by_rank(t_stack *A)
{
	int		new_tab[A->size];
	size_t	i;
	i = 0;
	while (i < (A->size))
	{
		new_tab[i] = get_rank(A, i);
		i++;
	}
	i = 0;
	while (i < (A->size))
	{
		A->tab[i] = new_tab[i];
		i++;
	}
}

static int	get_rank(t_stack *A, int index)
{
	int	nb;
	int	res;
	size_t	i;

	nb = A->tab[index];
	i = 0;
	res = 0;
	while (i < (A->size))
	{
		if (A->tab[i] < nb)
			res++;
		i++;
	}
	return (res);
}

int	is_stack_reverse_sorted(t_stack *A)
{
	size_t	i;
	int		is_rsorted;

	i = 0;
	is_rsorted = 1;
	while (i + 1 < A->size - 1)
	{
		if (A->tab[i + 1] > A->tab[i])
			is_rsorted = 0;
		i++;
	}
	return (is_rsorted);
}

int	is_stack_sorted(t_stack *A)
{
	size_t	i;
	int		is_sorted;

	i = 0;
	is_sorted = 1;
	if (A->size == 0)
		return (1);
	while (i + 1 < A->size - 1)
	{
		if (A->tab[i + 1] < A->tab[i])
			is_sorted = 0;
		i++;
	}
	return (is_sorted);
}
