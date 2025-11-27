NAME = libft.a

SRCS = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strnstr.c \
	ft_strchr.c \
	ft_atoi.c

OBJ_DIR = obj

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	cc -c $(SRC)

CC = cc
CFLAGS = -g -Werror -Wall -Wextra 

OBJ = $(SRCS:.c=.o)


$(NAME): $(OBJ)
		

