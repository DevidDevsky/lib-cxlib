# CxLib - Useful C Library

CxLib is a lightweight C library providing a set of useful functions for console operations, cryptography, and mathematical computations.

## 📦 Installation

### Linux/macOS
```bash
# Clone the repository
git clone https://github.com/DevidDevsky/lib-cxlib.git
cd lib-cxlib

# Compile and install
make
sudo make install
```

### Windows
1. Clone the repository
2. Open command prompt in the project folder
3. Run:
   ```
   install.bat
   ```

## 📚 Documentation

### 1. cconsole Module
Functions for colored console output.

```c
#include <cconsole.h>

// Example of colored output
cprintf(C_RED, "This text will be red\n");
cprintf(C_GREEN, "This text will be green\n");
```

### 2. ccrypto Module
Cryptographic functions.

```c
#include <ccrypto.h>

// Hashing
char *hash = md5("Hello, World!");
printf("MD5: %s\n", hash);
free(hash);

// Base64 encoding/decoding
char *encoded = base64_encode((unsigned char*)"Hello", 5);
printf("Base64: %s\n", encoded);
free(encoded);
```

### 3. cmathx Module
Mathematical functions and matrix operations.

```c
#include <cmathx.h>

// Prime number check
if (is_prime(17)) {
    printf("17 is a prime number\n");
}

// Matrix operations
matrix_t *a = matrix_create(2, 2);
// ... initialize matrix ...
matrix_t *b = matrix_create(2, 2);
// ... initialize matrix ...
matrix_t *result = matrix_add(a, b);
// ... work with result ...
matrix_free(a);
matrix_free(b);
matrix_free(result);
```

## 🚀 Examples

Check the `test/` directory for usage examples:

1. `test_console.c` - colored console output examples
2. `test_crypto.c` - cryptographic operations examples
3. `test_math.c` - mathematical operations examples

To compile and run tests:
```bash
make test
```

## 🔧 Compilation

To compile the library manually:

```bash
gcc -c src/*.c -Iinclude/
ar rcs libcxlib.a *.o
```

To use in your project:
1. Include the header files from `include/`
2. Link with `-lcxlib` and `-lssl -lcrypto` for crypto functions
3. Make sure OpenSSL is installed on your system

### Dependencies

#### Linux/macOS
```bash
# For Ubuntu/Debian
sudo apt-get install libssl-dev

# For macOS (using Homebrew)
brew install openssl
```

#### Windows (MSYS2/MinGW)
```bash
# Install OpenSSL
pacman -S mingw-w64-x86_64-openssl

# Set the include and library paths if needed
export C_INCLUDE_PATH=/mingw64/include/openssl
export LIBRARY_PATH=/mingw64/lib
```

## 📝 API Reference

### cconsole.h
- `cprintf(ccolor_t color, const char *format, ...)` - Print formatted text with color
- Available colors: `C_BLACK`, `C_RED`, `C_GREEN`, `C_YELLOW`, `C_BLUE`, `C_MAGENTA`, `C_CYAN`, `C_WHITE`, `C_RESET`

### cmathx.h
- `long long factorial(int n)` - Calculate factorial
- `bool is_prime(int n)` - Check if number is prime
- Matrix operations: `matrix_create()`, `matrix_add()`, `matrix_sub()`, `matrix_mul()`, `matrix_transpose()`, etc.

### ccrypto.h
- Hashing: `md5()`, `sha1()`, `sha256()`
- Base64: `base64_encode()`, `base64_decode()`

## 🛠️ Building from Source

### Linux/macOS
```bash
make clean
make
sudo make install  # installs to /usr/local by default
```

### Windows (MSYS2/Mingw)
```bash
make clean
make
```

## 🧪 Running Tests

Test files are located in the `test/` directory:
- `test_console.c` - Tests for colored console output
- `test_math.c` - Tests for math functions and matrix operations
- `test_crypto.c` - Tests for hashing and Base64 functions

To compile and run all tests:
```bash
make test
```

Or run individual tests:
```bash
./test/test_console
./test/test_math
./test/test_crypto
```

## ⚠️ Notes

1. OpenSSL is required for cryptographic functions
2. Matrices are dynamically allocated - remember to free them with `matrix_free()`
3. Matrix determinant is calculated using Gaussian elimination, which is safe for large matrices

## 📜 License

MIT License - see [LICENSE](LICENSE) file for details.