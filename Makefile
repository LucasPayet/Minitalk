# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupayet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 12:05:15 by lupayet           #+#    #+#              #
#    Updated: 2025/08/26 12:55:00 by lupayet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#.SILENT:

NAME = minitalk

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g
RM = rm -f
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc
LIBFT_P = ./libft/
LIBFT = $(LIBFT_P)libft.a

#SRC	= server.c

#OBJ	= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

#$(OBJ_DIR)%.o: $(SRC_DIR)%.c
#	$(CC) -Wall -Wextra -Werror -I$(LIBFT_P) -I$(INC_DIR) -g -c $< -o $@

all: $(NAME)

$(LIBFT):
	@echo "\nCOMPILING LIBFT..."
	@make -C $(LIBFT_P) 1>/dev/null
	@echo "> LIBFT CREATED"

$(NAME): $(LIBFT) $(OBJ)
	@echo "\nCOMPILING $(NAME)\n"
	$(CC) $(CFLAGS) ./src/server.c -I$(LIBFT_P) $(LIBFT_P)libft.a -g -o server
	$(CC) $(CFLAGS) ./src/client.c -I$(LIBFT_P) $(LIBFT_P)libft.a -g -o client
	@echo "> $(NAME) READY"

clean:
	@make clean -C $(LIBFT_P) 1>/dev/null
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_P) 1>/dev/null
	@rm -f $(NAME)

re:fclean all

dev: re
	@make clean 1>/dev/null

.PHONY: all clean fclean re dev
