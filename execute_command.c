/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:39:20 by alevra            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/12/15 21:34:51 by alevra           ###   ########lyon.fr   */
=======
/*   Updated: 2022/12/12 13:39:35 by alevra           ###   ########lyon.fr   */
>>>>>>> e04df7b (refactoring)
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
int	execute_command(const char *command, t_stack *A, t_stack *B)
=======
int	execute_command(char *user_input, t_stack *A, t_stack *B)
>>>>>>> e04df7b (refactoring)
{
	int			i;
	static int	nb_command;
	
	nb_command++;
	i = 0;
<<<<<<< HEAD
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
=======
	printf(user_input);
	printf("\n");
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
>>>>>>> e04df7b (refactoring)
	}
	return (nb_command);
}
