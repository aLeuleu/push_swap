/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:08:51 by alevra            #+#    #+#             */
/*   Updated: 2022/12/08 02:48:43 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
	int		*tab;
	size_t	size;	
}	t_stack;

void	push(t_stack *A, t_stack *B);
void	show_stack_row(t_stack *A, int row);
void	show_stacks(t_stack *A, t_stack *B);
int		execute_command(char *user_input, t_stack *A, t_stack *B);
void	swap(t_stack *A);
void	rotate(t_stack *A);
void	rotate_reverse(t_stack *A);
void	short_sort(t_stack *a, t_stack* b);
int		get_radix_max_index(t_stack* A);

int	main(int argc, char const *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	*user_input;
	int		min;
	int		min_pos;
	int		radix_index;

	i = 1;
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
	printf("Radix max index : %d\n", get_radix_max_index(a));
	if (is_stack_sorted(a))
		return (0);
	i = 0;
	if (a->size < 10)
		short_sort(a,b);
	else
	{
		while(i < radix_index)
			radix_sort_index(i++, a, b);
	}
	show_stacks(a, b);
	printf("Stack sorted : %d\n", is_stack_sorted(a));
	read(1, user_input, 3);
	return (0);
}

int	radix_sort_index(int index, t_stack *A, t_stack *B)
{
	int	i;

	i = 0;
	while(i < A->size)
		// if bit == 0, push the whole number in b 
		if ((A->tab[i++] >> index)%2 == 0)
			execute_command("pb", A, B);
	while(B->size)
		execute_command("pa", A, B);
}

int get_radix_max_index(t_stack* A)
{
	int	i;
	int	max;

	max =0;
	i = 0;
	while (i < (A->size))
	{
		while ((A->tab[i] >> max) != 0)
			max++;
		i++;
	}
	return (max);
}

void	short_sort(t_stack *a, t_stack *b)
{
	int min_pos;
	int	min;
	
	printf("short sort\n"); //debug
	while (a->size != 0 && !is_stack_sorted(a))
	{
		min = get_min_stack(a);
		min_pos = get_min_pos_stack(a);
		if (a->tab[0] > a->tab[1])
			execute_command("sa", a ,b);
		min_pos = get_min_pos_stack(a);
		if (min_pos + 1 < (a->size) / 2)
		{
			while (a->tab[0] != min)
				execute_command("ra", a, b);
		}
		else
		{
			while (a->tab[0] != min)
				execute_command("rra", a, b);
		}
		execute_command("pb", a, b);
	}
	while (b->size > 0)
		printf("%d ", execute_command("pa", a, b));
}

int	get_max_stack(t_stack *A)
{
	int	i;
	int	max;

	max = A->tab[0];
	i = 1;
	while (i < (A->size))
	{
		if (A->tab[i] > max)
			max = A->tab[i];
		i++;
	}
	return (max);
}

int	get_max_pos_stack(t_stack *A)
{
	int	i;
	int	max;
	int	pos;

	max = A->tab[0];
	pos = 0;
	i = 1;
	while (i < (A->size))
	{
		if (A->tab[i] > max)
		{
			max = A->tab[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	get_min_stack(t_stack *A)
{
	int	i;
	int	min;

	min = A->tab[0];
	i = 1;
	while (i < (A->size))
	{
		if (A->tab[i] < min)
			min = A->tab[i];
		i++;
	}
	return (min);
}

int	get_min_pos_stack(t_stack *A)
{
	int	i;
	int	min;
	int	pos;

	min = A->tab[0];
	pos = 0;
	i = 1;
	while (i < (A->size))
	{
		if (A->tab[i] < min)
		{
			min = A->tab[i];
			pos = i;
		}
		i++;
	}
	return (pos);
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
	while (i + 1 < A->size - 1)
	{
		if (A->tab[i + 1] < A->tab[i])
			is_sorted = 0;
		i++;
	}
	return (is_sorted);
}

void	show_stacks(t_stack *A, t_stack *B)
{
	int	top_row;

	top_row = A->size;
	if (B->size > top_row)
		top_row = B->size;
	printf("\n");
	while (top_row)
	{
		show_stack_row(A, top_row);
		show_stack_row(B, top_row);
		printf("\n");
		top_row--;
	}
	printf("\tA\tB\n");
}

void	show_stack_row(t_stack *A, int row)
{
	if (A->size >= row)
		printf("\t%d", A->tab[A->size - row ]);
	else
		printf("\t.");
}

int	execute_command(char *user_input, t_stack *A, t_stack *B)
{
	int			i;
	static int	nb_command;
	
	nb_command++;
	i = 0;
	printf(user_input);
	printf("\n");
	if (user_input[0] == 'p')
	{
		if (user_input[1] == 'a' && B->size)
			push(B, A);
		if (user_input[1] == 'b' && A->size)
			push(A, B);
	}
	if (user_input[0] == 's')
	{
		if (user_input[1] == 'a')
			swap(A);
		if (user_input[1] == 'b')
			swap(B);
		if (user_input[1] == 's')
		{
			swap(A);
			swap(B);
		}
	}
	if (user_input[0] == 'r')
	{
		if (user_input[1] == 'a')
			rotate(A);
		if (user_input[1] == 'b')
			rotate(B);
		if (user_input[1] == 'r' && user_input[2] != 'a' && user_input[2] != 'b' && user_input[2] != 'r') 
		{
			rotate(A);
			rotate(B);
		}
		if (user_input[1] == 'r')
		{
			if (user_input[2] == 'a')
				rotate_reverse(A);
			if (user_input[2] == 'b')
				rotate_reverse(B);
			if (user_input[2] == 'r')
			{
				rotate_reverse(A);
				rotate_reverse(B);
			}
		}
	}
	return (nb_command);
}

void	rotate(t_stack *A)
{
	int	last;
	int	tmp;
	int	i;

	i = 0;
	last = A->size - 1;
	tmp = A->tab[0];
	while (i < last)
	{
		A->tab[i] = A->tab[i + 1];
		i++;
	}
	A->tab[last] = tmp;
}

void	rotate_reverse(t_stack *A)
{
	int	last;
	int	tmp;
	int	i;

	i = 0;
	last = A->size - 1;
	tmp = A->tab[last];
	while (i < last)
	{
		A->tab[last - i] = A->tab[last - i - 1];
		i++;
	}
	A->tab[0] = tmp;
}

void	push(t_stack *A, t_stack *B)
{
	int	i;

	i = 1;
	B->size++;
	while (i < B->size)
	{
		B->tab[B->size - i] = B->tab[B->size - (i + 1)];
		i++;
	}
	i = 0;
	B->tab[0] = A->tab[0];
	while ((i+1) < A->size)
	{
		A->tab[i] = A->tab[i + 1];
		i++;
	}
	A->size--;
}

void	swap(t_stack *A)
{
	int	tmp;

	tmp = A->tab[0];
	A->tab[0] = A->tab[1];
	A->tab[1] = tmp;
}
