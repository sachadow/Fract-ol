# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sderet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:05:33 by sderet            #+#    #+#              #
#    Updated: 2018/02/02 18:36:30 by sderet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_strlow.c ft_strlen.c ft_isascii.c ft_isalpha.c ft_isprint.c ft_isdigit.c ft_isalnum.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_putchar.c ft_putstr.c ft_putendl.c ft_strrev.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_itoa.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c get_next_line.c
INCLUDE = libft.h
CC = clang
CC_FLAGS = -Wall -Werror -Wextra
NAME = libft.a
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) built"

clean :
	@rm -f $(OBJ)
	@echo "$(NAME) clean successful"

fclean : clean
	@rm -f $(NAME)
	@echo "$(NAME) fclean successful"

re : fclean all

rere : re clean
