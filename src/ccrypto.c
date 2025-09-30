#include "ccrypto.h"
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// ======= Вспомогательная функция для хешей =======
static char* digest_to_hex(const unsigned char *digest, unsigned int len) {
    char *res = malloc(len*2 + 1);
    for (unsigned int i = 0; i < len; i++)
        sprintf(&res[i*2], "%02x", digest[i]);
    res[len*2] = '\0';
    return res;
}

// ======= MD5 =======
char* md5(const char *data) {
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;

    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_md5(), NULL);
    EVP_DigestUpdate(ctx, data, strlen(data));
    EVP_DigestFinal_ex(ctx, digest, &digest_len);
    EVP_MD_CTX_free(ctx);

    return digest_to_hex(digest, digest_len);
}

// ======= SHA1 =======
char* sha1(const char *data) {
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;

    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_sha1(), NULL);
    EVP_DigestUpdate(ctx, data, strlen(data));
    EVP_DigestFinal_ex(ctx, digest, &digest_len);
    EVP_MD_CTX_free(ctx);

    return digest_to_hex(digest, digest_len);
}

// ======= SHA256 =======
char* sha256(const char *data) {
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;

    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_sha256(), NULL);
    EVP_DigestUpdate(ctx, data, strlen(data));
    EVP_DigestFinal_ex(ctx, digest, &digest_len);
    EVP_MD_CTX_free(ctx);

    return digest_to_hex(digest, digest_len);
}

// ======= Base64 Encode =======
char* base64_encode(const unsigned char *data, size_t input_length) {
    BIO *bio, *b64;
    BUF_MEM *buffer_ptr;

    b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL); // без переноса строк
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_write(bio, data, input_length);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &buffer_ptr);

    char *b64text = malloc(buffer_ptr->length + 1);
    memcpy(b64text, buffer_ptr->data, buffer_ptr->length);
    b64text[buffer_ptr->length] = '\0';

    BIO_free_all(bio);
    return b64text;
}

// ======= Base64 Decode =======
unsigned char* base64_decode(const char *data, size_t *output_length) {
    BIO *bio, *b64;
    int decodeLen = (int)strlen(data);
    unsigned char *buffer = malloc(decodeLen);

    b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    bio = BIO_new_mem_buf(data, -1);
    bio = BIO_push(b64, bio);

    *output_length = BIO_read(bio, buffer, decodeLen);
    BIO_free_all(bio);

    return buffer;
}