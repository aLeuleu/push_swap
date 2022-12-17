/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:55:01 by alevra            #+#    #+#             */
/*   Updated: 2022/12/17 14:55:52 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_freestacks(t_stack *a, t_stack *b)
{
	ft_freestack(a);
	ft_freestack(b);
}

void	ft_freestack(t_stack *a)
{
	free (a->tab);
	free(a);
}
