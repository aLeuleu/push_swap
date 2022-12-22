/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:08:51 by alevra            #+#    #+#             */
/*   Updated: 2022/12/22 14:25:31 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_a_number(const char *str);
static int		check_args(size_t size, char const *argv[]);
/* static size_t	ft_max(size_t a, size_t b);
static int		ft_strequ(char *str1, char *str2); */
static int		how_many_appearance(char *str, char **str_tab);
static int		handle_mono_arg(t_stacks_pair *stacks, const char *argv1);
static int		sort_stacks(t_stacks_pair *stacks);
static void		print_commands(t_stacks_pair *stacks);
static void		error(void);
static int		overflow_int(long long nb);

static int	overflow_int(long long nb)
{
	if (nb > INT_MAX)
		return (1);
	if (nb < INT_MIN)
		return (-1);
	return (0);
}

static int	is_a_number(const char *str)
{
	int		i;

	if (!(str[0] == '-' || str[0] == '+' || ft_isdigit((int)str[0])))
		return (0);
	i = 1;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

/* static size_t	ft_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
} */

static int	check_args(size_t size, char const *argv[])
{
	size_t		i;
	long long 	res;

	i = 0;
	while (i < size)
	{
		res = ft_atoll(argv[i]);
		if (!is_a_number(argv[i])
			|| how_many_appearance((char *)argv[i++], (char **)argv) > 1
			|| overflow_int(res))
			return (0);
	}
	return (1);
}

/* static int	ft_strequ(char *str1, char *str2)
{
	size_t	str1len;
	size_t	str2len;

	str1len = ft_strlen(str1);
	str2len = ft_strlen(str2);
	if (str1len != str2len || ft_strncmp(str1, str2, ft_max(str1len, str2len)))
		return (0);
	return (1);
} */

static int	how_many_appearance(char *str, char **str_tab)
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

static int	handle_mono_arg(t_stacks_pair *stacks, const char *argv1)
{
	int		j;
	char	**splits;

	j = 0;
	splits = (ft_split(argv1, ' '));
	while (*(splits++))
		stacks->a->size++;
	splits -= (stacks->a->size + 1);
	if (!check_args(stacks->a->size, (const char **)splits))
		return (0);
	malloc_stacks_tab_and_set_size(stacks, stacks->a->size + 1);
	while (splits[j] != 0)
	{
		stacks->a->tab[j] = ft_atoi(splits[j]);
		free(splits[j]);
		j++;
	}
	free(splits);
	return (1);
}

static int	sort_stacks(t_stacks_pair *stacks)
{
	if (is_stack_sorted(stacks->a))
		return (execute_command("END", stacks, &stacks, 0));
	replace_values_by_rank(stacks->a);
	if (stacks->a->size < 55)
		select_sort(stacks);
	else
		radix_sort(stacks);
	return (1);
}

static void	print_commands(t_stacks_pair *stacks)
{
	size_t	i;

	i = 0;
	if (stacks)
	{
		while (ft_strncmp(stacks->commands[i], "END", 4))
		{
			ft_printf(stacks->commands[i]);
			ft_printf("\n");
			i++;
		}
	}
}

static void	error()
{
	write(2, "Error\n", ft_strlen("Error\n"));
}

int	main(int argc, char const *argv[])
{
	t_stacks_pair	*stacks;
	t_stack			*a;
	t_stack			*b;

	if (argc == 1)
		return (0);
	stacks = init_stacks_pair(&a, &b);
	if (!stacks)
		return (error(), 0);
	if (argc > 2)
	{
		if (!check_args(argc - 1, argv +1))
			return (error(), 0);
		malloc_stacks_tab_and_set_size(stacks, argc);
		while (argc > 1)
		{
			a->tab[argc - 2] = ft_atoi(argv[argc - 1]);
			argc--;
			a->size++;
		}
		a->tab[stacks->a->size] = 9999;
	}
	else if (argc == 2)
		if (!handle_mono_arg(stacks, argv[1]))
			return (error(), 0);
	if (!sort_stacks(stacks) && stacks->commands_tab_size > 1)
		return (ft_printf("Error\n"));
	print_commands(stacks);
	return (ft_freestacks(stacks), 0);
}
