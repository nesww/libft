#include <fcntl.h>
#include <libft/libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char touppercase(u32 index, char c) {
  UNUSED(index);
  return c - 0x20;
}

void tolowercase(u32 index, char *c) {
  UNUSED(index);
  *c += 0x20;
}

void del_str(void *s) { UNUSED(s); }

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
  fprintf(stdout, "\n=== Test for atoi ===\n");
  fprintf(stdout, "Test for atoi: chars: %s, result: %d\n", "-123bc",
          ft_atoi("-123bc"));

  fprintf(stdout, "\n=== Test for substr ===\n");
  const char *x = "AABXAA";
  char *res = ft_substr(x, 2, 21789);
  fprintf(stdout, "For string: %s, expected BX, had: %s\n", x, res);
  free(res);

  // strdup
  fprintf(stdout, "\n=== Test for strdup ===\n");
  const char *y = "HOLA__";
  char *yy = ft_strdup(y);
  fprintf(stdout, "%s\n", yy);
  free(yy);

  /////////////////
  fprintf(stdout, "\n=== Test for itoa ===\n");
  // test for itoa
  int toto = 125121;
  char *toto_res = ft_itoa(toto);
  fprintf(stdout, "got: %s\n", toto_res);
  free(toto_res);

  char *s1 = "AA";
  char *s2 = "BB";

  /////////////////
  fprintf(stdout, "\n=== Test for strjoin ===\n");
  char *join = ft_strjoin(s1, s2);
  printf("Result of ft_strjoin: %s\n", join);
  free(join);

  /////////////////
  fprintf(stdout, "\n=== Test for strtrim ===\n");
  char *s = "aabaabaMy name is Simonbbabba";
  char *set = "ab";
  char *trimmed = ft_strtrim(s, set);
  printf("Result of trimming the string `%s` with set `%s` => %s\n", s, set,
         trimmed);
  free(trimmed);

  /////////////////
  fprintf(stdout, "\n=== Test for split ===\n");
  char **res_split = ft_split("a,,b", ',');
  printf("Initial string: %s, sep: %c for splitting\n", "hello", 'o');
  for (u32 i = 0; i < 3; ++i)
    printf("splitted[%d] = %s\n", i, res_split[i]);
  for (u32 i = 0; i < 2; ++i) {
    free(res_split[i]);
  }
  free(res_split);

  /////////////////
  fprintf(stdout, "\n=== Test for strmapi ===\n");
  const char *tomap = "tatatiti";
  char *mapped = ft_strmapi(tomap, touppercase);
  printf("result of mapping %s= %s\n", tomap, mapped);

  /////////////////
  fprintf(stdout, "\n=== Test for striteri ===\n");
  printf("about to changed directly mapped %s\n", mapped);
  ft_striteri(mapped, tolowercase);
  printf("result of change directly: %s\n", mapped);
  free(mapped);

  /////////////////
  fprintf(stdout, "\n=== Test for putchar_fd ===\n");
  int fd_test = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0644);
  printf("fd= %d\n", fd_test);
  ft_putchar_fd('A', fd_test);

  ft_putendl_fd("TATATA", fd_test);
  ft_pubnbr_fd(6969, fd_test);

  close(fd_test);

  /////////////////
  fprintf(stdout, "\n=== Test for lstnew ===\n");
  t_list *list = ft_lstnew("Hello");
  printf("Newly created linked list element: %s, with next at: %p\n",
         ((char *)(list->content)), list->next);
  printf("list size before appending: %d\n", ft_lstsize(list));
  t_list *l2 = ft_lstnew(" World!");
  ft_lstadd_back(&list, l2);
  printf("Appended two linked list element: %s %s, with next at: %p "
         "(original address of second element, supposed to be next: %p) & %p\n",
         ((char *)(list->content)), ((char *)(l2->content)), list->next, l2,
         l2->next);
  printf("list size after appending: %d\n", ft_lstsize(list));
  ft_lstclear(&list, del_str);
}
