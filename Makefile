# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/28 17:44:36 by fernafer          #+#    #+#              #
#    Updated: 2025/06/30 16:13:11 by fernando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes/
FSANITIZE = -fsanitize=address -g3

SRCS = main.c \
	 error_handling.c \
	 utils.c \
	 stack_swap_operations.c \
	 stack_push_operations.c \
	 stack_rotate_operations.c \
	 stack_r_rotate_operations.c \
	 stack_utils.c \

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

# aqui se compilaria la libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled!"

%.o: %.c
	@echo "Compiling $< into $@"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "Cleaning completed!"

fclean: clean
	rm -f $(NAME)
	@echo "Deep cleaning completed"

re: fclean all
	@echo "Rebuilding project..."

.PHONY: all clean fclean re

