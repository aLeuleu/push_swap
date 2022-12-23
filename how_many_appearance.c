/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_many_appearance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:19:08 by alevra            #+#    #+#             */
/*   Updated: 2022/12/23 17:34:49 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	how_many_appearance(char *str, char **str_tab)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (str_tab[i])
		if (ft_atoll(str) == ft_atoll(str_tab[i++]))
			res++;
	return (res);
}
