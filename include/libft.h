#ifndef LIBFT_H
#define LIBFT_H

// u64 => unsigned long long, unsigned int on 64 bits i.e. 8 bytes
typedef unsigned long long u64;

// u32 => unsigned int, unsigned integer on 32 bits i.e 4 bytes
typedef unsigned int u32;

// u16 => unsigned short, unsigned integer on 16 bits i.e 2 bytes
typedef unsigned short u16;

// u8 => unsigned char, unsigned integer (or often char) on 8 bits i.e. 1 byte
typedef unsigned char u8;

#define NULL 0

#define STRLEN_MAX 1024 * 1024 // 1 048 576 bytes
#define MAX_LOOP_BEF_CRASH 1000

// Print a specific message for an unimplemented function.
#define TODO(str)                                                              \
  do {                                                                         \
    if (str)                                                                   \
      fprintf(stderr, "TODO:" #str "\n");                                      \
    exit(1);                                                                   \
  } while (0)

// Make any argument of a function UNUSED, avoiding -Werror=unused-parameter
#define UNUSED(x) ((void)x)

/**
 * ft_isalpha - Check if a given character is alpha.
 * @paramc (u8): character to test
 *
 * True iff the provided character is an alphabetic value (i.e. not a number,
 * but a valid letter in sense of ASCII)
 *
 * Return: true iff the provided character is an alpha value (not a number,
 * nor another ASCII value).
 */
u8 ft_isalpha(u8 c);

/**
 * ft_isdigit - Check if a given character is digit.
 * @param c (u8): character to test
 *
 * True iff the provided character is a digit value (not alpha, but between 0 to
 * 9).
 *
 * Return: true iff the provided character is a digit value.
 */
u8 ft_isdigit(u8 c);

/**
 * ft_isalnum - Check if a given character is alpha-numerical.
 * @param c (u8): character to test
 *
 * True iff the provided character is an alpha-numerical value
 * (i.e. either number or letter in sense of ASCII).
 *
 * Return: true iff the provided character is an alpha-numerical value.
 */
u8 ft_isalnum(u8 c);

/**
 * ft_isascii - Check if a given character is an ASCII one.
 * @param c (u8): character to test
 *
 * True iff the provided character is an ASCII character
 * (i.e. its hex value under 0x7E (127))
 *
 * Return: true iff the provided character is an ASCII one
 */
u8 ft_isascii(u8 c);

/**
 * ft_isprint - Check if a given character is printable.
 * @param c (u8): character to test
 *
 * True iff the provided character is printable
 * (i.e. alpha-numerical or space)
 *
 * Return: true iff the provided character is printable
 */
u8 ft_isprint(u8 c);

/*
 * ******************************
 * String & memory manipulation *
 * ******************************
 */

/**
 * ft_strlen - Gets the length of a given string.
 * @param s (char*): string to test
 *
 * Gets the length for a NUL-terminated string. If not NUL-terminated as
 * UNIX string (or char pointers) should be, will loop indefinitely.
 *
 * Return: the length of the provided string
 */
u64 ft_strlen(const char *s);

/**
 * ft_memset - Sets byte by byte a constant byte to a buffer.
 * @param s (void*): buffet where to write
 * @param c (u8): value to write byte by byte;
 * @param n (u32): number of bytes to write
 *
 * Write bytes by bytes to the provided buffer n times the c char/u8 byte.
 * Can cause segfaulting if n is bigger than size of the buffer or lead to
 * unpredicted result.
 *
 * Return: the pointer to the buffer (or memory area s)
 */
void *ft_memset(void *s, u8 c, u32 n);

/**
 * ft_bzero - Sets byte 0 value to a buffer.
 * @param s (void*): buffer where to write
 * @param n (u32): number of bytes to write
 *
 * Sets 0 n times inside the memory area. Can cause unpredicted
 * result in case on n bigger than the size of the memory area.
 */
void ft_bzero(void *s, u32 n);

/**
 * ft_memcpy - Copy the contents of the source buffer to the destination buffer.
 * @param src (const void*): source buffer to copy
 * @param dest (void*): destination buffer where to copy
 * @param size (u32): number of bytes to copy
 *
 * Copy the contents over size bytes from the src buffer to the
 * destination buffer. Does not handle destination buffer size.
 *
 * You need to assure that src buffer HAS at least size bytes
 * and that destination can receive size bytes. Can then lead to
 * segfault or unpredicted result.
 *
 * Does not check if it is overlapping (possible loss of information),
 * use only memcpy only if you are sure that both buffer does not overlap
 * in memory.
 *
 * Return: the destination buffer pointer
 */
void *ft_memcpy(const void *src, void *dest, u32 size);

/**
 * ft_memmove - Copy from src buffer `size` bytes into destination buffer.
 * @param src (const void*): source buffer to move (copy)
 * @param dest (void*): destination buffer where to copy
 * @param size (u32): number of bytes to copy
 *
 * Copy the contents over size bytes from the src buffer to the
 * destination buffer. Does not handle destination buffer size.
 *
 * You need to assure that src buffer HAS at least size bytes
 * and that destination can receive size bytes. Can then lead to
 * segfault or unpredicted result.
 *
 * Takes into account possible overlapping between the two given
 * buffer, starting from the right instead of the left.
 *
 * Return: the destination buffer pointer
 */
void *ft_memmove(const void *src, void *dest, u32 size);

/**
 * ft_strlcpy - Copy the string content of the src buffer to
 * the destination buffer.
 * @param src (const char*): source buffer to copy from
 * @param dest (char*): destination buffer
 * @param size (u64): destination buffer size (could be further than
 * NUL-termination)
 *
 * Copy the string content of the source buffer to the destination
 * buffer. Will check that the destination can fit all content,
 * including NUL-termination. If it cannot fit, the output can
 * be amputated (especially for NUL-termination).
 *
 * Source buffer must be NUL-terminated, else, possible segfault or
 * unexpected result can occur. Destination buffer will be NUL-terminated, and
 * source content copy can be amputated if its size cannot fit all source buffer
 * in.
 *
 * Return: the number of bytes written to the destination buffer (can be smaller
 * than expected).
 */
u64 ft_strlcpy(const char *src, char *dest, u64 size);

/**
 * ft_strlcat - Concatenate the string content of the source buffer after the
 * contents of the destination buffer.
 * @param src (const char*): source buffer
 * @param dest (char*): destination buffer
 * @param size (u64): destination buffer size
 *
 * Concatenate the contents of the NUL-terminated source buffer at
 * the end of the contents (expected to be at a NUL-termination '\0')
 * of the destination buffer. Given size is the total allocated memory of
 * the destination buffer, and must contains enough space to fit source buffer
 * content, else it will be amputated, or segfault.
 *
 * Destination buffer resulting content will be NUL-terminated (even when the
 * memory area isn't enough to fit all source content).
 *
 * Return: the size of bytes written (can be smaller than expected).
 */
u64 ft_strlcat(const char *src, char *dest, u64 size);

/*
 * ft_toupper - Convert char to uppercase value.
 * @param c (u8): character to convert
 *
 * Converts the provided char to its uppercase value
 * (i.e. substracting 32 (or 0x20)).
 * Does not check if the provided character is ASCII, it must be
 * checked beforehand, or else can lead to unexpected char representation.
 *
 * Return: the uppercase value of the provided character
 */
u8 ft_toupper(u8 c);

/*
 * ft_tolower - Convert char to lowercase value.
 * @param c (u8): character to convert
 *
 * Converts the provided char to its lowercase value
 * (i.e. adding 32 (or 0x20)).
 * Does not check if the provided character is ASCII, it must be
 * checked beforehand, or else can lead to unexpected char representation.
 *
 * Return: the lowercase value of the provided character
 */
u8 ft_tolower(u8 c);

/*
 * ft_strchr - Search for a specific character in a string.
 * @param s (const char*): the string where to search
 * @param c (u8): the char to search for
 *
 * Search for the first occurrence of the given character inside a string.
 * The string provided must be NUL-terminated to avoid infinite looping.
 * If not found in the correctly formatted string, return a NULL pointer.
 *
 * Return: the pointer to the first occurrence of the character (NULL if not
 * found)
 */
const char *ft_strchr(const char *s, u8 c);

/*
 * ft_strchr - Search for a specific character in a string.
 * @param s (const char*): the string where to search
 * @param c (u8): the char to search for
 *
 * Search for the last occurrence of the given character inside a string.
 * The string provided must be NUL-terminated to avoid infinite looping.
 * If not found in the correctly formatted string, return a NULL pointer.
 *
 * Return: the pointer to the last occurrence of the character (NULL if not
 * found)
 */
const char *ft_strrchr(const char *s, u8 c);

/*
 * ft_strncmp - Compare two strings for n bytes.
 * @param s1 (const char*): first string to compare
 * @param s2 (const char*): second string to compare
 *
 * Compare the two provided string for n bytes of each.
 * If given n is bigger than one of the string buffer,
 * will exit with a specific message.
 *
 * Return: 0 if equals, negative if s1 < s2, positive if s1 > s2
 */
int ft_strncmp(const char *s1, const char *s2, u32 n);

/*
 * ft_memchr - Search for a character in the buffer, bounded to n.
 * @param s (const void*): pointer to buffer where to search
 * @param c (u8): character to find
 * @param n (u32): number of bytes to limit search to
 *
 * Search the first occurence of the given character/byte in
 * the provided buffer, bounded to n.
 *
 * Return: the pointer to the first occurrence if found, else NULL.
 */
const void *ft_memchr(const void *s, u8 c, u32 n);

/*
 * ft_memcmp - Compare the contents of two buffer over n bytes.
 * @param s1 (const void*): first buffer
 * @param s2 (const void*): second buffer
 * @param n (u64): number of bytes to parse
 *
 * Compare the contents of the two provided buffers, for
 * n bytes on each. Buffers sizes must be larger or equal
 * than n, to avoid segfault.
 *
 * Return: 0 if equals, negative if s1 < s2, positive if s1 > s2
 */
int ft_memcmp(const void *s1, const void *s2, u64 n);

/*
 * ft_strnstr - Search for the first occurence of string little in big, over
 * len.
 * @param big (const char*): big string where to search
 * @param little (const char*): little string to search
 * @param len (u64): len limit of search in big string
 *
 * Search for the first occurrence of the little string in the big
 * string, going max to len character in big string.
 * Both strings must be NUL-terminated.
 *
 * Return: if little is an empty (but NUL-terminated) string, return big.
 * If found, return the pointer to the start of the occurrence.
 * If not found at all, returns NULL.
 */
const char *ft_strnstr(const char *big, const char *little, u64 len);

/*
 * needs to be NUL-terminated!!! see unix/c convention
 */
int ft_atoi(const char *nptr);
#endif // LIBFT_H
