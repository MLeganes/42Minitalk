# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 11:24:29 by amorcill          #+#    #+#              #
#    Updated: 2021/12/28 10:01:38 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minital
SERVERNAME	= server
CLIENTNAME  = client
CC			= gcc
#FLAGS		= -Wall -Wextra -Werror -g -fsanitize=address -fsanitize=address
FLAGS		= -Wall -Wextra -Werror
OBJS		= $(patsubst %.c, %.o, $(SRCS))
SRCS		=	server.c \

			 
%.o: %.c
	$(CC) $(FLAGS) -Ilibft -c $< -o $@

all: $(NAME)

$(NAME): libft/libft.a $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -Llibft -lft -o $(SERVERNAME) 

clean:
	rm -f *.o
	rm -f *.out
	make -C libft clean

fclean: clean
	make -C libft fclean	
	rm -f $(NAME)

re: fclean $(NAME)
	
libft/libft.a:
	make -C libft all
