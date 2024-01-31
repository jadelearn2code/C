#include <unistd.h>
#include <stdint.h>

#define LS_BYTES	0x0101010101010101ULL

/**
 * _memset - Fills a block of memory with a specified value.
 * @m: A pointer to the block of memory to be filled.
 * @c: The value to be set.
 * @len: The number of bytes to be set.
 *
 * This function is a reimplementation of the standard C library function memset.
 * It fills a block of memory with a specified value. It handles the case where
 * the number of bytes is not a multiple of 8 first, and then sets 8 bytes at a time.
 *
 * The function has a time complexity of O(n), where n is the number of bytes to be set,
 * as it visits each byte exactly once. The space complexity is O(1), as it only uses a
 * fixed amount of additional space.
 *
 * Returns: A pointer to the memory block after it has been filled.
 */
void	*_memset(void *m, int c, size_t len) {
	const void *init = (const void *)m;
	uint64_t *long_word;
	uint64_t ext_char;

	// Handle the case where len is not a multiple of 8
	while (len % 8) {
		*(uint8_t *)m++ = (uint8_t)c;
		--len;
	}

	// If there are still bytes left to set
	if (len) {
		// Create a 64-bit value where each byte is c
		ext_char = LS_BYTES * (uint8_t)c;

		// Set 8 bytes at a time
		long_word = (uint64_t *)m;
		while (len) {
			*long_word++ = ext_char;
			len -= 8;
		}
	}

	return ((void *)init);
}
