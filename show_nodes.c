/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:47:09 by alevra            #+#    #+#             */
/*   Updated: 2023/01/03 17:25:00 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_printf_tab(int tabs, const char *str, ...)
{
	va_list	args;
	int		res;

	while (tabs-- > 0)
		return (ft_printf("\t"));
	va_start(args, str);
	res = ft_printf(str, args);
	va_end(args);
	return (res);
}

void	show_nodes(t_node *node)
{
	int	i;
	int	tabs;

	i = 0;
	tabs = node->depth;
	ft_printf_tab(tabs, "depth : %d", node->depth);
	show_stacks(node->stacks);
}
