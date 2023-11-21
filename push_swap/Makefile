NAME = push_swap
CC = clang
CFLAGS = -g -Wall -Wextra -Werror -I.
SRC_DIR = src/
SRC = 	srcs/main.c \
		srcs/stack/stack_ops.c srcs/stack/stack_utility.c\
		srcs/algo/ft_algo.c srcs/algo/ft_algo_utils.c\
		srcs/algo/small/ft_quicksort.c srcs/algo/small/ft_brut_force.c\
		srcs/algo/medium/ft_medium_sort.c srcs/algo/medium/ft_medium_utils.c\
		srcs/algo/large/ft_butterfly.c srcs/algo/large/ft_butterfly_utils.c \
		srcs/parsing/ft_parsing.c \
		srcs/rules/ft_rules_a.c srcs/rules/ft_rules_b.c srcs/rules/ft_rules_all.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I includes/ -I $(LIBFT_DIR)/includes/

all: $(NAME)

bonus: all

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME) $(CFLAGS) $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf a.out
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
