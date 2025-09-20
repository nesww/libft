FLAGS=-Wall -Wextra -Werror
NAME=libft.a

BUILD_DIR=build/
INCLUDE_DIR=include/
SOURCE_DIR=src/
all: clean fclean re lib test

clean:
	rm -rf $(NAME)
	rm -rf test

fclean:
	rm -rf $(BUILD_DIR)*.o $(BUILD_DIR)*.a

re: $(INCLUDE_DIR)libft.h $(SOURCE_DIR)libft.c
	gcc $(FLAGS) -c -g -o $(BUILD_DIR)libft.o $(SOURCE_DIR)libft.c
	ar rcs $(BUILD_DIR)libft.a $(BUILD_DIR)libft.o

unlib:
	sudo rm -f /usr/include/libft.h
	sudo rm -f /usr/lib/libft.a

lib: 
	sudo cp $(INCLUDE_DIR)libft.h /usr/include/
	sudo cp $(BUILD_DIR)libft.a /usr/lib/

test: lib test.c
	gcc $(FLAGS) -g test.c -o test -lft

