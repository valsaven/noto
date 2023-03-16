#include "noto_entry_show_all.h"

#define BUFFER_SIZE 10000

void noto_db_create();
char *noto_db_get_path();

/**
 * Show all entries.
 */
void noto_entry_show_all() {
  char line[BUFFER_SIZE];
  FILE *file;

  file = fopen(noto_db_get_path(), "r");

  if (file == NULL) {
    // Can't open file
    noto_db_create();
    return;
  }

  printf("\n----------------\n");
  printf("|  Your notes  |\n");
  printf("----------------\n\n");

  while (fgets(line, BUFFER_SIZE, file) != NULL) {
    puts(line);
  }

  fclose(file);
}
