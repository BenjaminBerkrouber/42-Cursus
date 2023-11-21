NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src/
SRC = 			ft_atoi.c ft_isprint.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c \
				ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strlcat.c ft_substr.c \
				ft_calloc.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c \
				ft_isalnum.c ft_putstr_fd.c ft_strlen.c ft_toupper.c \
				ft_isalpha.c ft_memchr.c ft_strmapi.c \
				ft_isascii.c ft_memcmp.c ft_split.c ft_strncmp.c \
				ft_isdigit.c ft_memcpy.c ft_strchr.c ft_strnstr.c \
				ft_memmove.c ft_strdup.c ft_strrchr.c ft_memset.c ft_striteri.c
OBJ = 			$(SRC:.c=.o)
BONUS_SRC = 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
				ft_lstiter.c ft_lstmap.c
BONUS_OBJ = 	$(BONUS_SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $(OBJ) $(BONUS_OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
