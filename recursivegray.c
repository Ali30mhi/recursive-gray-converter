#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 255

/* Converts a binary string (e.g. "1011") to its Gray code ("1110").
 * Returns 1 on success, 0 if the input contains anything but 0 and 1. */
static int binary_to_gray(const char *binary, char *gray) {
    size_t n = strlen(binary);
    if (n == 0) return 0;

    for (size_t i = 0; i < n; i++) {
        if (binary[i] != '0' && binary[i] != '1') return 0;
        if (i == 0)
            gray[i] = binary[0];                         /* first bit is copied */
        else
            gray[i] = (binary[i] == binary[i - 1]) ? '0' : '1';   /* XOR with previous bit */
    }
    gray[n] = '\0';
    return 1;
}

int main(void) {
    char binary[MAX_DIGITS + 1];
    char gray[MAX_DIGITS + 1];

    printf("Enter a binary number: ");
    if (scanf("%255s", binary) != 1) {
        fprintf(stderr, "No input given.\n");
        return 1;
    }

    if (!binary_to_gray(binary, gray)) {
        fprintf(stderr, "Invalid input: \"%s\" is not a binary number (use only 0 and 1).\n", binary);
        return 1;
    }

    printf("Gray code equivalent: %s\n", gray);
    return 0;
}