#include <errno.h>
#include <libft.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

const void *ft_memchr(const void *s, u8 c, u32 n) {
  u32 counter = 0;
  const char *temp = (const char *)s;
  while (counter < n) {
    if (temp[counter] == c)
      return &temp[counter];
  }
  return NULL;
}

int ft_memcmp(const void *s1, const void *s2, u64 n) {
  const char *ts1 = (const char *)s1;
  const char *ts2 = (const char *)s2;

  u32 sum_s1 = 0;
  for (u64 i = 0; i < n; ++i)
    sum_s1 += ts1[i];

  u32 sum_s2 = 0;
  for (u64 i = 0; i < n; ++i)
    sum_s2 += ts2[i];

  return sum_s1 - sum_s2;
}

const char *ft_strnstr(const char *big, const char *little, u64 len) {
  if (little[0] == '\0')
    return big;
  u32 counter = 0;
  u32 little_len = ft_strlen(little);
  while (counter < len && counter < MAX_LOOP_BEF_CRASH) {
    if (big[counter] == little[0]) {
      u32 tmp = 1;
      while (counter + tmp < len && tmp < little_len) {
        if (big[counter + tmp] == little[tmp])
          ++tmp;
        else
          break;
      }
      if (tmp == little_len)
        return &big[counter];
    }
    ++counter;
  }
  return NULL;
}

int ft_atoi(const char *nptr) {
  u32 nptr_len = ft_strlen(nptr);
  u32 i = 1;
  int isneg = nptr[0] == '-';
  int result = 0;
  while (i < nptr_len && ft_isdigit(nptr[i])) {
    result += ((int)nptr[i] - 0x30);
    if (!ft_isdigit(nptr[i + 1]))
      break;
    result *= 10;
    ++i;
  }
  return isneg ? result * (-1) : result;
}

void *ft_calloc(u64 n, u64 size) {
  if (n != 0 && size > UINT64_MAX / n)
    return NULL;
  void *p = malloc(size * n);
  if (!p)
    return NULL;
  ft_bzero(p, n * size);
  return p;
}

char *ft_strdup(const char *s) {
  char *dup = (char *)malloc(ft_strlen(s) + 1);
  if (!dup) {
    errno = ENOMEM;
    return NULL;
  }
  ft_memcpy(s, dup, ft_strlen(s) + 1);
  return dup;
}

char *ft_substr(const char *s, u32 start, u64 len) {
  if (len - start > ft_strlen(s)) {
    return NULL;
  }
  char *sub = (char *)malloc(sizeof(char) * len);
  if (!sub)
    return NULL;
  // dividing start / 4 since u32 (aka unsigned int)
  // is 4 bytes, one char is 1 byte
  ft_memcpy(s + start, sub, len);
  return sub;
}

char *ft_strjoin(const char *s1, const char *s2) {
  u64 s1_len = ft_strlen(s1);
  u64 s2_len = ft_strlen(s2);
  char *str = malloc(s1_len + s2_len);

  if (!str)
    return NULL;

  ft_strlcpy(s1, str, sizeof(str));
  ft_strlcat(s2, str, s1_len + s2_len);
  str[s1_len + s2_len - 1] = '\0';

  return str;
}

int ft_ischar_in_string(const char *s, const char c) {
  if (!s)
    return 0;
  u32 s_len = ft_strlen(s);
  for (u32 i = 0; i < s_len; ++i) {
    if (s[i] == c)
      return 1;
  }
  return 0;
}

char *ft_strtrim(const char *s, const char *set) {
  if (!s || !set)
    return NULL;

  // head of string
  u32 s_len = ft_strlen(s);
  u32 start_index = 0;

  while (ft_ischar_in_string(set, s[start_index]))
    ++start_index;

  // tail of string
  u32 end_index = s_len - 1;
  while (ft_ischar_in_string(set, s[end_index]))
    --end_index;

  if (start_index > end_index)
    return ft_strdup("");

  char *tmp = malloc(end_index - start_index + 2);
  u32 k = 0;
  for (u32 i = start_index; i <= end_index; ++i) {
    tmp[k] = s[i];
    ++k;
  }
  tmp[end_index - start_index + 1] = '\0';
  return tmp;
}

u32 count_words(const char *s, const char c) {
  if (!s || !*s)
    return 0;
  u32 count = 0;
  int in_word = 0;

  for (u32 i = 0; s[i]; ++i) {
    if (s[i] != c && !in_word) {
      in_word = 1;
      count++;
    } else if (s[i] == c) {
      in_word = 0;
    }
  }
  return count;
}

char **ft_split(const char *s, char c) {
  if (!s)
    return NULL;
  if (!ft_ischar_in_string(s, c)) {
    char **res = malloc(sizeof(char *) * 2);
    res[0] = malloc(ft_strlen(s) + 1);
    ft_memcpy(s, res[0], ft_strlen(s) + 1);
    res[1] = NULL;
    return res;
  }

  u32 nb_words = count_words(s, c);

  char **tmp = malloc((nb_words + 1) * sizeof(char *));

  u32 read_string_index = 0;
  for (u32 i = 0; i < nb_words; ++i) {
    u32 word_len = 0;
    while (s[read_string_index + word_len] != '\0' &&
           s[read_string_index + word_len] != c) {
      ++word_len;
    }
    if (word_len == 0) {
      ++read_string_index;
      --i;
      continue;
    }

    tmp[i] = malloc((word_len + 1) * sizeof(char));
    for (u32 k = 0; k < word_len; ++k) {
      tmp[i][k] = s[read_string_index + k];
    }
    tmp[i][word_len] = '\0';
    read_string_index += word_len;
    while (s[read_string_index] == c) {
      read_string_index++;
    }
  }
  tmp[nb_words] = NULL;
  return tmp;
}

char *ft_itoa(int n) {
  if (n == 0) {
    char *res = malloc(2);
    if (!res)
      return NULL;
    res[0] = '0';
    res[1] = '\0';
    return res;
  }
  int isneg = n < 0;
  i64 num = isneg ? -(i64)n : n;

  u32 nbdigits = 0;
  i64 tmp = num;
  while (tmp > 0) {
    ++nbdigits;
    tmp /= 10;
  }
  char *alpha = malloc(nbdigits + 1 + (isneg ? 1 : 0));
  if (!alpha)
    return NULL;

  u32 i = nbdigits + (isneg ? 1 : 0) - 1;
  while (num > 0) {
    alpha[i--] = num % 10 + 0x30;
    num /= 10;
  }
  if (isneg)
    alpha[0] = '-';

  alpha[nbdigits + (isneg ? 1 : 0)] = '\0';
  return alpha;
}
