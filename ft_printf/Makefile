SRCS =  ft_printe.c\
		ft_printf.c\
		ft_printnb.c\
		ft_putnbr_base.c\
		ft_string.c\
		print_ptr.c\
		print_unsigned.c\
		limk.c


CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus