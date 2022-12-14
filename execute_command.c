/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:39:20 by alevra            #+#    #+#             */
/*   Updated: 2022/12/14 14:11:50 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_command(char *user_input, t_stack *A, t_stack *B)
{
	int			i;
	static int	nb_command;
	
	nb_command++;
	i = 0;
	ft_printf(user_input);
	ft_printf("\n");
	if (user_input[0] == 'p')
	{
		if (user_input[1] == 'a' && B->size)
			push(B, A);
		if (user_input[1] == 'b' && A->size)
			push(A, B);
	}
	if (user_input[0] == 's')
	{
		if (user_input[1] == 'a')
			swap(A);
		if (user_input[1] == 'b')
			swap(B);
		if (user_input[1] == 's')
		{
			swap(A);
			swap(B);
		}
	}
	if (user_input[0] == 'r')
	{
		if (user_input[1] == 'a')
			rotate(A);
		if (user_input[1] == 'b')
			rotate(B);
		if (user_input[1] == 'r' && user_input[2] != 'a' && user_input[2] != 'b' && user_input[2] != 'r') 
		{
			rotate(A);
			rotate(B);
		}
		if (user_input[1] == 'r')
		{
			if (user_input[2] == 'a')
				rotate_reverse(A);
			if (user_input[2] == 'b')
				rotate_reverse(B);
			if (user_input[2] == 'r')
			{
				rotate_reverse(A);
				rotate_reverse(B);
			}
		}
	}
	return (nb_command);
}
