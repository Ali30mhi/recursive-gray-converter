#include <stdio.h>

int binaryToGray(int binary);

int main() {
    int binary, gray;

    printf("Enter a binary number: ");
    scanf("%d", &binary);

    gray = binaryToGray(binary);
    printf("Gray code equivalent: %d\n", gray);

    return 0;
}

int binaryToGray(int binary) {
    if (binary == 0) {
        return 0;
    }

    int shifted_binary = binary >> 1;
    int xor_result = binary ^ shifted_binary;

    return xor_result + (binaryToGray(shifted_binary) * 10);
}