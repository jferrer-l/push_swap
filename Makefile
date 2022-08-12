#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 18:11:15 by jferrer-          #+#    #+#              #
#    Updated: 2022/03/17 18:26:57 by jferrer-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME= pushswap.a

SRCS= calculate.c push.c reverse_rotate.c rotate.c swap.c utils.c

#SRCSB= 

OBJ= $(SRCS:.c=.o)

$(NAME): $(OBJ)
	@echo "\033[36m"--Compilando--"\033[0m ";
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	gcc -Wall -Wextra -Werror f_norm.c calculate.c swap.c push.c reverse_rotate.c rotate.c utils.c swapbonus.c pushbonus.c reverse_rotatebonus.c rotatebonus.c -o push_swap
#	gcc -Wall -Wextra -Werror -fsanitize=address f_norm.c calculate.c swap.c push.c reverse_rotate.c rotate.c utils.c swapbonus.c pushbonus.c reverse_rotatebonus.c rotatebonus.c -o push_swap
	@clear

all: $(NAME)

re: fclean all

clean:
	@rm -rf $(NAME) $(OBJ) push_swap checker *.o
	@clear
	@echo "\033[34m"🗑️\  Todo depurado correctamente  \🗑️"\033[0m"

fclean: clean
		@rm -rf pushswap.a

bonus:
	@echo "\033[36m"--Compilando Bonus--"\033[0m ";
#	@make -sC ./Libft
#	@cp ./get_next_line/get_next_line.h .
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=20 bonus.c push.c swapbonus.c pushbonus.c reverse_rotatebonus.c rotatebonus.c utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c -o checker
#	gcc -Wall -Wextra -Werror -fsanitize=address -D BUFFER_SIZE=5 bonus.c push.c swapbonus.c pushbonus.c reverse_rotatebonus.c rotatebonus.c utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c -o checker
	@clear

.PHONY: all clean re fclean bonus
