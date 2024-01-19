CC	= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= push_swap.a
LIBFTD	= ./libft
SRC 	= push_swap.c
OBJ	= $(SRC:.c=.o)
HEADER	= push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTD) all
	cp $(LIBFTD)/libft.a $(NAME)
	ar rcs $(NAME) $^

$(OBJ): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	make -C $(LIBFTD) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFTD) fclean

re:	fclean all

.PHONY: all re clean fclean
