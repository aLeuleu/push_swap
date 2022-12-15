/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:39:20 by alevra            #+#    #+#             */
/*   Updated: 2022/12/15 15:45:48 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_command(const char *user_input, t_stack *A, t_stack *B)
{
	int			i;
	static int	nb_command;
	
	nb_command++;
	i = 0;
	ft_printf(user_input);
	ft_printf("\n");
	if (ft_strncmp(user_input,"pa", ft_strlen(user_input)))
		push(B, A);
	if (ft_strncmp(user_input,"pb", ft_strlen(user_input)))
		push(A, B);
	if (ft_strncmp(user_input,"sa", ft_strlen(user_input)))
		swap(A);
	if (ft_strncmp(user_input,"sb", ft_strlen(user_input)))
		swap(B);
	if (ft_strncmp(user_input,"sb", ft_strlen(user_input)))
	{
		swap(A);
		swap(B);
	}
	if (ft_strncmp(user_input,"ra", ft_strlen(user_input)))
		rotate(A);
	if (ft_strncmp(user_input,"rb", ft_strlen(user_input)))
		rotate(B);
	if (ft_strncmp(user_input,"rra", ft_strlen(user_input)))
		rotate_reverse(A);
	if (ft_strncmp(user_input,"rrb", ft_strlen(user_input)))
		rotate_reverse(B);
	if (ft_strncmp(user_input,"rrr", ft_strlen(user_input)))
	{
		rotate_reverse(A);
		rotate_reverse(B);
	}
	return (nb_command);
}
