/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:08:51 by alevra            #+#    #+#             */
/*   Updated: 2022/12/14 19:27:44 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_rank(t_stack *A, int index);
static		replace_values_by_rank(t_stack *A);

int	main(int argc, char const *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	
	b->size = 0;
	a->size = 0;
	if (argc > 2)
	{
		a->tab = malloc(sizeof(int) * (argc - 1));
		b->tab = malloc(sizeof(int) * (argc - 1));
		while (argc > 1)
		{
			a->tab[argc - 2] = atoi(argv[argc - 1]);
			a->size++;
			argc--;
		}
	}
	else if (argc == 2)		//TODO refactor this shit
	{						//TODO mettre count words dans ma libft et malloc avec count-word
		char** char_tab = (ft_split(argv[1], ' '));
		int j = 0;

		a->tab = malloc(j);
		b->tab = malloc(j);
		while (char_tab[j] != 0)
		{
			a->tab[j] = 4;
			a->tab[j] = ft_atoi(char_tab[j]);
			a->size++;
			free(char_tab[j]);
			j++;
		}
		a->size--;
		free(char_tab);
	}
	//show_stacks(a , b);
	if (is_stack_sorted(a))
		return (0);
	i = 0;
	replace_values_by_rank(a);
	if (a->size < 10)
		short_sort(a,b);
	else
		radix_sort(a , b);
	//show_stacks(a, b);
	//ft_printf("Stack sorted : %d\n", is_stack_sorted(a));
	return (0);
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
	int	i;

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
