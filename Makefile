# Makefile для сборки библиотеки cxlib и тестов

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/cconsole.c src/cmathx.c src/ccrypto.c
OBJ = $(SRC:.c=.o)
LIB = libcxlib.a

TESTS = test/test_console test/test_math test/test_crypto

all: $(LIB) $(TESTS)

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

test/%: test/%.c $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -L. -lcxlib

clean:
	rm -f $(OBJ) $(LIB) $(TESTS)