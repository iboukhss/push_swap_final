# Compiler options
CC            := cc
CFLAGS        := -Wall -Wextra -Werror
DEBUG_CFLAGS  := -Wall -Wextra -g3 -fsanitize=address,undefined -MMD

# Project files
PROJ_NAME     := push_swap
PROJ_MAIN     := src/ps_main.c
PROJ_SRCS     := src/s_stack.c \
                 src/s_stack_pop.c \
                 src/s_stack_push.c \
                 src/s_sort.c
PROJ_INCS     := src/ps_main.h \
                 src/s_stack.h

# Debug files
DEBUG_NAME    := ps_debug
DEBUG_SRCS    := src/dbg_main.c
DEBUG_INCS    := src/dbg_main.h

# Test files
TEST_NAME     := ps_test
TEST_MAIN     := src/tst_main.c
TEST_SRCS     := src/tst_stack.c
TEST_INCS     := src/tst_main.h

# Objects and dependencies
COMMON_OBJS   := $(PROJ_SRCS:.c=.o)
PROJ_OBJS     := $(PROJ_MAIN:.c=.o) $(COMMON_OBJS)
DEBUG_OBJS    := $(PROJ_OBJS:.o=.dbg.o) $(DEBUG_SRCS:.c=.dbg.o)
TEST_OBJS     := $(TEST_MAIN:.c=.dbg.o) $(TEST_SRCS:.c=.dbg.o) $(COMMON_OBJS:.o=.dbg.o)
ALL_DEPS      := $(PROJ_OBJS:.o=.d) $(DEBUG_OBJS:.o=.d) $(TEST_OBJS:.o=.d)

# Suffixes
.SUFFIXES: .c .o .dbg.o

# Default target
all: debug test

release: $(PROJ_NAME)

debug: $(DEBUG_NAME)

test: $(TEST_NAME)
	./$(TEST_NAME)

# Binary targets
$(PROJ_NAME): $(PROJ_OBJS)
	$(CC) $(CFLAGS) $(PROJ_OBJS) -o $@

$(DEBUG_NAME): $(DEBUG_OBJS)
	$(CC) $(DEBUG_CFLAGS) $(DEBUG_OBJS) -o $@

$(TEST_NAME): $(TEST_OBJS)
	$(CC) $(DEBUG_CFLAGS) $(TEST_OBJS) -o $@

# Suffix rules
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.c.dbg.o:
	$(CC) $(DEBUG_CFLAGS) -c $< -o $@

# Phony rules
norm:
	-norminette $(PROJ_SRCS) $(PROJ_INCS)

clean:
	rm -rf src/*.o src/*.dbg.o src/*.d

fclean: clean
	rm -f $(PROJ_NAME) $(DEBUG_NAME) $(TEST_NAME)

re: fclean all

-include $(ALL_DEPS)

.PHONY: all release debug test norm clean fclean re
