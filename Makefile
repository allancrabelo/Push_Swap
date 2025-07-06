NAME     = push_swap
CC       = cc
CFLAGS   = -Wall -Wextra -Werror

SRCS     = push_swap.c split.c handle_errors.c init_stack.c ready_a.c ready_b.c \
           sort.c stack_utils.c rotate.c reverse_rotate.c sort_three.c \
           push.c swap.c sort_four.c sort_five.c atol.c max.c sort_utils.c

OBJS     = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) -c $(SRCS)
	$(CC) -nostartfiles -shared -o lib$(NAME).so $(OBJS)

