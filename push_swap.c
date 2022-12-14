/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:08:51 by alevra            #+#    #+#             */
/*   Updated: 2022/12/14 17:30:19 by alevra           ###   ########lyon.fr   */
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
	char	*user_input;
	
	a = malloc(sizeof(int *) + sizeof(size_t));
	
	b = malloc(sizeof(int *) + sizeof(size_t));
	
	b->size = 0;
	a->size = 0;
	if (argc > 1)
	{
		a->size = (argc - 1);
		a->tab = malloc(sizeof(int) * (a->size));
		
		b->tab = malloc(sizeof(int) * argc - 1);
		while (argc > 1)
		{
			a->tab[(a->size - 1) - (argc - 2)] = atoi(argv[argc - 1]);
			argc--;
		}
	}
	if (argc == 1)		//TODO refactor this shit
	{
		char** char_tab = (ft_split(argv[1], ' '));
		int j = 0;
		
		while (char_tab[j] != 0)
			j++;
		a->size = j;
		while(--j > 0)
		{
			a->tab[j] = ft_atoi(char_tab[a->size - j]);
			free(char_tab[a->size - j]);
		}
		free(char_tab);
	}
	//show_stacks(a , b);
	user_input = malloc(sizeof(char) * 3); // jamais free ca ? mdr
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
	// read(1, user_input, 3);
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
