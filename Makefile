# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 04:32:35 by hrhilane          #+#    #+#              #
#    Updated: 2025/04/10 04:32:36 by hrhilane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux
MLX = minilibx-linux/libmlx.a
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

NAME = fractol

SRC_MANDATORY = main_mandatory.c init.c utils.c parse_args.c \
                hooks_mandatory.c mandelbrot.c julia.c render_mandatory.c

SRC_BONUS = main_bonus.c init.c utils.c parse_args.c \
            hooks_bonus.c burningship.c tricorn.c render_bonus.c \
            mandelbrot.c julia.c

OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

HEADERS = fractol.h fractol_bonus.h

all: $(MLX) $(NAME)

$(MLX):
	make -C minilibx-linux

$(NAME): $(OBJ_MANDATORY)
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) $(MLX_FLAGS) -o $(NAME)

bonus: .bonus_marker

.bonus_marker: $(MLX) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_FLAGS) -o $(NAME)
	@touch .bonus_marker

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_MANDATORY) $(OBJ_BONUS)
	rm -f .bonus_marker
	make clean -C minilibx-linux

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
