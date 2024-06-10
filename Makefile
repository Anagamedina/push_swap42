# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 09:54:05 by anamedin          #+#    #+#              #
#    Updated: 2024/06/10 10:24:52 by anamedin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -02
RM = rm -rf
ARC =  ar -rcs

NAME = push_swap.a
HEADER = push_swap.h

SRCS = $(wildcard *.c)
OBJS = $(SRCS: .c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(ARC) $(NAME) $(OBJS)

%.o : %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean 
	$(RM) $(NAME)

re : fclean all 

.PHONY : all, clean, fclean, re
