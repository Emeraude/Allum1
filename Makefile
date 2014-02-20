##
## Makefile for  in /home/broggi_t/projets/allum1
##
## Made by broggi_t
## Login   <broggi_t@epitech.eu>
##
## Started on  Tue 11 Feb 04:07:15 2014 broggi_t
## Last update Sun Feb 16 01:57:56 2014 
##

SRCS	= src/game.c \
	  src/get_next_line.c \
	  src/ia.c \
	  src/main.c \
	  src/my_getnbr.c \
	  src/my_putnchar.c \
	  src/my_str.c \
	  src/my_strcmp.c \
	  src/player.c \
	  src/print.c

OBJS	= $(SRCS:.c=.o)

NAME	= allum1

CC	= cc

CFLAGS	+= -W -Wall -Wextra -pedantic -ansi
CFLAGS	+= -I include/

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
