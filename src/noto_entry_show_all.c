#include "noto_entry_show_all.h"

#define CHUNK 1024 /* read 1024 bytes at a time */

void noto_db_create();
char *noto_db_get_path();

/**
 * Show all entries.
 */
void noto_entry_show_all() {
  char buf[CHUNK];
  FILE *file;
  size_t nread;

  file = fopen(noto_db_get_path(), "r");

  if (file) {
    printf("\n----------------\n");
    printf("|  Your notes  |\n");
    printf("----------------\n\n");

    while ((nread = fread(buf, 1, sizeof buf, file)) > 0) {
      fwrite(buf, 1, nread, stdout);
    }

    if (ferror(file)) {
      printf("Error! Opening file.\n");
      exit(1);
    }

    fclose(file);
  } else { // Can't open file
    noto_db_create();
  }
}
