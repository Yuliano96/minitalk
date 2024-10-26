# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 16:34:32 by ypacileo          #+#    #+#              #
#    Updated: 2024/10/26 12:16:03 by ypacileo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -I./
RM = rm -f
OBJ = ft_basic.o ft_printf.o
all: $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)
	@echo "PRINTF COMPILED\n"
%.o : %.c
	gcc  -c  $(CFLAGS) $< -o $@

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re
