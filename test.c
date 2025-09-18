#include <libft.h>
#include <stdio.h>

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

  ft_atoi(NULL);
}
