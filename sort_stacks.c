/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:16:57 by alevra            #+#    #+#             */
/*   Updated: 2022/12/23 17:17:10 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stacks(t_stacks_pair *stacks)
{
	if (is_stack_sorted(stacks->a))
		return (execute_command("END", stacks, &stacks, 0));
	replace_values_by_rank(stacks->a);
	if (stacks->a->size < 55)
		select_sort(stacks);
	else
		radix_sort(stacks);
	return (1);
}
