FLAGS=-Wall -Wextra -Werror
NAME=libft.a

BUILD_DIR=build/
INCLUDE_DIR=include/
SOURCE_DIR=src/


OS := $(shell uname -s)

ifeq ($(OS), Darwin)
INSTALL_PREFIX_PATH=/usr/local
else
INSTALL_PREFIX_PATH=/usr
endif

INSTALL_INCLUDE_DIR=$(INSTALL_PREFIX_PATH)/include/libft
all: clean build install test

clean:
	rm -rf $(BUILD_DIR)/*.a
	rm -rf $(BUILD_DIR)/*.o
	rm -rf *.o
	rm -rf test

build: $(INCLUDE_DIR)* $(SOURCE_DIR)libft.c
	gcc $(FLAGS) -c -g -o $(BUILD_DIR)libft.o $(SOURCE_DIR)libft.c
	ar rcs $(BUILD_DIR)libft.a $(BUILD_DIR)libft.o

uninstall:
	sudo rm -f $(INSTALL_INCLUDE_DIR)/*
	sudo rm -f $(INSTALL_PREFIX_PATH)/lib/libft.a

install: build 
	echo $(OS)
	sudo mkdir -p $(INSTALL_INCLUDE_DIR)
	sudo cp $(INCLUDE_DIR)* $(INSTALL_INCLUDE_DIR)
	sudo cp $(BUILD_DIR)libft.a $(INSTALL_PREFIX_PATH)/lib/

test: install test.c
	gcc $(FLAGS) -g test.c -o test -lft

