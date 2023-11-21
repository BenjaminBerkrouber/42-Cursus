NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src/
SRC = 			srcs/printf.c \
				srcs/bonus/printf_utility.c \
				srcs/utility/ft_charset.c \
				srcs/print/ft_putnbr.c srcs/print/ft_putpointeur.c srcs/print/ft_putstr.c srcs/print/ft_putnbr_utils.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I includes/ -I $(LIBFT_DIR)/includes/

all: $(NAME)

bonus: all

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)

re: fclean all

.PHONY: all clean fclean re