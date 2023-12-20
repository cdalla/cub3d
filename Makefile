NAME = cub3d

CC = gcc

FLAGS = -Wall -Werror -Wextra #-fsanitize=address

HEADER := src/libft/libft.h

LIBFT := src/libft/libft.a

SRC =	src/main.c\
		src/utils/is_space.c\
		src/parser/parser.c\
		src/parser/copy_file.c\
		src/parser/texture_path_value.c\
		src/parser/color_value.c\
		src/parser/map_value.c\
		src/GNL/get_next_line.c\
		src/GNL/get_next_line_utils.c\
		

OBJ =	$(SRC:src/%.c=obj/%.o)
		
all: $(NAME)
	
$(NAME): $(LIBFT) $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) -o $@ $<

obj/%.o: src/%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT):
	make -C ./src/libft

clean:
	make clean -C ./src/libft/
	rm -r obj

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re