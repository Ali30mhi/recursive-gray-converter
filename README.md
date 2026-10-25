# Binary to Gray Code Converter

A small C program that converts a binary number to its Gray code.

## What is Gray code?

In Gray code, two consecutive numbers differ in only one bit. It is used
in rotary encoders, Karnaugh maps and error-resistant digital signals.

| Decimal | Binary | Gray |
|---------|--------|------|
| 0       | 000    | 000  |
| 1       | 001    | 001  |
| 2       | 010    | 011  |
| 3       | 011    | 010  |
| 4       | 100    | 110  |
| 5       | 101    | 111  |
| 6       | 110    | 101  |
| 7       | 111    | 100  |

## How it works

The first Gray bit equals the first binary bit; every following Gray bit
is the XOR of the current binary bit and the previous one:

```
binary:  1   0   1   1
         |  1^0 0^1 1^1
gray:    1   1   1   0
```

## Build & run

```bash
gcc -Wall -Wextra -std=c11 -o recursivegray recursivegray.c
./recursivegray
```

```
Enter a binary number: 1011
Gray code equivalent: 1110
```

## Features

- Reads the number as text, so leading zeros are kept (`0111` -> `0100`)
- Works with up to 255 digits (no `int` overflow)
- Rejects anything that is not 0 or 1 with a clear error message
- No external dependencies

## History

The first version read the input with `scanf("%d")`, which treated `10`
as the decimal number ten instead of binary two, and printed wrong
results (e.g. `10` -> `1385` instead of `11`). The current version works
on the digits directly and gives correct results.
