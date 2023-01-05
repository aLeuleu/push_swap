/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:42:46 by alevra            #+#    #+#             */
/*   Updated: 2023/01/05 03:15:26 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetab(void **tab, int position)
{
	if (position >= 0)
	{
		while (position >= 0)
		{
			if (tab[position])
				free(tab[position]);
			position--;
		}
	}
	free(tab);
}
