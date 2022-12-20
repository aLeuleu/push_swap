/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:08:51 by alevra            #+#    #+#             */
/*   Updated: 2022/12/20 15:01:09 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				*tab;
	size_t			size;
}					t_stack;

typedef struct s_stacks_pair
{
	t_stack			*a;
	t_stack			*b;
	char			**commands; //coherent whith execute_command
	size_t			commands_tab_size;
}					t_stacks_pair;

typedef struct s_node
{
	struct s_node	*parent;
	t_stacks_pair	*stacks;
	size_t			depth;
}					t_node;

# ifndef NB_COMMANDS
#  define NB_COMMANDS 11
# endif


void			push(t_stack *a, t_stack *b);
void			show_stacks(t_stacks_pair *stacks);
int				execute_command(const char *command, t_stacks_pair *old_stacks,
		t_stacks_pair **new_stacks, size_t depth);
void			swap(t_stack *A);
void			rotate(t_stack *A);
void			rotate_reverse(t_stack *A);
void			short_sort(t_stacks_pair *stacks);
int				radix_sort(t_stacks_pair *stacks);
int				get_max_stack(t_stack *A);
int				get_max_pos_stack(t_stack *A);
int				get_min_stack(t_stack *A);
int				get_min_pos_stack(t_stack *A);
int				is_stack_reverse_sorted(t_stack *A);
int				is_stack_sorted(t_stack *A);
void			ft_freestacks(t_stacks_pair *stacks);
void			ft_freestack(t_stack *a);
void			replace_values_by_rank(t_stack *A);
t_stacks_pair	*stacks_dup(t_stacks_pair *src);
t_stacks_pair	*init_stacks_pair(t_stack	**a, t_stack	**b);
int				malloc_stacks_tab_and_set_size(t_stacks_pair *stacks, int value);
#endif