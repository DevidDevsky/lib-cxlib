CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LIB = libcxlib.a
SRC = src/cconsole.c src/cmathx.c src/ccrypto.c
OBJ = $(SRC:.c=.o)

# OpenSSL (переопределяем при необходимости)
OPENSSL_INC ?= /opt/homebrew/opt/openssl/include
OPENSSL_LIB ?= /opt/homebrew/opt/openssl/lib
LIBS = -lssl -lcrypto

# Тесты
TESTS = test/test_console test/test_math test/test_crypto

all: $(LIB) $(TESTS)

$(LIB): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I$(OPENSSL_INC) -c $< -o $@

test/test_console: test/test_console.c $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -L. -lcxlib

test/test_math: test/test_math.c $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -L. -lcxlib

test/test_crypto: test/test_crypto.c $(LIB)
	$(CC) $(CFLAGS) -I$(OPENSSL_INC) -L$(OPENSSL_LIB) -o $@ $< -lcxlib $(LIBS)

clean:
	rm -f src/*.o $(LIB) $(TESTS)

.PHONY: all clean