#include <unistd.h>

#define LS_BYTES				0x0101010101010101ULL
#define MS_BYTES				0x8080808080808080ULL
#define LONG_WORD_HAS_ZERO(lw)	(((lw - LS_BYTES) & ~(lw)) & MS_BYTES)
#define TEST_BYTE(x)			if (!ptr[x]) return (ptr - str + x)

/* 
 * Function: _strlen
 * -------------------
 *  An optimized version of the strlen function from the standard C library.
 *  This function calculates the length of a string, not including the terminating null character.
 *
 *  str: The string whose length is to be calculated.
 *
 *  returns: The length of the string.
 */
size_t _strlen(const char *str) {
  const char *ptr = str;

  // Align the pointer to an 8-byte boundary
  while ((uintptr_t)ptr % 8) {
    if (!*ptr) {
      return (ptr - str);
    }

    ++ptr;
  }

  // Read 8 bytes at a time
  while (1) {
    // Check if any of the bytes in the word are zero
    if (LONG_WORD_HAS_ZERO(*(const uintptr_t*)ptr)) {
      // If a zero byte is found, check each byte in the word individually
      TEST_BYTE(0);
      TEST_BYTE(1);
      TEST_BYTE(2);
      TEST_BYTE(3);
      TEST_BYTE(4);
      TEST_BYTE(5);
      TEST_BYTE(6);
      TEST_BYTE(7);
    }

    ptr += 8;
  }
}
