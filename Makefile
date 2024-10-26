# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 20:28:41 by yuliano           #+#    #+#              #
#    Updated: 2024/10/26 12:16:11 by ypacileo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server
OBJS_CLIENT = client.o
OBJS_SERVER = server.o
CFLAGS = -Wall -Wextra -Werror -I./
LIBS = ft_printf/libftprintf.a

all : libs $(SERVER_NAME) $(CLIENT_NAME)
	@echo "DONE"
libs:
	@make -C ft_printf

$(SERVER_NAME) : $(OBJS_SERVER)
	gcc  $(CFLAGS) $(OBJS_SERVER) $(LIBS) -o $(SERVER_NAME)
	@echo "SERVER COMPILED\n"

$(CLIENT_NAME) : $(OBJS_CLIENT)
	gcc $(CFLAGS) $(OBJS_CLIENT) $(LIBS) -o $(CLIENT_NAME)
	@echo "CLIENT COMPILED\n"

%.o : %.c
	gcc  -c  $(CFLAGS) $< -o $@


clean :
	@make fclean -C ft_printf
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME) $(LIBS)
re: fclean all
.PHONY: all clean fclean re