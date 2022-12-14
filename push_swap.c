/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:08:51 by alevra            #+#    #+#             */
/*   Updated: 2022/12/13 19:34:30 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	*user_input;
	
	a = malloc(sizeof(int *) + sizeof(size_t));
	a->tab = malloc(sizeof(int) * argc - 1);
	b = malloc(sizeof(int *) + sizeof(size_t));
	b->tab = malloc(sizeof(int) * argc - 1);
	b->size = 0;
	a->size = argc - 1;
	if (argc > 1)
	{
		while (argc > 1)
		{
			a->tab[argc - 2] = atoi(argv[argc - 1]);
			argc--;
		}
	}
	user_input = malloc(sizeof(char) * 3);
	show_stacks(a, b);
	if (is_stack_sorted(a))
		return (0);
	i = 0;
	if (a->size < 5)
		short_sort(a,b);
	else
		radix_sort(a , b);
	show_stacks(a, b);
	printf("Stack sorted : %d\n", is_stack_sorted(a));
	// read(1, user_input, 3);
	return (0);
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
