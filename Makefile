NAME = cub3d

CC = gcc

FLAGS = -Wall -Werror -Wextra -fsanitize=address
MLXFLAGS = -Imlxdir/include -ldl -lglfw -pthread -lm
HEADER := src/libft/libft.h

LIBFT := src/libft/libft.a
MLXLIB := mlxdir/build/libmlx42.a

SRC =  src/main.c\
        src/utils/is_space.c\
        src/utils/free_data.c\
        src/error/print_error.c\
        src/parser/parser.c\
        src/parser/copy_file.c\
        src/parser/texture_path_value.c\
        src/parser/color_value.c\
        src/parser/data_validation.c\
        src/parser/map_borders_validation.c\
        src/parser/map_value.c\
		src/render/print_map.c\
        src/render/print_roofandceil.c\
        src/GNL/get_next_line.c\
        src/GNL/get_next_line_utils.c

OBJ =  $(SRC:src/%.c=obj/%.o)
        
all: $(NAME)
    
$(NAME): $(LIBFT) $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) $(MLXLIB) $(LIBFT) $(MLXFLAGS) -o $@

obj/%.o: src/%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) -c $(FLAGS) -Imlxdir/include $< -o $@

$(LIBFT):
	make -C ./src/libft

clean:
	make clean -C ./src/libft/
	rm -rf obj

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re
