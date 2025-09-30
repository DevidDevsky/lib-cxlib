#ifndef CCRYPTO_H
#define CCRYPTO_H

#include <stddef.h>  // Для size_t

// Хеш-функции
char* md5(const char *data);
char* sha1(const char *data);
char* sha256(const char *data);

// Base64
char* base64_encode(const unsigned char *data, size_t input_length);
unsigned char* base64_decode(const char *data, size_t *output_length);

#endif // CCRYPTO_H