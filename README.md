CXLib

CXLib — это легковесная библиотека на C для удобной работы с консолью, математикой и криптографией.
Библиотека включает три модуля:
	•	cconsole.h — цветной вывод текста, рамки, таблицы
	•	cmathx.h — расширенные математические функции, включая работу с матрицами
	•	ccrypto.h — хеши (MD5, SHA1, SHA256) и Base64

⸻

📦 Установка

Linux / macOS
```bash
	1.	Установите OpenSSL (для криптографии):

# macOS (Homebrew)
brew install openssl

# Ubuntu/Debian
sudo apt update
sudo apt install libssl-dev

	2.	Клонируйте репозиторий:

git clone https://github.com/DevidDevsky/lib-cxlib.git
cd lib-cxlib

	3.	Соберите библиотеку:

make

Файл libcxlib.a будет готов в корне проекта, тесты — в test/.
```
⸻

```bash
Windows (MSYS2 / MinGW)
	1.	Установите OpenSSL через MSYS2:

pacman -S mingw-w64-x86_64-openssl

	2.	Соберите библиотеку через MSYS2/Mingw:

make

В Windows нужно будет указать пути к include и lib OpenSSL, если они не находятся в стандартных папках.
```
⸻

🧩 Модули и функции

1. cconsole.h

Функции для красивого консольного вывода.

#include "cconsole.h"

printf("Hello World!", ccolor.red); // красный текст

	•	Цвета: ccolor.red, ccolor.green, ccolor.blue, ccolor.yellow, ccolor.pink
	•	Можно добавлять рамки, таблицы и другие эффекты (добавим позже расширенные функции).

⸻

2. cmathx.h

Базовые функции:

#include "cmathx.h"

long long f = factorial(5);    // факториал 5!
bool prime = is_prime(17);     // true, если число простое

Работа с матрицами:

matrix_t *A = matrix_create(3, 3);
matrix_t *B = matrix_create(3, 3);

// Сложение / вычитание
matrix_t *C = matrix_add(A, B);
matrix_t *D = matrix_sub(A, B);

// Умножение на число
matrix_t *E = matrix_mul_scalar(A, 2.0);

// Умножение матрицы на матрицу
matrix_t *F = matrix_mul(A, B);

// Транспонирование
matrix_t *G = matrix_transpose(A);

// Определитель и ранг
double det = matrix_determinant(A);
int rank = matrix_rank(A);

// Освобождение памяти
matrix_free(A);
matrix_free(B);
matrix_free(C);
matrix_free(D);
matrix_free(E);
matrix_free(F);
matrix_free(G);


⸻

3. ccrypto.h

Функции для хеширования и Base64 (требуется OpenSSL).

#include "ccrypto.h"

// MD5 / SHA1 / SHA256
char *md5_hash = md5("Hello");
char *sha1_hash = sha1("Hello");
char *sha256_hash = sha256("Hello");

// Base64
char *b64 = base64_encode((unsigned char*)"12345", strlen("12345"));
size_t decoded_len;
unsigned char *decoded = base64_decode(b64, &decoded_len);

// Не забывайте освобождать память
free(md5_hash);
free(sha1_hash);
free(sha256_hash);
free(b64);
free(decoded);


⸻

🏃‍♂️ Тесты

Все тесты находятся в папке test/:
	•	test_console.c — тесты для цветного консольного вывода
	•	test_math.c — тесты для математики и матриц
	•	test_crypto.c — тесты для хешей и Base64

Сборка и запуск:

make
./test/test_console
./test/test_math
./test/test_crypto


⸻

⚙️ Примечания
	1.	Для работы криптографии требуется OpenSSL.
	2.	Матрицы динамически выделяются, не забудьте вызывать matrix_free.
	3.	Определитель вычисляется итеративно через метод Гаусса — безопасно для больших матриц.

⸻

📜 Лицензия

MIT License.