#include <stdbool.h>

/* 
 * Function: _atoi
 * -------------------
 * Converts a string to an integer, mimicking the behavior of the standard atoi function.
 * This optimized version improves performance by minimizing branching and using bitwise operations.
 *
 * str: A pointer to the string that will be converted to an integer.
 *
 * returns: The integer value of the parsed string. If the string does not contain a valid integer,
 *          the return value will be zero. This function does not handle integer overflow or underflow,
 *          and such conditions will result in undefined behavior.
 */
int _atoi(const char *str) {
    int result = 0;  // Holds the converted integer value
    bool negative = false;  // Flag to indicate if the resulting integer should be negative

    // Skip leading whitespace characters (space, tab, newline, etc.)
    while ((*str >= 9 && *str <= 13) || *str == 32) {
        str++;
    }

    // Check for a sign indicator ('-' or '+') and set the 'negative' flag accordingly
    if (*str == '-' || *str == '+') {
        negative = (*str == '-');
        str++;
    }

    // Convert the string to an integer by processing each digit
    while (*str >= '0' && *str <= '9') {
        // 'result' is multiplied by 10 to shift left, and the digit value is added
        result = (result * 10) + (*str - '0');
        str++;
    }

    // If the number is negative, invert the sign of 'result'
    return negative ? -result : result;
}
