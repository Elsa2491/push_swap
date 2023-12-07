NAME = push_swap
PRINTF = ../printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS =	delete_functions.c ft_split.c handle_errors.c little_sorting.c main.c \
	mathematical_functions.c push_functions.c push_swap_init.c push_swap_utils.c \
	reverse_rotate_functions.c rotate_functions.c size_functions.c \
	swap_functions.c min_max_functions.c big_sorting.c exec_function.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	make -C "../printf/"
	cc $(CFLAGS) $(OBJS) -Inc $(PRINTF) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
