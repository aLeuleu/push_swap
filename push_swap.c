/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:08:51 by alevra            #+#    #+#             */
/*   Updated: 2022/11/27 19:13:16 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	p(int *stack, char *s);

int	main(int argc, char const *argv[])
{
	int		*A;
	int		i;
	char	*user_input;

	i = 1;
	A = malloc(sizeof(int) * argc - 1);
	while (i < argc)
	{
		A[i] = NULL;
		i++;
	}
	if (argc > 1)
	{
		while (argc > 1)
		{
			A[argc - 2] = atoi(argv[argc - 1]);
			argc--;
		}
	}
	user_input = malloc(sizeof(char) * 3);
	read(1, user_input, 3);
	while (user_input[0] != 'e')
	{
		execute_command(user_input, A);
		read(1, user_input, 3);
	}
	return (0);
}

void	execute_command(char *user_input, int *A, int *B)
{
	if (user_input[0] == 'p')
	{
		printf("p%c\n", user_input[1]);
		if (user_input[1] == 'a' && B[0])
			p(A, B)
	}
}



void	p(int *stack, char *s)
{
	static int i;

	stack[i] = atoi(s);
	i++;
}