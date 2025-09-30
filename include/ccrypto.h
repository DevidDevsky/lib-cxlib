#ifndef CCRYPTO_H
#define CCRYPTO_H

#include <stddef.h>  // Для size_t

// === Хеши ===
// Возвращают хеш строки в виде HEX (не забывать free)
char* md5(const char *data);
char* sha1(const char *data);
char* sha256(const char *data);

// === Base64 ===
// Кодирование и декодирование Base64
// base64_encode возвращает null-terminated строку, free после использования
char* base64_encode(const unsigned char *data, size_t input_length);

// base64_decode возвращает массив байт и длину через output_length, free после использования
unsigned char* base64_decode(const char *data, size_t *output_length);

#endif // CCRYPTO_H