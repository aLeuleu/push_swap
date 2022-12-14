# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 15:01:30 by alevra            #+#    #+#              #
#    Updated: 2022/12/15 23:20:46 by alevra           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = $(NAME).h

SRC =	push_swap.c			\
		push.c				\
		execute_command.c	\
		get_min_max_stack.c	\
		radix_sort.c		\
		rotate.c			\
		short_sort.c		\
		show_stacks.c		\
		swap.c				\

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
	