# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 09:54:05 by anamedin          #+#    #+#              #
#    Updated: 2024/06/16 18:55:05 by anamedin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O2
RM = rm -rf
ARC = ar -rcs

# Archivos
NAME = push_swap.a
HEADER = push_swap.h

# Encontrar todos los archivos .c y generar los archivos .o correspondientes
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Reglas
all: $(NAME)

$(NAME): $(OBJS)
	$(ARC) $(NAME) $(OBJS)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

