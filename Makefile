NAME		= libftprintf.a

HDRS_DIR	= ./includes/
SRCS_DIR	= ./srcs/

SRC		= ft_printf.c \
		ft_putlchar.c ft_putlstr.c \
		ft_putlptr.c \
		ft_putlnbr.c ft_putlnbrbase.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))
OBJS		= $(SRCS:%.c=%.o)


all:		$(NAME)

$(NAME):	$(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o:		%.c
	cc -Wall -Werror -Wextra -c -I $(HDRS_DIR) $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
