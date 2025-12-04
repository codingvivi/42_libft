
CC = cc
CFLAGS = -g -Werror -Wall -Wextra
LDFLAGS =
LDLIBS =

NAME = libft.a

PTH_SRC = .
PTH_SRC_UNITY = unity/src
PTH_SRC_TEST = test

PTH_BLD = build
PTH_BLD_OBJ = $(PTH_BLD)/obj
PTH_BLD_UNITY = $(PTH_BLD)/unity
PTH_BLD_UNITY_OBJ = $(PTH_BLD_UNITY)/obj
PTH_BLD_TEST = $(PTH_BLD)/test
PTH_BLD_TEST_RUNSRC = $(PTH_BLD_TEST)/runner_src
PTH_BLD_TEST_OBJ = $(PTH_BLD_TEST)/obj
PTH_BLD_TEST_BIN = $(PTH_BLD_TEST)/bin

ifeq ($(OSTYPE),cygwin)
	CMD_CLEAN = rm -f
	CMD_MKPTH = mkdir -p
	TARGET_EXTENSION = .out
else ifeq ($(OS),Windows_NT)
	CMD_CLEAN = del /F /Q
	CMD_MKPTH = mkdir
	TARGET_EXTENSION = .exe
else
	CMD_CLEAN = rm -f
	CMD_MKPTH = mkdir -p
	TARGET_EXTENSION = .out
endif

CMD_RUNGEN = unity/auto/generate_test_runner.rb

#SRCS = $(wildcard $(PTH_SRC)/*.c)

SRCS = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \


SRCS_TO_ADD = \
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

OBJS = $(addprefix $(PTH_BLD_OBJ)/, $(SRCS:.c=.o))
#$(info $(OBJS))

TEST_SRC_FILES = $(wildcard $(PTH_SRC_TEST)/test_*.c)
TEST_NAMES = $(patsubst $(PTH_SRC_TEST)/test_%.c,%,$(TEST_SRC_FILES))
TEST_BINS = $(addprefix $(PTH_BLD_TEST_BIN)/,$(addsuffix _Runner$(TARGET_EXTENSION),$(TEST_NAMES)))

.PRECIOUS: $(PTH_BLD_TEST_RUNSRC)/test_%_Runner.c $(PTH_BLD_TEST_OBJ)/test_%.o $(PTH_BLD_TEST_OBJ)/test_%_Runner.o

.PHONY: all clean fclean re test test-all

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "Created $(NAME)"

$(PTH_BLD_OBJ)/%.o: $(PTH_SRC)/%.c | $(PTH_BLD_OBJ)
	$(CC) $(CFLAGS) -I. -c $< -o $@

test: test-all

test-all: $(TEST_BINS)
	@echo "Running all tests...\n"
	@for test_bin in $(TEST_BINS); do \
		echo "===> Running: $$test_bin"; \
		./$$test_bin || exit 1; \
		echo "\n"; \
	done

$(PTH_BLD_TEST_BIN)/%_Runner$(TARGET_EXTENSION): $(PTH_BLD_TEST_OBJ)/test_%.o $(NAME) $(PTH_BLD_TEST_OBJ)/test_%_Runner.o $(PTH_BLD_UNITY_OBJ)/unity.o | $(PTH_BLD_TEST_BIN)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(PTH_BLD_TEST_OBJ)/test_%.o: $(PTH_SRC_TEST)/test_%.c | $(PTH_BLD_TEST_OBJ)
	$(CC) $(CFLAGS) -I. -I$(PTH_SRC_UNITY) -I$(PTH_SRC_TEST) -c $< -o $@

$(PTH_BLD_TEST_OBJ)/test_%_Runner.o: $(PTH_BLD_TEST_RUNSRC)/test_%_Runner.c | $(PTH_BLD_TEST_OBJ)
	$(CC) $(CFLAGS) -I. -I$(PTH_SRC_UNITY) -I$(PTH_SRC_TEST) -c $< -o $@

$(PTH_BLD_TEST_RUNSRC)/test_%_Runner.c: $(PTH_SRC_TEST)/test_%.c | $(PTH_BLD_TEST_RUNSRC)
	@echo "Generating runner for $<..."
	@ruby $(CMD_RUNGEN) $< $@

$(PTH_BLD_UNITY_OBJ)/unity.o: $(PTH_SRC_UNITY)/unity.c | $(PTH_BLD_UNITY_OBJ)
	$(CC) $(CFLAGS) -I$(PTH_SRC_UNITY) -c $< -o $@

$(PTH_BLD_OBJ) $(PTH_BLD_UNITY_OBJ) $(PTH_BLD_TEST_RUNSRC) $(PTH_BLD_TEST_OBJ) $(PTH_BLD_TEST_BIN):
	@$(CMD_MKPTH) $@

clean:
	@echo "Cleaning intermediate files..."
	@$(CMD_CLEAN) $(OBJS)
	@$(CMD_CLEAN) -r $(PTH_BLD_TEST) 

fclean: clean
	@echo "Cleaning all build artifacts..."
	@$(CMD_CLEAN) $(NAME)
	@$(CMD_CLEAN) -r $(PTH_BLD) 

re: fclean all
