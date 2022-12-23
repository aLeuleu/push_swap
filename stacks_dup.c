/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:15:44 by alevra            #+#    #+#             */
/*   Updated: 2022/12/23 17:33:18 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		stack_dup(t_stack *src, t_stack *dest);

t_stacks_pair	*stacks_dup(t_stacks_pair *src)
{
	t_stacks_pair	*dest;
	t_stack			*a;
	t_stack			*b;

	dest = init_stacks_pair(&a, &b);
	if (!dest)
		return (NULL);
	if (!malloc_stacks_tab_and_set_size(dest, src->a->size + src->b->size + 1))
		return (ft_freestacks(dest), NULL);
	stack_dup(src->a, dest->a);
	stack_dup(src->b, dest->b);
	return (dest);
}

static int	stack_dup(t_stack *src, t_stack *dest)
{
	size_t	i;

	i = 0;
	dest->size = src->size;
	while (i < src->size)
	{
		dest->tab[i] = src->tab[i];
		i++;
	}
	dest->tab[dest->size] = 9999;
	return (1);
}
