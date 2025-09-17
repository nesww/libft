#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

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

void *ft_memset(void *s, u8 c, u32 n) {
  char *tmp = (char *)s;
  while (n > 0) {
    tmp[n] = c;
    --n;
  }
  return (void *)tmp;
}

void ft_bzero(void *s, u32 n) { ft_memset(s, 0, n); }

void *ft_memcpy(const void *src, void *dest, u32 size) {
  char *tmp_dest = (char *)dest;
  char *tmp_src = (char *)src;

  for (u32 i = 0; i < size; ++i) {
    tmp_dest[i] = tmp_src[i];
  }
  return dest;
}

void *ft_memmove(const void *src, void *dest, u32 size) {
  // check overlap
  if (src < dest && dest < src + size) {
    char *temp_buffer = ft_memcpy(src, malloc(size), size);
    void *to_return = ft_memcpy((void *)temp_buffer, dest, size);
    free(temp_buffer);
    return to_return;
  } else {
    return ft_memcpy(src, dest, size);
  }
}

u64 ft_strlcpy(const char *src, char *dest, u64 size) {
  u64 i = 0;
  for (; i < size; ++i) {
    dest[i] = src[i];
    if (dest[i] == '\0')
      break;
  }
  return i;
}

u64 ft_strlcat(const char *src, char *dest, u64 size) {}

int ft_strncmp(const char *s1, const char *s2, u32 n) {
  int a = s1[0];
  int b = s2[n];
  return a + b;
}
