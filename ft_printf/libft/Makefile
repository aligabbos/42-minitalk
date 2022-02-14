# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 11:46:16 by gsemerar          #+#    #+#              #
#    Updated: 2022/01/20 12:13:57 by gsemerar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_isalpha.c		\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_strlen.c			\
		ft_memset.c			\
		ft_bzero.c			\
		ft_memcpy.c			\
		ft_memmove.c		\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strchr.c			\
		ft_strrchr.c		\
		ft_strncmp.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_strnstr.c		\
		ft_atoi.c			\
		ft_calloc.c			\
		ft_strdup.c			\
		ft_substr.c			\
		ft_strjoin.c		\
		ft_strtrim.c		\
		ft_split.c			\
		ft_itoa.c			\
		ft_strmapi.c		\
		ft_striteri.c		\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

SRCBS =	ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c

OBJBS = $(SRCBS:.c=.o)

CC = gcc
HEADER = ./
OPTION = -c -I $(HEADER)
CFLAGS = -Wall -Wextra -Werror $(OPTION)
AR = ar rcs
RM = /bin/rm -f

NAME = libft.a

all: 		$(NAME)

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ) $(OBJBS)

fclean:		clean
			$(RM) $(NAME)

re: 		fclean $(NAME)

bonus:		$(OBJ) $(OBJBS)
			$(AR) $(NAME) $(OBJ) $(OBJBS)

.PHONY:		all clean fclean re bonus
