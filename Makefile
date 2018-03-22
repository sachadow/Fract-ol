# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sderet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 15:33:21 by sderet            #+#    #+#              #
#    Updated: 2018/02/02 18:46:52 by sderet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = main.c win_crea.c mandelbrot.c display_fun.c julia.c burning_ship.c init_big.c zoom.c
HEAD = fractol.h
LIBS = -L./libft -lft -L./minilibx -lmlx
FRAMEW = -framework OpenGL -framework Appkit
OBJ = $(SRCS:%.c=%.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

debug: CFLAGS += -g
debug: all

$(NAME): libft/libft.a $(OBJ)
	@$(CC) $(LIBS) $(FRAMEW) -o $(NAME) $(SRCS) $(CFLAGS)
	@echo "Successfully compiled $(NAME)"

libft/libft.a:
	@$(MAKE) -C libft
	@echo "Successfully compiled libft"

$(OBJ): %.o: %.c $(HEAD)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "Successfully compiled object for $<"

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C libft $@
	@echo "$(NAME) clean successful"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft $@
	@echo "$(NAME) fclean successful"

re: fclean all
