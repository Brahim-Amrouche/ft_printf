SRCS = $
{
	wildcard./ srcs/*.c}

LIBFT_SRCS = ${wildcard ./libft/*.c}

SRCS_OBJS = ${SRCS:.c=.o}

LIBFT_OBJS = ${LIBFT_SRCS:.c=.o}

CC = cc

HEADERS = -I./headers 

FLAGS = -Wall -Wextra -Werror -fsanitize=address $(HEADERS)

NAME = libftprintf.a

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(SRCS_OBJS) $(LIBFT_OBJS)
	ar -rcs $@ $^

clean :
	rm -f $(SRCS_OBJS) $(LIBFT_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re	