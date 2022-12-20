/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks_pair.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:23:11 by alevra            #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2022/12/18 02:57:33 by alevra           ###   ########lyon.fr   */
=======
/*   Updated: 2022/12/19 13:56:21 by alevra           ###   ########lyon.fr   */
>>>>>>> 99823af (nodes && execute_commands returns stacks_pair *)
=======
/*   Updated: 2022/12/19 13:56:21 by alevra           ###   ########lyon.fr   */
>>>>>>> 99823af (nodes && execute_commands returns stacks_pair *)
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
	res->commands = NULL;
	res->commands_tab_size = 0;
>>>>>>> 99823af (nodes && execute_commands returns stacks_pair *)
=======
	res->commands = NULL;
	res->commands_tab_size = 0;
>>>>>>> 99823af (nodes && execute_commands returns stacks_pair *)
	return (res);
}
