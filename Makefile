NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRCS =	delete_functions.c ft_split.c handle_errors.c little_sorting.c main.c \
	mathematical_functions.c push_swap.c push_swap_init.c push_swap_utils.c \
	rotate_functions.c shift.c size_functions.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o:%.c
	cc -I $(CFLAGS) -o $@ -c $?

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
