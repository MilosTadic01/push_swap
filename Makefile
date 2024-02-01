CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g
NAME	= push_swap
SRCD	= ./source/
LIBFTD	= ./libft/
SRC 	= push_swap.c \
	  inputctrl_pt1.c \
	  inputctrl_pt2.c \
	  sorting.c \
	  conds.c \
	  conds_steps_a1.c \
	  conds_steps_a2.c \
	  conds_steps_b1.c \
	  conds_steps_b2.c \
	  operands.c \
	  liberators.c
HEADER	= push_swap.h

all: $(NAME)

$(NAME): $(addprefix $(SRCD),$(SRC)) $(SRCD)$(HEADER)
	make -C $(LIBFTD) all
	$(CC) $(CFLAGS) $(addprefix $(SRCD),$(SRC)) -I$(SRCD) -L$(LIBFTD) -lft -o $(NAME)

clean:
	rm -f $(SRCD)*.o
	make -C $(LIBFTD) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFTD) fclean

re:	fclean all

.PHONY: all re clean fclean
