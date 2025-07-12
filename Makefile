NAME        = push_swap
BONUS       = checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRCS        = push_swap.c split.c handle_errors.c init_stack.c ready_a.c ready_b.c \
              sort.c stack_utils.c rotate.c reverse_rotate.c sort_three.c \
              push.c swap.c sort_four.c sort_five.c atol.c max.c sort_utils.c

BONUS_SRCS  = split.c handle_errors.c init_stack.c ready_a.c ready_b.c \
              sort.c stack_utils.c rotate.c reverse_rotate.c sort_three.c \
              push.c swap.c sort_four.c sort_five.c atol.c max.c sort_utils.c \
              checker_bonus.c get_next_line.c get_next_line_utils.c

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) -c $(SRCS)
	$(CC) -nostartfiles -shared -o lib$(NAME).so $(OBJS)
