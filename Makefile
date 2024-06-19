# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 09:54:05 by anamedin          #+#    #+#              #
#    Updated: 2024/06/18 00:18:58 by anamedin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# Archivos
NAME = push_swap
HEADER = push_swap.h

# Encontrar todos los archivos .c y generar los archivos .o correspondientes
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

# Reglas
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: all

.PHONY: all clean fclean re
