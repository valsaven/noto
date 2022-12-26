#include "noto_entry_create.h"

char *noto_hash_generate();
char *noto_db_get_path();

/**
 * Create the entry.
 */
int noto_entry_create(char *str) {
  FILE *out = fopen(noto_db_get_path(), "a");
  srand(time(NULL));
  char *hash = noto_hash_generate();
  fprintf(out, "%s %s\n", hash, str);
  fclose(out);
  printf(" > New entry has been added.\n");
  return (0);
}
