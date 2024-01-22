NAME = push_swap
PRINTF = ../printf/libftprintf.a
PRINTF_SGOINFRE = ../../sgoinfre/printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror -g3
SRCS =	delete_functions.c ft_split.c handle_errors.c little_sorting.c main.c \
	mathematical_functions.c push_functions.c push_swap_init.c push_swap_utils.c \
	reverse_rotate_functions.c rotate_functions.c size_functions.c \
	swap_functions.c min_max_functions.c big_sorting.c exec_function.c \
	check_params.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

foo-default:
	echo 'foo-default'

bar-default:
	echo 'bar-default'

%: %-default
	@ true

$(NAME):$(OBJS)
	ifeq ($(PRINTF_SGOINFRE), 1)
	make -C "../../sgoinfre/printf/"
	cc $(CFLAGS) $(OBJS) -Inc $(PRINTF_SGOINFRE) -o $(NAME)
	endif 

$(NAME):$(OBJS)
	make -C "../printf/"
	cc $(CFLAGS) $(OBJS) -Inc $(PRINTF) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
