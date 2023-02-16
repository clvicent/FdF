CC = clang

NAME = fdf

DIR_S = srcs
DIR_O = obj
HEADER = inc/
RM = rm -rf

LIBFT = libft
MLX = mlx_linux

SOURCES =   main.c \
			display_tools.c \
			grid_tools.c \
			utils.c \
			drawing_tools.c \
			tab_tools.c \
			colors.c \
			color_tools.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

CFLAGS = -g3 -Wall -Werror -Wextra -I $(HEADER)

MFLAGS = -L $(LIB)mlx_linux -lmlx -lm -lX11 -lXext -lpthread

LFLAGS = -L $(LIBFT) -lft

all: $(NAME)

$(OBJS) : $(DIR_O)/%.o : $(DIR_S)/%.c
		@mkdir -p $(dir $@)
# $(CC) $(CFLAGS) -c $< -o $@
		$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	@make -C $(LIBFT)
	@make -C $(MLX)
	$(CC)	$(CFLAGS)	$(OBJS)	$(MFLAGS) $(LFLAGS) -o	$(NAME)

norme:
	@echo
	norminette	./$(HEADER)
	@echo
	norminette	./$(DIR_S)

val:
	make -s -j all
	valgrind				\
		--show-leak-kinds=all	\
		--track-origins=yes		\
		--leak-check=full		\
		./\$(NAME) maps/maps_test/42.fdf
		
#./\$(NAME) maps/test5.fdf

bonus: all

clean:
	$(RM) $(DIR_O)
	@make clean -C $(MLX)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	@make clean -C $(MLX)
	@make fclean -C $(LIBFT)

re: fclean all