CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g
NAME	= push_swap
SRCD	= ./source/
BONUSD	= ./bonus/
LIBFTD	= ./libft/
SRC 	= main.c \
	  inputctrl_pt1.c \
	  inputctrl_pt2.c \
	  midpoint_sorting.c \
	  sort_upto3.c \
	  flip_b.c \
	  flip_a.c \
	  flip_utils.c \
	  operands.c \
	  liberators.c
BNAME	= checker
BSRC	= checker.c \
	  inputctrl_pt1_bonus.c \
	  inputctrl_pt2_bonus.c \
	  sorting_bonus.c \
	  operands_bonus.c \
	  liberators_bonus.c

HEADER	= push_swap.h
BHEADER	= checker.h

all: $(NAME)

$(NAME): $(addprefix $(SRCD),$(SRC)) $(SRCD)$(HEADER)
	make -C $(LIBFTD) all
	$(CC) $(CFLAGS) $(addprefix $(SRCD),$(SRC)) -I$(SRCD) -L$(LIBFTD) -lft -o $(NAME)

bonus: $(BNAME)

$(BNAME): $(addprefix $(BONUSD),$(BSRC)) $(BONUSD)$(BHEADER)
	$(CC) $(CFLAGS) $(addprefix $(BONUSD),$(BSRC)) -I$(BONUSD) -L$(LIBFTD) -lft -o $(BNAME)

clean:
	make -C $(LIBFTD) clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(BNAME)
	make -C $(LIBFTD) fclean

re:	fclean all

.PHONY: all re clean fclean bonus
