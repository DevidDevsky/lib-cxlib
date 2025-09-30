# Компилятор
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LIB = libcxlib.a
SRC = src/cconsole.c src/cmathx.c src/ccrypto.c
OBJ = $(SRC:.c=.o)

# -------------------------------------
# Определяем ОС
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    # macOS
    OPENSSL_INC ?= /opt/homebrew/opt/openssl/include
    OPENSSL_LIB ?= /opt/homebrew/opt/openssl/lib
else ifeq ($(UNAME_S),Linux)
    # Linux
    OPENSSL_INC ?= /usr/include
    OPENSSL_LIB ?= /usr/lib
else
    $(error Unsupported OS: $(UNAME_S))
endif

LIBS = -lssl -lcrypto

# Тесты
TESTS = test/test_console test/test_math test/test_crypto

# -------------------------------------
# Цель по умолчанию
all: $(LIB) $(TESTS)

# Сборка статической библиотеки
$(LIB): $(OBJ)
	ar rcs $@ $^

# Компиляция объектов
%.o: %.c
	$(CC) $(CFLAGS) -I$(OPENSSL_INC) -c $< -o $@

# -------------------------------------
# Тесты
test/test_console: test/test_console.c $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -L. -lcxlib

test/test_math: test/test_math.c $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -L. -lcxlib

test/test_crypto: test/test_crypto.c $(LIB)
	$(CC) $(CFLAGS) -I$(OPENSSL_INC) -L. -L$(OPENSSL_LIB) -o $@ $< -lcxlib $(LIBS)

# -------------------------------------
# Очистка
clean:
	rm -f src/*.o $(LIB) $(TESTS)

.PHONY: all clean