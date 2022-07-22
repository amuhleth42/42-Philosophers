# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 18:06:24 by amuhleth          #+#    #+#              #
#    Updated: 2022/07/22 12:54:58 by amuhleth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_bonus
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I.
SRCS	= 	$(addprefix srcs/,		\
			main.c					\
			utils.c					\
			print.c					\
			time.c					\
			init.c					\
			philos.c				\
			error.c					\
			checker.c)

OBJS	= $(SRCS:.c=.o)


$(NAME) :	$(OBJS)
	$(CC) $(CFLAGS) $(INCL) $(OBJS) -o $(NAME)

all :	$(NAME)

clean :
	rm -Rf $(OBJS)

fclean : clean
	rm -Rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
