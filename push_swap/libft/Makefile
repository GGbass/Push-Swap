# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gongarci <gongarci@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 10:23:11 by gongarci          #+#    #+#              #
#    Updated: 2023/09/26 10:23:15 by gongarci         ###   ########.fr        #
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

SRC =	ft_strchr.c \
		ft_strlen.c \
		ft_strrchr.c \
		ft_bzero.c \
		ft_strlcpy.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_strlcat.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line_utils.c \
		get_next_line.c \
		./printf/ft_putnbr.c \
		./printf/ft_printf.c \
		./printf/ft_putchar.c \
		./printf/ft_puthexa.c \
		./printf/ft_putmem.c \
		./printf/ft_string.c \
		./printf/ft_unprintf.c \
		./printf/ft_unsigned_int.c \



OBJS = $(SRC:.c=.o)
CURRENT_FILE = 1
TOTAL_FILES = $(words $(SRC))
COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror 

NAME = libft.a



all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	@printf "\033[KCompiling $<... $(shell echo $$(($(CURRENT_FILE) * 100 / $(TOTAL_FILES))))%%\r"
	@$(COMPILER) $(CFLAGS) -c $< -o $@
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	
#bonus: $(OBJS_BONUS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all 

#BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
#bonus
#OBJS_BONUS = $(BONUS:.c=.o)
#	ar rc $(NAME) $(OBJS_BONUS)
#	rm -f $(OBJS_BONUS)