# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupayet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 12:05:15 by lupayet           #+#    #+#              #
#    Updated: 2025/09/01 14:00:44 by lupayet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#.SILEN  T:

NAME = minitalk

SERVER = server
CLIENT = client

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

$(SERVER): ./src/server.c ./src/utils.c
	@echo "\nCOMPILING SERVER..."
	@$(CC) $(CFLAGS) ./src/server.c ./src/utils.c -I$(INC_DIR) -I$(LIBFT_P) $(LIBFT_P)libft.a -g -o server
	@echo "> SERVER CREATED"

$(CLIENT): ./src/client.c
	@echo "\nCOMPILING CLIENT..."
	@$(CC) $(CFLAGS) ./src/client.c -I$(LIBFT_P) $(LIBFT_P)libft.a -g -o client
	@echo "> CLIENT CREATED"

$(NAME): $(LIBFT) $(CLIENT) $(SERVER)
	@echo "\n> $(NAME) READY"

clean:
	@make clean -C $(LIBFT_P) 1>/dev/null
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_P) 1>/dev/null
	@rm -f $(SERVER) $(CLIENT)

re:fclean all

dev: re
	@make clean 1>/dev/null

.PHONY: all clean fclean re dev
