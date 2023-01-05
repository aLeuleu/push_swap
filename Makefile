# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 15:01:30 by alevra            #+#    #+#              #
#    Updated: 2023/01/04 22:28:06 by alevra           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = $(NAME).h

SRC =	execute_command.c			\
		ft_freestacks.c				\
		get_min_max_stack.c			\
		how_many_appearance.c		\
		init_stacks_pair.c			\
		is_stack_sorted.c			\
		malloc_stacks_tab_and_set_size.c\
		print_commands.c			\
		push_swap.c					\
		push.c						\
		radix_sort.c				\
		realloc_stacks_command.c	\
		replace_values_by_rank.c	\
		rotate.c					\
		select_sort.c				\
		sort_stacks.c				\
		stacks_dup.c				\
		swap.c						\
		
	
OBJ = $(addprefix obj/,$(SRC:.c=.o))

FSANITIZE = -fsanitize=address

all	: create_obj_folder $(NAME) end_message

libft/libft.a :
	make -C libft

$(NAME): libft/libft.a $(OBJ)
	cc -Wall -Wextra -Werror $(OBJ) -L ./libft -lft -o $(NAME)

obj/%.o : %.c $(HEADER)
		cc -c -Wall -Wextra -Werror $< -o $@

create_obj_folder :
	mkdir -p obj

clean:
	rm -f $(OBJ)
	@if [ -d "./obj" ]; then\
		rm -r obj;\
	fi
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

debug : libft/libft.a
	cc $(FSANITIZE) -Wall -Wextra -Werror $(SRC) -L ./libft -lft -o $(NAME)_debug  && ./$(NAME)_debug $(ARG) && echo "" && ./$(NAME)_debug $(ARG) | ./checker $(ARG) 

run:
	./$(NAME) $(ARG)

end_message:
	@echo "Done !"

.PHONY: all clean fclean re create_obj_folder end_message
	