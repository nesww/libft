#include <libft.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc < 2)
    return 1;

  fprintf(stdout, "=== Test for strlen ===\n");
  char *string = argv[1];
  printf("String len calculated: %llu\n", ft_strlen(string));

  // test strnstr
  fprintf(stdout, "\n=== Test for strnstr ===\n");
  char *big = "TotoTataTiti";
  char *little = "Tta";
  const char *found = ft_strnstr(big, little, ft_strlen(big));
  fprintf(stdout, "Big address : %p, found address for little: %p, diff: %ld\n",
          big, found, found - big);

  fprintf(stdout, "Test for int cast for a char: had %c, casted to int: %d \n",
          '2', (int)'2');

  fprintf(stdout, "Test for atoi: chars: %s, result: %d\n", "-123bc",
          ft_atoi("-123bc"));

  const char *x = "AABXAA";
  char *res = ft_substr(x, 2, 21789);
  fprintf(stdout, "For string: %s, expected BX, had: %s\n", x, res);

  // strdup
  const char *y = "HOLA__";
  char *yy = ft_strdup(y);
  fprintf(stdout, "%s\n", yy);
  free(yy);
}
