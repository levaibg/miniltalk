# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 16:33:29 by lloginov          #+#    #+#              #
#    Updated: 2024/10/17 17:42:59 by lloginov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
RM = rm -f
PRINTF = ft_printf/ft_printe.c \
          ft_printf/ft_printf.c \
          ft_printf/ft_printnb.c \
          ft_printf/ft_putnbr_base.c \
          ft_printf/ft_string.c \
          ft_printf/print_ptr.c \
          ft_printf/print_unsigned.c \
          ft_printf/limk.c

all: $(SERVER) $(CLIENT)

$(SERVER): server.c $(PRINTF)
	$(CC) $(CFLAGS) -o $(SERVER) server.c $(PRINTF)

$(CLIENT): client.c $(PRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT) client.c $(PRINTF)

clean:
	$(RM) $(SERVER) $(CLIENT)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean

