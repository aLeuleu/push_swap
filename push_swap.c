/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:08:51 by alevra            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/16 13:52:42 by alevra           ###   ########lyon.fr   */
=======
/*   Updated: 2022/12/12 21:10:46 by alevra           ###   ########lyon.fr   */
>>>>>>> e04df7b (refactoring)
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
<<<<<<< HEAD

static int	get_rank(t_stack *A, int index);
static void	replace_values_by_rank(t_stack *A);

// static void	handle_multi_arg(t_stack *a, t_stac *b, char const *argv[argc])

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

static void	handle_mono_arg(t_stack *a, t_stack *b, char *argv1)
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
=======
>>>>>>> e04df7b (refactoring)

int	main(int argc, char const *argv[])
{
	t_stack	*a;
	t_stack	*b;
<<<<<<< HEAD
=======
	int		i;
	char	*user_input;

    //debug
    ft_printf("%b\n", 1); // pad de padding ?
    return 0;
    //debug
>>>>>>> e04df7b (refactoring)

	init_stack(&a, &b);
	if (argc > 2 && malloc_stack_tab_and_set_size(a, b, argc))
		while (argc > 1)
<<<<<<< HEAD
			a->tab[(argc--) - 2] = ft_atoi(argv[argc - 1]);
	else if (argc == 2)
		handle_mono_arg(a, b, argv[1]);
	if (is_stack_reverse_sorted(a))
		return (0);
	replace_values_by_rank(a);
	if (a->size < 10)
		short_sort(a, b);
	else
		radix_sort(a, b);
	return (0);
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

=======
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

>>>>>>> e04df7b (refactoring)
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
