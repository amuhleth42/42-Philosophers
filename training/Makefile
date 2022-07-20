NAME	= philo

CFLAGS	= -Wall -Wextra -Werror
INCL	= -I.

SRCS_DIR	= srcs
OBJS_DIR	= $(shell mkdir -p objs && printf "objs")

SRCS	= 	test.c		\
			utils.c		\
			print.c		\
			time.c		\
			checker.c	\
			init.c		\
			philos.c	\

OBJS	= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all :	$(NAME)

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
	gcc $(CFLAGS) $(INCL) -c $< -o $@ -g

$(NAME) :	$(OBJS)
	gcc $(CFLAGS) $(INCL) $(OBJS) -o $(NAME) -g

clean :
	rm -rf $(OBJS_DIR)
	rm $(NAME)

fclean :	clean

re :		fclean all

.PHONY :	clean fclean all re
