SRCS = ${wildcard ./srcs/*.c}

SRCS_OBJS = ${SRCS:.c=.o}

CC = cc

HEADERS = -I./headers -I./libft

FLAGS = -Wall -Wextra -Werror $(HEADERS)

NAME = libftprintf.a

$(NAME) :  $(SRCS_OBJS)
	make -C ./libft bonus
	mv ./libft/libft.a $(NAME)
	ar -rcs $@ $^

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -f $(SRCS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

dev : all clean 
	rm -f a.out
	$(CC) $(FLAGS) main.c $(NAME)

.PHONY : all clean fclean re dev