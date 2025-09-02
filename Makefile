# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupayet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 12:05:15 by lupayet           #+#    #+#              #
#    Updated: 2025/09/02 13:57:38 by lupayet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#.SILENT:

NAME = minitalk

SERVER = server
CLIENT = client

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g
RM = rm -f
INC_DIR = ./inc
SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIBFT_P = ./libft/
LIBFT = $(LIBFT_P)libft.a
S_SRC = server.c utils.c clt_utils.c
C_SRC = client.c

C_OBJ	= $(addprefix $(OBJ_DIR), $(C_SRC:.c=.o))
S_OBJ	= $(addprefix $(OBJ_DIR), $(S_SRC:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_P) -I$(INC_DIR) -c $< -o $@

all: $(NAME)

$(LIBFT):
	@echo "COMPILING LIBFT..."
	@make -C $(LIBFT_P) 1>/dev/null
	@echo "> LIBFT CREATED\n"

$(SERVER): $(S_OBJ)
	@echo "COMPILING SERVER..."
	@$(CC) $(CFLAGS) $(S_OBJ) -I$(INC_DIR) -I$(LIBFT_P) $(LIBFT) -g -o server
	@echo "> SERVER CREATED\n"

$(CLIENT): $(C_OBJ)
	@echo "COMPILING CLIENT..."
	@$(CC) $(CFLAGS) $(C_OBJ) -I$(LIBFT_P) $(LIBFT) -g -o client
	@echo "> CLIENT CREATED\n"

$(NAME): $(LIBFT) $(CLIENT) $(SERVER)
	@echo "> $(NAME) READY"

clean:
	@make clean -C $(LIBFT_P) 1>/dev/null
	@rm -f $(C_OBJ) $(S_OBJ)

fclean: clean
	@make fclean -C $(LIBFT_P) 1>/dev/null
	@rm -f $(SERVER) $(CLIENT)

re:fclean all

dev: re
	@make clean 1>/dev/null

.PHONY: all clean fclean re dev
