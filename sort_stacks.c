/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:16:57 by alevra            #+#    #+#             */
/*   Updated: 2023/01/05 07:07:11 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stacks(t_stacks_pair *stacks)
{
	if (is_stack_sorted(stacks->a))
		return (1);
	if (!replace_values_by_rank(stacks->a))
		return (0);
	if (stacks->a->size < 55)
		select_sort(stacks);
	else
		radix_sort(stacks);
	return (1);
}
