#include <libft.h>
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc < 2)
    return 1;

  char *string = argv[1];
  printf("String len calculated: %llu\n", ft_strlen(string));
}
