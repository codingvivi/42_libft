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
PTH_BLD_TEST = $(PTH_BLD)/test
PTH_BLD_TEST_OBJ = $(PTH_BLD_TEST)/obj
PTH_BLD_TEST_BIN = $(PTH_BLD_TEST)/bin
PTH_BLD_TEST_RUNSRC = $(PTH_BLD_TEST)/runner_src
PTH_BLD_UNITY = $(PTH_BLD)/unity
PTH_BLD_UNITY_OBJ = $(PTH_BLD_UNITY)/obj

ifeq ($(OSTYPE),cygwin)
	CMD_CLEAN=rm -f
	CMD_MKPTH=mkdir -p
	TARGET_EXTENSION=.out
else ifeq ($(OS),Windows_NT)
	CMD_CLEAN=del /F /Q
	MKPTH=mkdir
	TARGET_EXTENSION=.exe
else
	CMD_CLEAN=rm -f
	CMD_MKPTH=mkdir -p
	TARGET_EXTENSION=.out
endif

CMD_RUNGEN = unity/auto/generate_test_runner.rb



SRCS = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \

SRCS_TO_ADD = \
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

.PHONY: all clean fclean re

OBJS = $(addprefix $(PTH_BLD_OBJ)/, $(SRCS:.c=.o))

all: $(NAME)

# create lib
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "created $(NAME)"

#compile
$(PTH_BLD_OBJ)/%.o:: $(PTH_SRC)/%.c | $(PTH_BLD_OBJ)
	$(CC) $(CFLAGS) -I. -c $< -o $@

.PHONY: test test-all


TEST_BINS = $(addprefix $(PTH_BLD_TEST_BIN)/, $(addsuffix $(TARGET_EXTENSION), $(patsubst %.c,test_%_Runner,$(SRCS)))))

test:
	@$(MAKE) test-all

test-all: $(TEST_BINS)
	@echo "Running all tests"
	@for test_bin in $(TEST_BINS); do \
		./$$test_bin; \
	done


#link tests
$(PTH_BLD_TEST_BIN)/test_%_Runner.$(TARGET_EXTENSION): $(NAME) $(PTH_BLD_TEST_OBJ)/test_%_Runner.o $(PTH_BLD_UNITY_OBJ)/unity.o | $(PTH_BLD_TEST_BIN)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

#compile runner
$(PTH_BLD_TEST_OBJ)/test_%_Runner.o: $(PTH_BLD_TEST_RUNSRC)/test_%_Runner.c | $(PTH_BLD_TEST_OBJ)
	$(CC) $(CFLAGS) -I./$(PTH_SRC_UNITY) -I. -c $< -o $@

# generate runner code
$(PTH_BLD_TEST_RUNSRC)/test_%_Runner.c: $(PTH_SRC_TEST)/test_%.c | $(PTH_BLD_TEST_RUNSRC)
	@echo "generating runner for"
	@ruby $(CMD_RUNGEN) $< $@


# compile unity
$(PTH_BLD_UNITY_OBJ)/unity.o: $(PTH_SRC_UNITY)/unity.c $(PTH_SRC_UNITY)/unity.h | $(PTH_BLD_UNITY_OBJ)
	$(CC) $(CFLAGS) -I$(PTH_SRC_UNITY) -c $< -o $@ 

$(PTH_BLD_OBJ) $(PTH_BLD_UNITY_OBJ) $(PTH_BLD_TEST_RUNSRC) $(PTH_BLD_TEST_OBJ) $(PTH_BLD_TEST_BIN):
	@$(CMD_MKPTH) $@
