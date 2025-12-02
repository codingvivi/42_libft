#
# Compiler and flags
#
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

#
# Library name
#
NAME = libft.a

#
# Directories
#
UNITY_DIR      = unity
SRC_DIR        = .
BUILD_DIR      = build
OBJ_DIR        = $(BUILD_DIR)/obj
TEST_DIR       = test
TEST_BUILD_DIR = $(BUILD_DIR)/test

#
# OS-specific commands (for portability)
#
ifeq ($(OSTYPE),cygwin)
	CLEAN_CMD  = rm -f
	MKDIR_CMD  = mkdir -p
	TARGET_EXT = .out
else ifeq ($(OS),Windows_NT)
	CLEAN_CMD  = del /F /Q
	MKDIR_CMD  = mkdir
	TARGET_EXT = .exe
else
	CLEAN_CMD  = rm -f
	MKDIR_CMD  = mkdir -p
	TARGET_EXT = .out
endif

# --- Source Files ---

# Use wildcard to automatically find all .c files in the root directory.
# Add any new ft_*.c files and they will be included automatically.
SRCS = $(wildcard ft_*.c)

# Generate object file list from sources (e.g., build/obj/ft_isalpha.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))


# --- Main Library Rules ---

.PHONY: all clean fclean re

all: $(NAME)

# Rule to create the static library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created."

# Pattern rule to compile source files into object files
# -I. tells the compiler to look for headers in the root project directory.
# The `| $(OBJ_DIR)` is an order-only prerequisite to ensure the directory exists.
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@


# --- Testing Rules ---

.PHONY: test test-all

# Get base names from sources for tests (e.g., atoi, isalpha)
TEST_NAMES  := $(patsubst ft_%.c,%,$(SRCS))

# List of final test executables (e.g., build/test/atoi.out)
TEST_EXECS  := $(addprefix $(TEST_BUILD_DIR)/, $(addsuffix $(TARGET_EXT), $(TEST_NAMES)))

# Path to the Unity runner generator script
UNITY_RUN_GEN := $(UNITY_DIR)/auto/generate_test_runner.rb
# Source for the Unity framework itself
UNITY_SRC     := $(UNITY_DIR)/src/unity.c
# Include paths needed for compiling tests
TEST_INCLUDES := -I. -I$(UNITY_DIR)/src -I$(TEST_DIR)

# Main entry point for testing
# Usage:
#   make test         (runs all tests)
#   make test T=atoi  (runs a single test for ft_atoi.c)
test:
ifdef T
	@$(MAKE) $(TEST_BUILD_DIR)/$(T)$(TARGET_EXT) && ./$(TEST_BUILD_DIR)/$(T)$(TARGET_EXT)
else
	@$(MAKE) test-all
endif

# Rule to run all test executables
test-all: $(TEST_EXECS)
	@echo "\nRunning all tests..."
	@for test_exec in $(TEST_EXECS); do \
		./$$test_exec; \
	done

# Pattern rule to build a single test executable.
# It depends on the test file, the generated runner, and the library.
# Example: make build/test/atoi.out
$(TEST_BUILD_DIR)/%$(TARGET_EXT): $(TEST_DIR)/test_ft_%.c $(TEST_BUILD_DIR)/runners/ft_%_Runner.c $(NAME)
	@echo "Compiling and linking test for $*..."
	$(CC) $(CFLAGS) $(TEST_INCLUDES) -o $@ $(filter %.c,$^) $(UNITY_SRC) -L. -l$(NAME:lib%.a=%) 

# Pattern rule to auto-generate the runner C file using the provided ruby script.
# Example: make build/test/runners/ft_atoi_Runner.c
$(TEST_BUILD_DIR)/runners/ft_%_Runner.c: $(TEST_DIR)/test_ft_%.c | $(TEST_BUILD_DIR)/runners
	@echo "Generating runner for test_$*..."
	@ruby $(UNITY_RUN_GEN) $< $@


# --- Directory Creation and Cleanup ---

# This target creates all necessary build directories
$(OBJ_DIR) $(TEST_BUILD_DIR) $(TEST_BUILD_DIR)/runners:
	$(MKDIR_CMD) $@

# Standard clean rules
clean:
	@$(CLEAN_CMD) $(OBJS)
	@$(CLEAN_CMD) $(TEST_EXECS)
	@$(CLEAN_CMD) -r $(TEST_BUILD_DIR) 2>/dev/null || true

fclean: clean
	@$(CLEAN_CMD) $(NAME)
	@$(CLEAN_CMD) -r $(BUILD_DIR) 2>/dev/null || true

re: fclean all
