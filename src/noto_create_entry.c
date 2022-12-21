#include "noto_create_entry.h"

char *noto_generate_hash();
char *noto_get_path_to_db();

/**
 * Create the entry.
 */
int noto_create_entry(char *str) {
  FILE *out = fopen(noto_get_path_to_db(), "a");
  srand(time(NULL));
  char *hash = noto_generate_hash();
  fprintf(out, "%s %s\n", hash, str);
  fclose(out);
  printf(" > New entry has been added.\n");
  return (0);
}
