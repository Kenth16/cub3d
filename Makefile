NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SRC_DIR = src
OBJ_DIR = obj
MLX_DIR = includes/minilibx-linux
LIBFTDIR = includes/libft

MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT = $(LIBFTDIR)/libft.a

SRCS = $(SRC_DIR)/main.c\
	$(SRC_DIR)/get_next_line.c\
	$(SRC_DIR)/ft_free.c\
	$(SRC_DIR)/map_parsing.c\
	$(SRC_DIR)/free_struct.c\
	$(SRC_DIR)/parsing.c\
	$(SRC_DIR)/textures_fonctions.c\
	$(SRC_DIR)/colors_fonctions.c


OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR) bonus

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX_LIB) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -L$(LIBFTDIR) -lft -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(MLX_LIB)

re: fclean $(NAME)

.PHONY: all clean fclean re

