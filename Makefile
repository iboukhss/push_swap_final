CC := cc
CFLAGS := -Wall -Wextra -g3 -fsanitize=address,undefined -MMD

NAME := push_swap
TEST_BIN := test_stack

SRCS := src/dbg_main.c \
        src/ps_main.c \
        src/s_stack.c \
        src/s_stack_pop.c \
        src/s_stack_push.c \
        src/tst_stack.c

INCS := src/dbg_main.h \
        src/ps_main.h

OBJS := $(SRCS:.c=.o)
DEPS := $(OBJS:.o=.d)

TEST_OBJS := $(filter-out src/ps_main.o,$(OBJS))

all: test

test: $(TEST_BIN)

$(TEST_BIN): $(TEST_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

norm:
	-norminette $(SRCS) $(INCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_BIN)

re: fclean all

-include $(DEPS)

.PHONY: test norm clean fclean re
