CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g
NAME	= push_swap
LIBFTD	= ./libft
SRC 	= push_swap.c \
	  operands.c
HEADER	= push_swap.h

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	make -C $(LIBFTD) all
	cp $(LIBFTD)/libft.a $(NAME)
	$(CC) $(CFLAGS) $(SRC) -L$(LIBFTD) -lft -o $(NAME)

clean:
	rm -f *.o
	make -C $(LIBFTD) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFTD) fclean

re:	fclean all

.PHONY: all re clean fclean
