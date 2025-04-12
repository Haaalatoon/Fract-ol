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


# CC = cc
# CFLAGS = -Wall -Wextra -Werror 
# MLX_FLAGS = -lmlx -lXext -lX11 -lm

# NAME = fractol

# SRC_MANDATORY = main_mandatory.c init.c utils.c parse_args.c \
#                 hooks_mandatory.c mandelbrot.c julia.c render_mandatory.c

# SRC_BONUS = main_bonus.c init.c utils.c parse_args_bonus.c \
#             hooks_bonus.c burningship.c tricorn.c render_bonus.c \
#             mandelbrot.c julia.c

# OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)
# OBJ_BONUS = $(SRC_BONUS:.c=.o)

# HEADERS = fractol.h fractol_bonus.h

# .DEFAULT_GOAL = $(NAME)

# all: $(NAME)

# $(NAME): $(OBJ_MANDATORY)
# 	$(CC) $(CFLAGS) $(OBJ_MANDATORY) $(MLX_FLAGS) -o $(NAME)

# bonus: .bonus_marker

# .bonus_marker: $(OBJ_BONUS)
# 	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_FLAGS) -o $(NAME)
# 	@touch .bonus_marker

# %.o: %.c $(HEADERS)
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJ_MANDATORY) $(OBJ_BONUS)
# 	rm -f .bonus_marker

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11 -lm
NAME = fractol

SRC_MANDATORY = main_mandatory.c init.c utils.c parse_args.c \
                hooks_mandatory.c mandelbrot.c julia.c render_mandatory.c

SRC_BONUS = main_bonus.c init.c utils.c parse_args_bonus.c \
            hooks_bonus.c burningship.c tricorn.c render_bonus.c \
            mandelbrot.c julia.c

OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

HEADERS = fractol.h fractol_bonus.h

# Marker files
MANDATORY_MARK = .mandatory_mark
BONUS_MARK = .bonus_mark

all: $(MANDATORY_MARK)

$(MANDATORY_MARK): $(OBJ_MANDATORY)
	@rm -f $(BONUS_MARK)
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) $(MLX_FLAGS) -o $(NAME)
	@touch $(MANDATORY_MARK)

$(BONUS_MARK): $(OBJ_BONUS)
	@rm -f $(MANDATORY_MARK)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_FLAGS) -o $(NAME)
	@touch $(BONUS_MARK)

$(NAME): 
	@if [ -f $(BONUS_MARK) ]; then \
		$(MAKE) fclean; \
		$(MAKE) $(MANDATORY_MARK); \
	else \
		$(MAKE) $(MANDATORY_MARK); \
	fi

bonus: $(BONUS_MARK)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_MANDATORY) $(OBJ_BONUS)
	rm -f $(MANDATORY_MARK) $(BONUS_MARK)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re