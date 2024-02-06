CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g
NAME	= push_swap
SRCD	= ./source/
BONUSD	= ./bonus/
LIBFTD	= ./libft/
SRC 	= push_swap.c \
	  inputctrl_pt1.c \
	  inputctrl_pt2.c \
	  midpoint_sorting.c \
	  sorting.c \
	  conds.c \
	  conds_steps_a1.c \
	  conds_steps_a2.c \
	  conds_steps_b1.c \
	  conds_steps_b2.c \
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
