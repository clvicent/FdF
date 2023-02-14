CC = clang

NAME = fdf

DIR_S = srcs/

LIBFT = libft

HEADER = inc/

SOURCES =   main.c \
			display_tools.c \
			grid_tools.c \
			utils.c \
			drawing_tools.c \
			tab_tools.c \
			colors.c \
			color_tools.c

SRCS = $(addprefix $(DIR_S),$(SOURCES))

OBJS = $(SRCS:.c=.o)

CFLAGS = -g3 -Wall -Werror -Wextra -I $(HEADER)

MFLAGS = -L $(LIB)mlx_linux -lmlx -lm -lX11 -lXext -lpthread

LFLAGS = -L $(LIBFT) -lft

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@ make -C $(LIBFT)
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
		./\$(NAME) maps/test2.fdf
		
#./\$(NAME) maps/test5.fdf

bonus: all

clean:
	@rm -f $(OBJS)
	@make fclean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)

re: fclean all