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
  while (s[counter] != '\0') {
    ++counter;
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
  char *d = (char *)dest;
  const char *s = (const char *)src;

  if (d < s) {
    for (u32 i = 0; i < size; i++) {
      d[i] = s[i];
    }
  } else {
    for (u32 i = size; i > 0; i--) {
      d[i - 1] = s[i - 1];
    }
  }
  return dest;
}

u64 ft_strlcpy(const char *src, char *dest, u64 size) {
  u64 i = 0;
  // TODO: add check for destination buffer size compared to source buffer size
  // (prevent segfault on destination)
  for (; i < size; ++i) {
    dest[i] = src[i];
    if (dest[i] == '\0')
      break;
  }
  return i;
}

u64 ft_strlcat(const char *src, char *dest, u64 size) {
  u32 dest_len = 0;
  while (dest_len < size && dest[dest_len] != '\0') {
    ++dest_len;
  }

  if (dest_len >= size)
    return dest_len;

  u32 i;
  for (i = 0; i < size - dest_len; ++i) {
    dest[dest_len + i] = src[i];
    if (src[i] == '\0')
      break;
  }
  return i;
}

u8 ft_toupper(u8 c) { return c - 0x20; }
u8 ft_tolower(u8 c) { return c + 0x20; }

const char *ft_strchr(const char *s, u8 c) {
  u32 counter = 0;
  while (s[counter] != '\0') {
    if (s[counter] == c)
      return &s[counter];
    ++counter;
  }
  return NULL;
}

const char *ft_strrchr(const char *s, u8 c) {
  u32 counter = ft_strlen(s) - 1;
  while (counter != 0) {
    if (s[counter] == c)
      return &s[counter];
    --counter;
  }
  if (s[0] == c)
    return &s[0];
  return NULL;
}

int ft_strncmp(const char *s1, const char *s2, u32 n) {
  u64 len_s1 = ft_strlen(s1);
  if (len_s1 < n) {
    fprintf(stderr, "(libft) ft_strncmp: s1 provided shorter than n (%llu, %u)",
            len_s1, n);
    exit(1);
  }

  u64 len_s2 = ft_strlen(s2);
  if (len_s2 < n) {
    fprintf(stderr, "(libft) ft_strncmp: s2 provided shorter than n (%llu, %u)",
            len_s2, n);
    exit(1);
  }

  u8 sum_s1 = 0;
  for (u32 i = 0; i < n; ++i) {
    sum_s1 += s1[i];
  }

  u8 sum_s2 = 0;
  for (u32 i = 0; i < n; ++i) {
    sum_s2 += s2[i];
  }
  return sum_s1 - sum_s2;
}
