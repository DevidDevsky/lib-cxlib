#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ccrypto.h"

int main(void) {
    const char *text = "Hello, CXLib!";
    const int number = 12345;

    printf("Original string: %s\n", text);

    char *md5_hash = md5(text);
    printf("MD5: %s\n", md5_hash);
    free(md5_hash);

    char *sha1_hash = sha1(text);
    printf("SHA1: %s\n", sha1_hash);
    free(sha1_hash);

    char *sha256_hash = sha256(text);
    printf("SHA256: %s\n", sha256_hash);
    free(sha256_hash);

    char number_str[32];
    sprintf(number_str, "%d", number);
    char *b64 = base64_encode((unsigned char*)number_str, strlen(number_str));
    printf("Base64 Encoded: %s\n", b64);

    size_t decoded_len;
    unsigned char *decoded = base64_decode(b64, &decoded_len);
    printf("Base64 Decoded: %.*s\n", (int)decoded_len, decoded);

    free(b64);
    free(decoded);

    return 0;
}