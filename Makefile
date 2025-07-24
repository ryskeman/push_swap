# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fernafer <fernafer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/28 17:44:36 by fernafer          #+#    #+#              #
#    Updated: 2025/07/24 11:03:17 by fernando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes/
FSANITIZE = -fsanitize=address -g3

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE = -I$(LIBFT_DIR)/

SRCS = main.c \
	 error_handling.c \
	 utils.c \
	 sort_utils.c \
	 stack_init.c \
	 stack_swap_operations.c \
	 stack_push_operations.c \
	 stack_rotate_operations.c \
	 stack_r_rotate_operations.c \
	 stack_utils.c \

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(FSANITIZE) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(NAME) compiled succesfully!"

%.o: %.c
	@echo "Compiling $< into $@"
	$(CC) $(CFLAGS) $(FSANITIZE) $(LIBFT_INCLUDE) -c $< -o $@

$(LIBFT):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)

clean:
	@echo "Cleaning project objects..."
	rm -f $(OBJS)
	@echo "Cleaning libft completed!"
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Deep cleaning project executable..."
	rm -f $(NAME)
	@echo "Deep cleaning libft archive..."
	@make -C $(LIBFT_DIR) fclean

re: fclean all
	@echo "Rebuilding project..."

.PHONY: all clean fclean re $(LIBFT_DIR)/clean $(LIBFT_DIR)/fclean

