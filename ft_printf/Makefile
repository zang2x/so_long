NAME = libftprintf.a

CC = cc

AR = ar

ARFLAGS = rcs

CFILES = ft_printf.c ft_printf_utils.c

HEADER_DIR = /

OBJ = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I $(HEADER_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):$(OBJ)
	@echo "Compiling $(NAME) and creating object files..."
	ar rcs $(NAME) $(OBJ)

clean:
	@echo "Removing object files..."
	@rm -f $(OBJ)
fclean: clean
	@echo "Removing $(NAME) .exe..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re