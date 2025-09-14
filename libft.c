#include "libft.h"
#include <stdio.h>

u8 ft_isalpha(u8 c) { return (c > 0x40 && c < 0x5B) || (c > 0x60 && c < 0x7B); }

u8 ft_isdigit(u8 c) { return c > 0x2F && c < 0x3A; }

u8 ft_isalnum(u8 c) { return ft_isalpha(c) || ft_isdigit(c); }

u8 ft_isascii(u8 c) { return c <= 0x7F; }

u8 ft_isprint(u8 c) { return c >= 0x20 && c <= 0x7E; }

u64 ft_strlen(const char *s) {
  u32 counter = 0;
  while (counter < STRLEN_MAX || ft_strncmp("\0", s + counter, 1)) {
    ++counter;
  }
  if (counter >= STRLEN_MAX) {
    fprintf(stderr,
            "(libft) E: in strlen -> counter exceeded max value for string "
            "input (had %u, had %d",
            counter, STRLEN_MAX);
    return -1;
  }
  return counter;
}

int ft_strncmp(const char *s1, const char *s2, u32 n) {
  int a = s1[0];
  int b = s2[n];
  return a + b;
}
