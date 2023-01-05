# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 15:01:30 by alevra            #+#    #+#              #
#    Updated: 2023/01/05 08:43:03 by alevra           ###   ########lyon.fr    #
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
		push_swap.c					\
		push.c						\
		radix_sort.c				\
		replace_values_by_rank.c	\
		rotate.c					\
		select_sort.c				\
		sort_stacks.c				\
		stacks_dup.c				\
		swap.c						\
		
	
OBJ = $(addprefix obj/,$(SRC:.c=.o))

FSANITIZE = -fsanitize=address

all	:
	@$(MAKE) create_obj_folder 
	@$(MAKE) $(NAME)
	@$(MAKE) end_message

libft/libft.a :
	$(MAKE) -C libft

$(NAME):
	$(MAKE) libft/libft.a
	$(MAKE) $(OBJ)
	cc -Wall -Wextra -Werror -g3 $(OBJ) -L ./libft -lft -o $(NAME)

obj/%.o : %.c $(HEADER)
		cc -c -Wall -Wextra -Werror $< -o $@

create_obj_folder :
	@mkdir -p obj

clean:
	rm -f $(OBJ)
	@if [ -d "./obj" ]; then\
		rm -r obj;\
	fi
	rm $(NAME)_debug
	$(MAKE) clean -C libft

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all

debug : libft/libft.a
	cc $(FSANITIZE) -Wall -Wextra -Werror $(SRC) -L ./libft -lft -o $(NAME)_debug  && ./$(NAME)_debug $(ARG) && echo "" && ./$(NAME)_debug $(ARG) | ./checker $(ARG) && echo "debug done"

run:
	./$(NAME) $(ARG)

end_message:
	@echo "Done !"

.PHONY: all clean fclean re create_obj_folder end_message
	