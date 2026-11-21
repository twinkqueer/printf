*This project has been created as part of the 42 curriculum by mpankrat.*

# ft_printf

## Description

`ft_printf` is a recreation of the standard C `printf()` function, developed as part of the 42 curriculum.

The goal of this project is to understand variadic functions in C, work with different data types, and recreate formatted output without relying on the original `printf()` implementation.

The project implements a custom function called `ft_printf()` that writes formatted output to the standard output (`stdout`), handling both regular characters and format specifiers.

The implementation is divided into smaller functions, each responsible for printing a particular data type or handling a specific conversion. This modular approach makes the code easier to maintain, understand, and extend.

### Supported conversions

| Specifier | Description |
|:---:|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal. |
| `%d` | Prints a decimal integer. |
| `%i` | Prints an integer. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints a hexadecimal number in lowercase. |
| `%X` | Prints a hexadecimal number in uppercase. |
| `%%` | Prints a literal percent sign. |

### Project structure

| File | Responsibility |
|---|---|
| `ft_printf.c` | Main function and format specifier parsing. |
| `ft_printf_utils.c` | Basic output and utility functions. |
| `ft_printchar.c` | Character conversion. |
| `ft_printstr.c` | String conversion. |
| `ft_printint.c` | Signed and unsigned integer conversions. |
| `ft_printhex.c` | Hexadecimal conversion handling. |
| `ft_printbase.c` | Recursive number conversion for different bases. |
| `ft_printpointer.c` | Pointer address conversion. |
| `ft_printf.h` | Public header file. |
| `ft_printf_internal.h` | Internal function declarations and required headers. |
| `Makefile` | Compilation and library management. |

## Instructions

### Requirements

- A C compiler (`cc`, `gcc` or `clang`).
- GNU Make.
- A Unix-like operating system.

### Compilation

Clone the repository:

```bash
git clone https://github.com/twinkqueer/printf.git
cd printf
```

Compile the project using the provided Makefile:

```bash
make
```

This generates a static library called:

```text
libftprintf.a
```

The Makefile also provides the following commands:

| Command | Description |
|---|---|
| `make` | Compiles the library. |
| `make clean` | Removes object files. |
| `make fclean` | Removes object files and the compiled library. |
| `make re` | Recompiles the entire library. |

### Usage

To use `ft_printf()` in another C project, include the public header:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "42");
    ft_printf("Decimal: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Character: %c\n", 'A');
    ft_printf("Percentage: %%\n");

    return (0);
}
```

Compile your program by linking against the generated static library:

```bash
cc main.c -I. -L. -lftprintf -o program
```

Execute it:

```bash
./program
```

## Algorithm and Data Structures

### 1. Format string parsing

The core of the implementation is the `ft_printf()` function.

It processes the input format string sequentially, character by character, using a pointer to keep track of the current position.

There are two possible cases:

1. **Regular character:** If the current character is not `%`, it is printed directly using `ft_putchar_fd()`. The character counter is incremented.
2. **Format specifier:** If the current character is `%`, the next character is read and passed to `ft_print_specifier()`, which determines which conversion function should handle the argument.

The conversion function returns the number of characters printed, which is added to the total character count.

This process continues until the end of the format string is reached.

### 2. Variadic arguments

The project uses the `stdarg.h` library to handle a variable number of arguments.

The following macros are used:

- `va_list`: Stores the state of the argument list.
- `va_start`: Initializes the argument list.
- `va_arg`: Retrieves the next argument with the requested type.
- `va_end`: Cleans up the argument list.

This allows `ft_printf()` to accept different numbers and types of arguments depending on the format string.

For example:

```c
ft_printf("%d %s %c", 42, "Hello", 'A');
```

Each conversion function retrieves its corresponding argument using `va_arg()`.

### 3. Conversion dispatching

The `ft_print_specifier()` function acts as a dispatcher.

It receives the format specifier and the variadic argument list, then selects the appropriate conversion function.

For example:

- `%d`, `%i` and `%u` are handled by `ft_printint()`.
- `%x` and `%X` are handled by `ft_printhex()`.
- `%c` is handled by `ft_printchar()`.
- `%s` is handled by `ft_printstr()`.
- `%p` is handled by `ft_printpointer()`.

The `%%` conversion is handled directly by printing a percent character.

This separation keeps the main parsing function relatively simple and prevents all conversion logic from being concentrated in a single function.

### 4. Number conversion algorithm

The project uses a recursive base-conversion algorithm implemented in `ft_printbase()`.

This function is responsible for printing numbers in different numerical bases, particularly hexadecimal.

The algorithm works by repeatedly dividing the number by the selected base.

For each recursive call:

1. Divide the number by the base.
2. Recursively process the quotient.
3. Print the remainder using a lookup string containing the available digits.

For hexadecimal conversion, the lookup string is either:

```c
"0123456789abcdef"
```

or:

```c
"0123456789ABCDEF"
```

The remainder determines which character is printed.

Recursion ensures that digits are printed in the correct order, from the most significant digit to the least significant digit.

The function also handles zero as a special case to ensure that it prints at least one digit.

### 5. Data structures and technical choices

The implementation deliberately uses simple C data structures and standard library facilities.

**Character pointers (`char *` and `const char *`)**

Pointers are used to traverse the format string without copying it into another buffer. This avoids unnecessary memory allocation and keeps the parsing process efficient.

**`va_list`**

A variadic argument list is necessary because `ft_printf()` accepts a variable number of arguments. It provides a standard way to retrieve arguments according to their expected types.

**Integer types (`int`, `unsigned int`, `size_t`, `uintptr_t`)**

Different integer types are used depending on the conversion being performed. `uintptr_t` is used when representing pointer values as integers for hexadecimal output.

**Lookup strings**

Lookup strings provide a straightforward way to translate numerical remainders into their corresponding hexadecimal characters.

**Recursion**

Recursion is used for base conversion because repeatedly dividing a number produces its digits in reverse order. Processing the quotient before printing the remainder naturally reverses that order without requiring an additional array or buffer.

### 6. Algorithm complexity

For a format string containing `n` characters, the parsing process has a time complexity of:

- **O(n)** for traversing and processing the format string, excluding the cost of printing converted arguments.

For an integer containing `d` digits in a given base, the recursive base conversion has:

- **O(d)** time complexity.
- **O(d)** auxiliary stack space due to recursive calls.

The implementation does not require dynamically allocated memory for formatting or storing the output.

## Resources

The following resources were useful for understanding the concepts involved in this project.

### Documentation

- [printf(3) - Linux Manual Page](https://man7.org/linux/man-pages/man3/printf.3.html) — Reference for the original `printf()` function and its format specifiers.
- [stdarg.h - GNU C Library](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html) — Documentation about variadic functions and argument handling.
- [write(2) - Linux Manual Page](https://man7.org/linux/man-pages/man2/write.2.html) — Documentation about writing data to file descriptors.
- [C Reference](https://en.cppreference.com/w/c.html) — General C language reference.

### Learning resources

- [42 School](https://42.fr/) — Information about the 42 curriculum and its projects.
- [GNU C Library Documentation](https://www.gnu.org/software/libc/manual/) — Reference for C library functionality.

### AI Usage

AI tools were used as supplementary learning and development resources during this project.

They were used for:

- Understanding variadic functions and the `stdarg.h` macros.
- Clarifying how format specifiers work in the original `printf()` implementation.
- Understanding recursive algorithms and numerical base conversion.
- Reviewing the project's structure and helping document its implementation.
- Assisting with the preparation and organization of this README.

AI was used as a learning and documentation aid, not as a replacement for understanding the implementation. The project code and its functionality remain the responsibility of the author.

---

## Author

**Rivers Pankratov**

42 Student
