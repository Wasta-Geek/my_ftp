##
## Makefile for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
## 
## Made by Wasta-Geek
## Login   <ducate_c@epitech.net>
## 
## Started on  Mon May  2 12:44:41 2016 Wasta-Geek
## Last update Sat May 14 22:26:07 2016 Wasta-Geek
##

CC	= gcc

RM	= rm -f

NAME	= server

CFLAGS	= -W -Wextra -Wall -g -I includes

SRC_DIR	= srcs/

SRCS	= $(SRC_DIR)main.c	\
	  $(SRC_DIR)errors.c	\
	  $(SRC_DIR)checks.c	\
	  $(SRC_DIR)sockets.c	\
	  $(SRC_DIR)writing.c	\
	  $(SRC_DIR)commands.c	\
	  $(SRC_DIR)reading.c	\
	  $(SRC_DIR)to_login.c	\
	  $(SRC_DIR)path_commands.c	\
	  $(SRC_DIR)mode_commands.c	\
	  $(SRC_DIR)file_commands.c	\
	  $(SRC_DIR)files_functions.c	\

OBJS	= $(SRCS:.c=.o)


all:	  $(NAME)

$(NAME):  $(OBJS)
	  $(CC) -o $(NAME) $(OBJS)

clean:
	  $(RM) $(OBJS)

fclean:	  clean
	  $(RM) $(NAME)

re:	  fclean all
