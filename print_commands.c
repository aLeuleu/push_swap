/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:22:42 by alevra            #+#    #+#             */
/*   Updated: 2022/12/23 17:23:20 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_commands(t_stacks_pair *stacks)
{
	size_t	i;

	i = 0;
	if (stacks)
	{
		while (ft_strncmp(stacks->commands[i], "END", 4))
		{
			ft_printf(stacks->commands[i]);
			ft_printf("\n");
			i++;
		}
	}
}
