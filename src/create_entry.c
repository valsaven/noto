#include "noto.h"
#include <time.h>

/**
 * Create the entry.
 */
int create_entry(char *str) {
  FILE *out = fopen(get_path_to_db(), "a");
  if (!out) {
    return -1;
  }

  char *hash = generate_hash();
  if (!hash) {
    fclose(out);
    return -1;
  }

  fprintf(out, "%s %s\n", hash, str);
  free(hash);
  fclose(out);

  printf(" > New entry has been added.\n");
  return 0;
}