# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 11:24:29 by amorcill          #+#    #+#              #
#    Updated: 2021/12/30 20:35:33 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= minitalk
SERVER_NAME		= server
CLIENT_NAME 	= client
CC				= gcc
FLAGS			= -Wall -Wextra -Werror -g
SERVER_OBJS		= $(patsubst %.c, %.o, $(SERVER_SRCS))
CLIENT_OBJS		= $(patsubst %.c, %.o, $(CLIENT_SRCS))
SERVER_SRCS		=	server.c
CLIENT_SRCS		=	client.c
			 
%.o: %.c
	$(CC) $(FLAGS) -Ilibft -c $< -o $@

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): libft/libft.a $(SERVER_OBJS)
	$(CC) $(FLAGS) $(SERVER_OBJS) -Llibft -lft -o $(SERVER_NAME) 

$(CLIENT_NAME): libft/libft.a $(CLIENT_OBJS)
	$(CC) $(FLAGS) $(CLIENT_OBJS) -Llibft -lft -o $(CLIENT_NAME) 

clean:
	rm -f *.o
	rm -f *.out
	make -C libft clean

fclean: clean
	make -C libft fclean	
	rm -f $(SERVER_NAME)
	rm -f $(CLIENT_NAME)

re: fclean $(SERVER_NAME) $(CLIENT_NAME)
	
libft/libft.a:
	make -C libft all
