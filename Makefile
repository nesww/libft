FLAGS=-Wall -Wextra -Werror
NAME=libft.a

all: clean fclean re

clean:
	rm -rf $(NAME)

fclean:
	rm -rf *.o *.a

re: libft.h libft.c
	gcc $(FLAGS) -c -o libft.o libft.c
	ar rcs libft.a libft.o

