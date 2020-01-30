NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_printf_utils.c convert.c convert_print.c \
			convert_utils.c flags.c ft_atoi.c utils.c convert_print2.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all