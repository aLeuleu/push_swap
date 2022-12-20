/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks_pair.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:07:51 by alevra            #+#    #+#             */
/*   Updated: 2022/12/20 15:08:32 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_stacks_pair	*init_stacks_pair(t_stack **a, t_stack	**b)
{
	t_stacks_pair	*res;

	res = malloc(sizeof(t_stacks_pair));
	*a = malloc(sizeof(t_stack));
	*b = malloc(sizeof(t_stack));
	(*b)->size = 0;
	(*a)->size = 0;
	res->a = *a;
	res->b = *b;
	if (!res || !res->a || !res->b)
	{
		if (res)
		{
			if (res->a)
				free(res->a);
			if (res->b)
				free(res->b);
			free(res);
		}
		return (NULL);
	}
	res->commands = NULL;
	res->commands_tab_size = 0;
	return (res);
}
