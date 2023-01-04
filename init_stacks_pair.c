/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks_pair.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:07:51 by alevra            #+#    #+#             */
/*   Updated: 2023/01/04 04:59:37 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*malloc_stack_and_init(void);

t_stacks_pair	*init_stacks_pair(t_stack **a, t_stack	**b)
{
	t_stacks_pair	*res;

	res = malloc(sizeof(t_stacks_pair));
	if (!res)
		return (NULL);
	*a = malloc_stack_and_init();
	if (!a)
		return (free(res), NULL);
	*b = malloc_stack_and_init();
	if (!b)
		return (free(res), free(a), NULL);
	res->a = *a;
	res->b = *b;
	res->commands = NULL;
	res->commands_tab_size = 0;
	return (res);
}

static t_stack	*malloc_stack_and_init(void)
{
	t_stack	*a;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->tab = NULL;
	a->size = 0;
	return (a);
}
