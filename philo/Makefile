# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 18:03:09 by amuhleth          #+#    #+#              #
#    Updated: 2022/07/22 12:51:08 by amuhleth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I.
SRCS	= 	srcs/test.c				\
			srcs/utils.c			\
			srcs/print.c			\
			srcs/time.c				\
			srcs/checker.c			\
			srcs/init.c				\
			srcs/philos.c			\

OBJS	= $(SRCS:.c=.o)

%.o :	%.c
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all :	$(NAME)

clean :	
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

debug :
	$(CC) $(CFLAGS) $(SRCS) -g -o $(NAME)
	lldb $(NAME)
	rm -rf philo.dSYM

re : fclean all

.PHONY: all clean fclean re debug
