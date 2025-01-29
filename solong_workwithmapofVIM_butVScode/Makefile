# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 23:27:36 by tat-nguy          #+#    #+#              #
#    Updated: 2025/01/26 23:27:42 by tat-nguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME = so_long
BONUS = so_long_bonus

# Libft
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

# MLX
MLX_DIR	= ./minilibx
MLX		= $(MLX_DIR)/libmlx.a

# Source Files
DIR_SRC	= src
DIR_BONUS = bonus

# Paths and Files
SRC = $(wildcard $(DIR_SRC)/*.c)
SRC_BONUS = $(wildcard $(DIR_BONUS)/*.c)
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# Include
INCLUDES	= -Iinclude -Iminilibx

# Compiler and Flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I/usr/X11/include
RM			= rm -rf
LIBFLAGS	= -L$(LIBFT_DIR) -lft
MLXFLAGS	= -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lX11 -lXext    

# Targets
all:	$(LIBFT) $(MLX) $(NAME)

bonus:	$(LIBFT) $(MLX)	$(BONUS)

# Build libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Build mlx
$(MLX):
	@$(MAKE) -C $(MLX_DIR)

# Build so_long
$(NAME):	$(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(INCLUDES) $(CFLAGS) $(LIBFLAGS) $(MLXFLAGS)

# Build bonus
$(BONUS):	$(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) -o $(BONUS) $(INCLUDES) $(CFLAGS) $(LIBFLAGS) $(MLXFLAGS)

# Clean
clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean:	clean
	@$(RM) $(NAME) $(BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re bonus
