#include "noto.h"
#include <stdlib.h>
#include <string.h>

char *generate_hash(void) {
    const char alphabet[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    const int len = 7;

    char *hash = malloc(len + 2);
    if (!hash) return NULL;

    hash[0] = '@';

    const size_t alph_len = strlen(alphabet);
    for (int i = 1; i < len; i++) {
        hash[i] = alphabet[(unsigned)rand() % alph_len];
    }

    hash[len + 1] = '\0';

    return hash;
}