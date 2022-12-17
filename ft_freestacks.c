/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:55:01 by alevra            #+#    #+#             */
/*   Updated: 2022/12/17 19:28:12 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freestacks(t_stacks_pair *stacks)
{
	if (stacks->a)
		ft_freestack(stacks->a);
	if (stacks->b)
		ft_freestack(stacks->b);
	free(stacks);
}

void	ft_freestack(t_stack *a)
{
	if (a->tab)
		free(a->tab);
	free(a);
}
