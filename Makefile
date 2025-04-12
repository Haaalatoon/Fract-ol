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

# # Marker files
# MANDATORY_MARK = .mandatory_mark
# BONUS_MARK = .bonus_mark

# all: $(MANDATORY_MARK)

# $(MANDATORY_MARK): $(OBJ_MANDATORY)
# 	@rm -f $(BONUS_MARK)
# 	$(CC) $(CFLAGS) $(OBJ_MANDATORY) $(MLX_FLAGS) -o $(NAME)
# 	@touch $(MANDATORY_MARK)

# $(BONUS_MARK): $(OBJ_BONUS)
# 	@rm -f $(MANDATORY_MARK)
# 	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_FLAGS) -o $(NAME)
# 	@touch $(BONUS_MARK)

# $(NAME): 
# 	@if [ -f $(BONUS_MARK) ]; then \
# 		$(MAKE) fclean; \
# 		$(MAKE) $(MANDATORY_MARK); \
# 	else \
# 		$(MAKE) $(MANDATORY_MARK); \
# 	fi

# bonus: $(BONUS_MARK)

# %.o: %.c $(HEADERS)
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJ_MANDATORY) $(OBJ_BONUS)
# 	rm -f $(MANDATORY_MARK) $(BONUS_MARK)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all bonus clean fclean re
# ===== COLORS ===== #
GREEN	= \033[32m
RED		= \033[31m
BLUE	= \033[34m
PURPLE	= \033[35m
CYAN	= \033[36m
YELLOW	= \033[33m
BOLD	= \033[1m
NC		= \033[0m

# ===== COMPILER & FLAGS ===== #
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -lmlx -lXext -lX11 -lm
NAME		= fractol

# ===== SOURCES & OBJECTS ===== #
SRC_MANDATORY	= main_mandatory.c init.c utils.c parse_args.c \
				  hooks_mandatory.c mandelbrot.c julia.c render_mandatory.c
SRC_BONUS		= main_bonus.c init.c utils.c parse_args_bonus.c \
				  hooks_bonus.c burningship.c tricorn.c render_bonus.c \
				  mandelbrot.c julia.c

OBJ_MANDATORY	= $(SRC_MANDATORY:.c=.o)
OBJ_BONUS		= $(SRC_BONUS:.c=.o)

HEADERS			= fractol.h fractol_bonus.h

# ===== MARKER FILES ===== #
MANDATORY_MARK	= .mandatory_mark
BONUS_MARK		= .bonus_mark

# ===== RULES ===== #
all: $(MANDATORY_MARK)

$(MANDATORY_MARK): $(OBJ_MANDATORY)
	@echo "$(PURPLE)╔══════════════════════════════════╗$(NC)"
	@echo "$(PURPLE)║$(CYAN)   ____    __    __  __  ______   $(PURPLE)║$(NC)"
	@echo "$(PURPLE)║$(CYAN)  / __/___/ /___/ / / / / / / /   $(PURPLE)║$(NC)"
	@echo "$(PURPLE)║$(CYAN) / _// __  / __  / / / / / / /    $(PURPLE)║$(NC)"
	@echo "$(PURPLE)║$(CYAN)/_/ /_/ /_/_/ /_/ /_/ /_/_/_/     $(PURPLE)║$(NC)"
	@echo "$(PURPLE)║$(CYAN)      INFINITE BEAUTY AWAITS!     $(PURPLE)║$(NC)"
	@echo "$(PURPLE)╚══════════════════════════════════╝$(NC)"
	@rm -f $(BONUS_MARK)
	@$(CC) $(CFLAGS) $(OBJ_MANDATORY) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✅ $(BOLD)MANDATORY READY!$(NC) $(YELLOW)Time to explore the fractalverse! 🌌$(NC)"
	@touch $(MANDATORY_MARK)

$(BONUS_MARK): $(OBJ_BONUS)
	@echo "$(PURPLE)╔══════════════════════════════════╗$(NC)"
	@echo "$(PURPLE)║$(CYAN)   ____    __    __  __  ______   $(PURPLE)║$(NC)"
	@echo "$(PURPLE)║$(CYAN)  / __/___/ /___/ / / / / / / /   $(PURPLE)║$(NC)"
	@echo "$(PURPLE)║$(CYAN) / _// __  / __  / / / / / / /    $(PURPLE)║$(NC)"
	@echo "$(PURPLE)║$(CYAN)/_/ /_/ /_/_/ /_/ /_/ /_/_/_/     $(PURPLE)║$(NC)"
	@echo "$(PURPLE)║$(CYAN)      BONUS FRACTALS UNLOCKED!    $(PURPLE)║$(NC)"
	@echo "$(PURPLE)╚══════════════════════════════════╝$(NC)"
	@rm -f $(MANDATORY_MARK)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(PINK)🎉 $(BOLD)BONUS MODE ACTIVATED!$(NC) $(CYAN)Extra fractals unlocked! 🚀$(NC)"
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
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)🔹 $(CYAN)Compiled:$(NC) $(YELLOW)$<$(NC)"

clean:
	@rm -f $(OBJ_MANDATORY) $(OBJ_BONUS)
	@rm -f $(MANDATORY_MARK) $(BONUS_MARK)
	@echo "$(RED)🧹 $(ORANGE)Objects vaporized!$(NC) $(WHITE)(Poof! ✨)$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)💥 $(BOLD)Executable nuked!$(NC) $(PURPLE)See you in the next dimension... 👾$(NC)"

re: fclean all
	@echo "$(GREEN)♻️  $(BOLD)REBUILD COMPLETE!$(NC) $(BLUE)System rebooted. Ready for fractal madness! 🤯$(NC)"

.PHONY: all bonus clean fclean re