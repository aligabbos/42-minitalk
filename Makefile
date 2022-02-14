# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsemerar <gsemerar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 18:08:49 by gsemerar          #+#    #+#              #
#    Updated: 2022/02/14 12:37:16 by gsemerar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME			= server
CLIENT			= client
INCLUDE			= includes
FT_PRINTF		= ft_printf
LIB_FT_PRINTF	= $(FT_PRINTF)/libftprintf.a
CC				= gcc
OPTION			= -I $(INCLUDE)
CFLAGS			= -Wall -Werror -Wextra $(OPTION)
RM				= rm -f

#Sources

SERVER_SRC		= src/server.c
CLIENT_SRC		= src/client.c

#Objects

SERVER_OBJ		=	$(SERVER_SRC:.c=.o)
CLIENT_OBJ		=	$(CLIENT_SRC:.c=.o)

###

all:		$(NAME)

$(NAME):	$(SERVER_OBJ) $(CLIENT)
			make -C $(FT_PRINTF)
			$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIB_FT_PRINTF) -o $(NAME)

$(CLIENT):	$(CLIENT_OBJ)
			make -C $(FT_PRINTF)
			$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIB_FT_PRINTF) -o $(CLIENT)

bonus:		all

clean:
			make clean -C $(FT_PRINTF)
			$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)

fclean:		clean
			make fclean -C $(FT_PRINTF)
			$(RM) $(NAME) $(CLIENT)

re:			fclean all

.PHONY:		all bonus clean fclean re
