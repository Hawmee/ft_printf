*This project has been created as part of the 42 curriculum by varandri.*

# ft_printf

## Description

`ft_printf` is a C library that reimplements the standard `printf()` function from libc. The goal is to understand variadic functions in C — functions that accept a variable number of arguments — and to produce well-structured, extensible code.

The library is compiled as a static archive (`libftprintf.a`) and supports the following format conversions:

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a decimal (base 10) number |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal (base 10) number |
| `%x` | Prints a number in hexadecimal (base 16) lowercase |
| `%X` | Prints a number in hexadecimal (base 16) uppercase |
| `%%` | Prints a literal percent sign |

## Algorithm & Data Structure

The core of `ft_printf` is a format string parser. The function iterates over the format string character by character. When it encounters a `%`, it reads the next character to identify the conversion specifier, then dispatches to the appropriate handler function using a series of conditionals.

Each handler receives the current `va_list` (variable argument list), extracts the next argument using `va_arg` with the correct type, formats it, and writes it to stdout using `write()`. The function accumulates and returns the total number of characters written, mimicking the return value of the original `printf()`.

Memory is dynamically allocated using `ft_calloc` where converting non alphabetical value into a strings are needed. Those strings are directly read with an already existing functions to avoid making unnecessary redundant logics. All allocated memory is properly freed after use.

## Instructions

### Build the static library

```bash
make
```

### Clean the object files

To remove compiled object files (`*.o`) without deleting the library:

```bash
make clean
```

### Clean all generated files

To remove both object files and the compiled library:

```bash
make fclean
```

### Rebuild from scratch

```bash
make re
```

### Use the library in your program

```bash
cc -Wall -Werror -Wextra <program.c> libftprintf.a -o <output>
```

- `<program.c>`: Your source file that calls `ft_printf`.
- `libftprintf.a`: The static library generated at the root of the repository.

### Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
    ft_printf("Pointer: %p\n", (void *)main);
    ft_printf("Hex: %x / %X\n", 255, 255);
    return (0);
}
```

Compile and run:

```bash
cc -Wall -Werror -Wextra main.c libftprintf.a -o test && ./test
```

## Resources

The following resources were used during the development of this project:

- [GeeksforGeeks](https://www.geeksforgeeks.org/) — Documentation on `printf`, variadic functions, and general C behavior.
- [cppreference — printf](https://en.cppreference.com/w/c/io/fprintf) — Reference for format specifiers and expected behavior.
- [OneCompiler](https://onecompiler.com/c) — Online C compiler used for quick testing and prototyping.
- [YouTube](https://www.youtube.com/) — Video tutorials on variadic functions and `va_list` usage.
- [Claude AI](https://claude.ai/) — Used to help draft the README, and generate usage examples.