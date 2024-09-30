# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 20:20:21 by gongarci          #+#    #+#              #
#    Updated: 2024/09/09 17:26:30 by gongarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME = push_swap

NAMEB = bonus

SRC =	./src/a_to_b.c \
		./src/ab_tools.c \
		./src/b_to_a.c \
		./src/sort_tools.c \
		./src/sort_tools2.c \
		./src/free_stacks.c \
		./src/moves.c \
		./src/moves_a.c \
		./src/moves_dual.c \
		./src/moves_b.c \
		./src/lstd_tools.c \
		./src/params.c \
		./src/main.c \

SRCB =	./srcb/free_stacks_bonus.c \
		./srcb/moves_dual_bonus.c \
		./srcb/moves_b_bonus.c \
		./srcb/moves_a_bonus.c \
		./srcb/lstd_tools_bonus.c \
		./srcb/params_bonus.c \
		./srcb/checker.c \

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address,leak
CC = gcc
#-no-pie

all: $(NAME) show_progress

$(NAME): $(OBJ)
	@make -s -C libft 
	$(CC) $(CFLAGS) $(OBJ) -L libft -lft -o push_swap
	
show_progress:
		@for file in $(SRC); do \
			echo "$(GREEN)Compiling $$file "; \
		done; \
		echo "Compiled: 100%$(DEFAULT)"; \

bonus:
$(NAMEB): $(OBJB) show_progress2
	@make -s -C libft
	$(CC) $(CFLAGS) $(OBJB) -L libft -lft -o checker

show_progress2:
		@for file in $(SRCB); do \
			echo "$(GREEN)Compiling $$file "; \
		done; \
		echo "Compiled: 100%$(DEFAULT)"; \

clean:
	rm -f  $(NAME)
	rm -f $(NAMEB)
	@make fclean -s -C libft

fclean: clean
	rm -f  $(OBJ)
	rm -f $(OBJB)
	@make  clean -s -C libft

re: fclean all

re_bonus: fclean bonus
#	rm -f $(NAMEB)

git:
	git add .
	git commit -m "done"
	git push

.PHONY: clean fclean re all