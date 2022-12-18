/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_stacks_tab_and_set_size.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:49:45 by alevra            #+#    #+#             */
/*   Updated: 2022/12/17 21:49:52 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	malloc_stacks_tab_and_set_size(t_stacks_pair *stacks, int value)
{
	stacks->a->tab = malloc(sizeof(int) * value);
	if (!stacks->a->tab)
		return (0);
	stacks->b->tab = malloc(sizeof(int) * value);
	if (!stacks->b->tab)
		return (free(stacks->a->tab), 0);
	return (1);
}