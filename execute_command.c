/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:39:20 by alevra            #+#    #+#             */
/*   Updated: 2022/12/15 04:03:26 by alevra           ###   ########lyon.fr   */
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
	if (user_input == "pa")
		push(B, A);
	if (user_input == "pb")
		push(A, B);
	if (user_input == "sa")
		swap(A);
	if (user_input == "sb")
		swap(B);
	if (user_input == "ss")
	{
		swap(A);
		swap(B);
	}
	if (user_input == "ra")
		rotate(A);
	if (user_input == "rb")
		rotate(B);
	if (user_input == "rra")
		rotate_reverse(A);
	if (user_input == "rrb")
		rotate_reverse(B);
	if (user_input == "rrr")
	{
		rotate_reverse(A);
		rotate_reverse(B);
	}
	return (nb_command);
}
