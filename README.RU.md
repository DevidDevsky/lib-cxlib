# CxLib - Библиотека полезных функций на C

CxLib - это легковесная библиотека на языке C, предоставляющая набор полезных функций для работы с консолью, криптографией и математическими операциями.

## 📦 Установка

### Linux/macOS
```bash
# Клонируем репозиторий
git clone https://github.com/DevidDevsky/lib-cxlib.git
cd lib-cxlib

# Компилируем и устанавливаем
make
sudo make install
```

### Windows
1. Клонируйте репозиторий
2. Откройте командную строку в папке проекта
3. Выполните:
   ```
   install.bat
   ```

## 📚 Документация

### 1. Модуль cconsole
Функции для работы с цветным выводом в консоль.

```c
#include <cconsole.h>

// Пример использования цветного вывода
cprintf(C_RED, "Этот текст будет красным\n");
cprintf(C_GREEN, "А этот - зеленым\n");
```

### 2. Модуль ccrypto
Криптографические функции.

```c
#include <ccrypto.h>

// Хеширование
char *hash = md5("Hello, World!");
printf("MD5: %s\n", hash);
free(hash);

// Base64 кодирование/декодирование
char *encoded = base64_encode((unsigned char*)"Hello", 5);
printf("Base64: %s\n", encoded);
free(encoded);
```

### 3. Модуль cmathx
Математические функции и работа с матрицами.

```c
#include <cmathx.h>

// Проверка на простое число
if (is_prime(17)) {
    printf("17 - простое число\n");
}

// Работа с матрицами
matrix_t *a = matrix_create(2, 2);
// ... инициализация матрицы ...
matrix_t *b = matrix_create(2, 2);
// ... инициализация матрицы ...
matrix_t *result = matrix_add(a, b);
// ... работа с результатом ...
matrix_free(a);
matrix_free(b);
matrix_free(result);
```

## 🚀 Примеры

В папке `test/` находятся примеры использования библиотеки:

1. `test_console.c` - пример работы с цветным выводом
2. `test_crypto.c` - примеры криптографических операций
3. `test_math.c` - примеры математических операций

Для компиляции и запуска тестов:
```bash
make test
```

## 🔧 Компиляция

Для компиляции библиотеки вручную:

```bash
gcc -c src/*.c -Iinclude/
ar rcs libcxlib.a *.o
```

Для использования в вашем проекте:
1. Подключите заголовочные файлы из папки `include/`
2. Скомпилируйте с флагом `-lcxlib` Вот так:

```bash
gcc name.c -lcxlib -o name
```

## 📄 Лицензия

MIT License - смотрите файл [LICENSE](LICENSE) для деталей.