// u64 => unsigned long long, unsigned int on 64 bits i.e. 8 bytes
typedef unsigned long long u64;

// u32 => unsigned int, unsigned integer on 32 bits i.e 4 bytes
typedef unsigned int u32;

// u16 => unsigned short, unsigned integer on 16 bits i.e 2 bytes
typedef unsigned short u16;

// u8 => unsigned char, unsigned integer (or often char) on 8 bits i.e. 1 byte
typedef unsigned char u8;

#define STRLEN_MAX 1024 * 1024 // 1 048 576 bytes

/**
 * ft_isalpha - Check if a given character is alpha.
 * @param c (u8): character to test
 *
 * True iff the provided character is an alphabetic value (i.e. not a number,
 * but a valid letter in sense of ASCII)
 *
 * Return: true iff the provided character is an alpha value (not a number, nor
 * another ASCII value).
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
 *
 */

u8 ft_isalnum(u8 c);
/**
 *
 */

u8 ft_isascii(u8 c);
/**
 *
 */

u8 ft_isprint(u8 c);

/*
 * ******************************
 * String & memory manipulation *
 * ******************************
 */

/**
 *
 */
u64 ft_strlen(const char *s);

/**
 *
 */
void *ft_memset(void *s, u8 c, u32 n);

/**
 *
 */
void ft_bzero(void *s, u32 n);

/**
 *
 */
void *ft_memcpy(const void *src, void *dest, u32 size);

/**
 * Overlaps!! if src < dest < src + size, overlap !!!!
 */
void *ft_memmove(const void *src, void *dest, u32 size);

/**
 *
 */
u64 ft_strlcpy(const char *src, char *dest, u64 size);

/**
 *
 */
u64 ft_strlcat(const char *src, char *dest, u64 size);

/*
 *
 */
u8 ft_toupper(u8 c);

/*
 *
 */
u8 ft_tolower(u8 c);

/*
 *
 */
char *ft_strchr(const char *s, u8 c);

/*
 *
 */
char *ft_strrchr(const char *s, u8 c);

/*
 *
 */
int ft_strncmp(const char *s1, const char *s2, u32 n);

/*
 *
 */
void *ft_memchr(void *s, u32 n);

/*
 *
 */
int ft_memcmp(const void *s1, const void *s2, u64 n);

/*
 *
 */
char *ft_strnstr(const char *big, const char *little, u64 len);

/*
 * needs to be NUL-terminated!!! see unix/c convention
 */
int ft_atoi(const char *nptr);
