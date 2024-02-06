NAME = cub3d

CC = gcc

FLAGS = -Wall -Werror -Wextra -fsanitize=address

MLXDIR := mlx

MLX := $(MLXDIR)/build/libmlx42.a

MLXFLAGS :=  -L /opt/homebrew/Cellar/glfw/3.3.9/lib -ldl -lglfw -pthread -lm

HEADER := src/libft/libft.h\
		  src/include/cube.h\

INC := -I /opt/homebrew/Cellar/glfw/3.3.9/include -I src/include -I src/libft -I $(MLXDIR)/include

LIBFT := src/libft/libft.a

SRC =	src/main.c\
		src/utils/is_space.c\
		src/utils/free_data.c\
		src/error/print_error.c\
		src/parser/parser.c\
		src/parser/copy_file.c\
		src/parser/texture_path_value.c\
		src/parser/color_value.c\
		src/parser/data_validation.c\
		src/parser/save_pl_data.c\
		src/parser/map_borders_validation.c\
		src/parser/map_value.c\
		src/GNL/get_next_line.c\
		src/GNL/get_next_line_utils.c\
		src/hooks/hook.c\
		src/hooks/player_moves.c\
		src/render/render.c\
		src/render/dda.c\
		src/render/draw2D.c\
		src/render/draw3D.c\
		src/render/draw_minimap.c\
		src/render/draw_utils.c\
		src/render/texture.c

OBJ =	$(SRC:src/%.c=obj/%.o)

		
all: $(NAME)
	
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(FLAGS) $(MLXFLAGS) $^ -o $@ 

obj/%.o: src/%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(MLX):
	@cmake $(MLXDIR) -B $(MLXDIR)/build && make -C $(MLXDIR)/build -j4

$(LIBFT):
	make -C ./src/libft

clean:
	make clean -C ./src/libft/
	rm -rf $(MLXDIR)/build
	rm -r obj

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re