CC = clang

NAME = fdf

DIR_S = srcs/

HEADER = inc/

SOURCES =   main.c \
			utils.c \
			input_utils.c \
			tools.c \
			tools_2.c \
			tools_3.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_split.c \
			shades_and_color.c \
			printf.c \
			printf_2.c \
			printf_3.c \
			bresenham.c \
			tools_4.c

SRCS = $(addprefix $(DIR_S),$(SOURCES))

OBJS = $(SRCS:.c=.o)

CFLAGS = -g3 -Wall -Werror -Wextra -I $(HEADER)

FLAGS = -L $(LIB)mlx_linux -lmlx -lm -lX11 -lXext -lpthread

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC)	$(CFLAGS)	$(OBJS)	$(FLAGS) -o	$(NAME)

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

fclean: clean
	@rm -f $(NAME)

re: fclean all