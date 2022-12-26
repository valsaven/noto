#include "noto_hash_generate.h"

char *noto_hash_generate() {
  const char alphabet[] = "abcdefghijklmnopqrstuvwxyz0123456789";
  int len = 7;
  char *hash = malloc((len + 1) * sizeof(char));
  int i;

  hash[0] = '@';

  for (i = 1; i < len; i++) {
    hash[i] = alphabet[rand() % (strlen(alphabet))];
  }

  hash[len] = '\0';

  return hash;
}
