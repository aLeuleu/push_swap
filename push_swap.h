/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:08:51 by alevra            #+#    #+#             */
/*   Updated: 2022/12/17 11:37:22 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_stack
{
	int		*tab;
	size_t	size;
}			t_stack;

void		push(t_stack *A, t_stack *B);
void		show_stacks(t_stack *A, t_stack *B);
int			execute_command(const char *user_input, t_stack *A, t_stack *B);
void		swap(t_stack *A);
void		rotate(t_stack *A);
void		rotate_reverse(t_stack *A);
void		short_sort(t_stack *a, t_stack *b);
int			radix_sort(t_stack *A, t_stack *B);
int			get_max_stack(t_stack *A);
int			get_max_pos_stack(t_stack *A);
int			get_min_stack(t_stack *A);
int			get_min_pos_stack(t_stack *A);
int			is_stack_reverse_sorted(t_stack *A);
int			is_stack_sorted(t_stack *A);
