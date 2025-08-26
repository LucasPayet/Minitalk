# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupayet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 09:34:40 by lupayet           #+#    #+#              #
#    Updated: 2025/07/16 16:48:00 by lupayet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC	= cc
AR = ar rcs
CFLAGS	= -Wall -Wextra -Werror
RM = rm -f

SRC	= ft_isascii.c ft_strlcat.c ft_toupper.c ft_isdigit.c \
	  ft_striteri.c ft_atoi.c ft_putchar_fd.c ft_calloc.c \
	  ft_strdup.c ft_strncmp.c ft_strnstr.c ft_strchr.c \
	  ft_strtrim.c ft_split.c ft_strmapi.c ft_strlcpy.c \
	  ft_memchr.c ft_tolower.c ft_isalnum.c ft_isprint.c \
	  ft_memmove.c ft_putendl_fd.c ft_substr.c ft_memset.c \
	  ft_memcpy.c ft_memcmp.c ft_bzero.c ft_strlen.c \
	  ft_putstr_fd.c ft_isalpha.c ft_strjoin.c ft_itoa.c \
	  ft_putnbr_fd.c ft_strrchr.c ft_printf.c print_ap.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJ = $(BONUS:.c=.o)

OBJ	= $(SRC:.c=.o) 

all:$(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: $(BONUS_OBJ) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re:fclean all

.PHONY: all clean fclean re bonus
