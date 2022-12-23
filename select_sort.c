/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:45:33 by alevra            #+#    #+#             */
/*   Updated: 2022/12/23 16:02:58 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sort(t_stacks_pair *stacks)
{
	size_t	min_pos;
	int		min;
	t_stack	*a;
	t_stack	*b;
	size_t		depth;

	depth=0;
	a = stacks->a;
	b = stacks->b;
	while (a->size != 0)
	{
		min_pos = get_min_pos_stack(a);
		min = get_min_stack(a);
		if (a->tab[0] == get_max_stack(a) && a->tab[1] == min)
			execute_command("ra", stacks, &stacks, depth++);
		if (a->tab[0] > a->tab[1])
			execute_command("sa", stacks, &stacks, depth++);
		if (min_pos + 1 < (a->size) / 2)
			while (a->tab[0] != min)
				execute_command("ra", stacks, &stacks, depth++);
		else
			while (a->tab[0] != min)
				execute_command("rra", stacks, &stacks, depth++);
		if (is_stack_sorted(stacks->a))
			break ;
		else
			execute_command("pb", stacks, &stacks, depth++);
	}
	while (b->size > 0)
		execute_command("pa", stacks, &stacks, depth++);
	execute_command("END", stacks, &stacks, depth++);
}

# Afficher les dossiers en bleu et en gras avec un slash
ls -l | grep ^d | awk '{print "\033[1;34m" $9 "/\033[0m"}'

#Affiche tout les fichiers sans extensions en gras et en noir
ls -1 | grep -v '\.' | awk '{print "\033[1;1m" $1 "\033[0m"}'

# Afficher le fichier Makefile en gras et en jaune
ls -l | grep Makefile | awk '{print "\033[38;5;255m\033[48;5;226m "$9" \033[0m"}'

# Afficher les fichiers .h en gras et en vert clair
ls -l | grep ^- | awk '{ if ($9 ~ /\.h$/) { print "\033[1;32m" $9 "\033[0m" } }'

# Afficher les fichiers .c en gras et en vert
ls -l | grep ^- | awk '{ if ($9 ~ /\.c$/) { print "\033[1;32m" $9 "\033[0m" } }'

# Afficher le reste des fichiers
ls -l | grep ^- | awk '{ if (!($9 ~ /\.$/) && !($9 ~ /\.$/)) { print $9 } }'





ls -l | grep ^d | awk '{print "\033[1;34m" $9 "/\033[0m"}' && ls -1 | grep -v '\.' | awk '{print "\033[1;1m" $1 "\033[0m"}' && ls -l | grep Makefile | awk '{print "\033[38;5;255m\033[48;5;226m "$9" \033[0m"}' && ls -l | grep ^- | awk '{ if ($9 ~ /\.h$/) { print "\033[1;32m" $9 "\033[0m" } }' && ls -l | grep ^- | awk '{ if ($9 ~ /\.c$/) { print "\033[1;32m" $9 "\033[0m" } }' && ls -l | grep ^- | awk '{ if (!($9 ~ /\.h$/) && !($9 ~ /\.c$/)) { print $9 } }'


# Afficher les dossiers en bleu et en gras avec un slash

# Affiche tout les fichiers sans extensions en gras et en noir

# Afficher le fichier Makefile en gras et en jaune

# Afficher les fichiers .h en gras et en vert clair

# Afficher les fichiers .c en gras et en vert

# Afficher le reste des fichiers

# Afficher les dossiers en bleu et en gras avec un slash
ls -d */ | awk '{print "\033[1;34m" $0 "\033[0m"}'

# Afficher le fichier Makefile en gras et en jaune
ls -l | grep Makefile | awk '{print "\033[38;5;255m\033[48;5;226m "$9" \033[0m"}'

# Afficher les fichiers .h en gras et en vert clair
ls | grep '\.h$' | awk '{print "\033[1;92m" $0 "\033[0m"}'

# Afficher les fichiers .c en gras et en vert
ls | grep '\.c$' | awk '{print "\033[1;32m" $0 "\033[0m"}'

# Afficher le reste des fichiers
ls -p | grep -v / | grep -vE '\.[hc]$|^Makefile$'
