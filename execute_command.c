/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:39:20 by alevra            #+#    #+#             */
/*   Updated: 2022/12/17 13:14:09 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_command(const char *command, t_stack *A, t_stack *B)
{
	static int	nb_command;
	
	nb_command++;
	ft_printf(command);
	ft_printf("\n");
	if (!ft_strncmp(command,"pa", ft_strlen(command)))
		push(B, A);
	if (!ft_strncmp(command,"pb", ft_strlen(command)))
		push(A, B);
	if (!ft_strncmp(command,"sa", ft_strlen(command)))
		swap(A);
	if (!ft_strncmp(command,"sb", ft_strlen(command)))
		swap(B);
	if (!ft_strncmp(command,"sb", ft_strlen(command)))
	{
		swap(A);
		swap(B);
	}
	if (!ft_strncmp(command,"ra", ft_strlen(command)))
		rotate(A);
	if (!ft_strncmp(command,"rb", ft_strlen(command)))
		rotate(B);
	if (!ft_strncmp(command,"rra", ft_strlen(command)))
		rotate_reverse(A);
	if (!ft_strncmp(command,"rrb", ft_strlen(command)))
		rotate_reverse(B);
	if (!ft_strncmp(command,"rrr", ft_strlen(command)))
	{
		rotate_reverse(A);
		rotate_reverse(B);
	}
	return (nb_command);
}
