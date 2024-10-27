NAME		= libftprintf.a

SRCS_DIR	= ./srcs/
HDR_DIR		= ./includes/

SRC		= ft_printf.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))
OBJS		= $(SRC:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS)
	ar -rc $(NAME) $(OBJS)

.c.o:
	cc -Wall -Werror -Wextra -c -I $(HEAD_DIR) $< -o $(<:.c=.o)

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
