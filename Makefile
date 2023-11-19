NAME = push_swap.a
CFLAGS = -Wall -Wextra -Error
SRC = 

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	ar -rsc $(NAME) $(OBJS)
%.o:%.c
	cc -I $(FLAGS) -o $@ -c $?

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
