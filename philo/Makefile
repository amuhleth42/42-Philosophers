# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 18:03:09 by amuhleth          #+#    #+#              #
#    Updated: 2022/07/20 18:14:37 by amuhleth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCL	= -I.
SRCS	= 	$(addprefix srcs/,	\
			test.c				\
			utils.c				\
			print.c				\
			time.c				\
			checker.c			\
			init.c				\
			philos.c)

OBJS	= $(SRC:.c=.o)


all : $(OBJS)
	$(CC) $(CFLAGS) $(INCL) $(SRCS) -o $(NAME)

clean :	
	rm -Rf $(OBJS)

fclean : clean
	rm -Rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
