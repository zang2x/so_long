SRCS = so_long.c map_checks.c create_maps.c
INCLUDE = include
LIBFT = Libft
MINILIBX = minilibx-linux
FTPRINTF = ft_printf
OBJDIR = objs/
OBJS = $(SRCS:%.c=$(OBJDIR)%.o)
CC = cc -I$(INCLUDE) -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
NAME = so_long

all: lib printf mlx $(NAME)

bonus: lib printf mlx $(NAME)

lib:
	make	-C	$(LIBFT)

mlx:
	make -C $(MINILIBX)

printf:
	make -C $(FTPRINTF)

$(NAME): $(OBJS)
	make	-C	$(LIBFT)
	make -C $(MINILIBX)
	$(CC) $(OBJS) -L $(LIBFT) -lft -L $(FTPRINTF) -lftprintf -L $(MINILIBX) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(OBJDIR)%.o: %.c
	mkdir -p $(OBJDIR)
	$(CC)	-c	$<	-o	$@

clean:
	$(RM)	$(OBJS)
	rm -rf $(OBJDIR)
	make -C  $(LIBFT) clean
	make -C  $(MINILIBX) clean
	make -C $(FTPRINTF) clean

fclean: clean
	$(RM)	$(NAME)
	make -C $(LIBFT) fclean
	make -C $(MINILIBX) clean
	make -C $(FTPRINTF) fclean

re: fclean all

.PHONY: all lib clean fclean re bonus mlx