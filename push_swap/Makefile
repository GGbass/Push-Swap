# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 20:20:21 by gongarci          #+#    #+#              #
#    Updated: 2024/07/11 22:03:13 by gongarci         ###   ########.fr        #
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

SRC =	./src/lstd_tools.c \
		./src/params.c \
		./src/main.c \
		
OBJ = $(SRC:.c=.o)

#OBJB = $(SRCB:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address,leak
CC = gcc

all: $(NAME) show_progreesss

$(NAME): $(OBJ)
	@make -s -C libft 
	$(CC) $(CFLAGS) $(OBJ) -L libft -lft -o push_swap -no-pie
	
show_progreesss:
		@for file in $(SRC); do \
			echo "$(GREEN)Compiling $$file "; \
		done; \
		echo "Compiled: 100%$(DEFAULT)"; \
#bonus: 
#$(NAMEB): $(OBJB)
#	@make -C libft
#	$(CC) $(CFLAGS) $(OBJB) -L libft -lft -o bonus
	
clean:
		rm -f $(NAME)
#rm -f $(NAMEB)
		@make fclean -s -C libft
	
fclean: clean
	rm -f $(OBJ)
#rm -f $(OBJB)
	@make  clean -s -C libft

re: fclean all
#rm -f $(NAME)

#re_bonus: fclean bonus
#	rm -f $(NAMEB)

.PHONY: clean fclean re all 

# -C  aplica solo para ese directorio
# -L para las librerias