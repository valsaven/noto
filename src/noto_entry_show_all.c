#include "noto_entry_show_all.h"

#define BUFFER_SIZE 10000

void noto_db_create();
char *noto_db_get_path();

/**
 * Show all entries.
 */
void noto_entry_show_all() {
  char buffer[BUFFER_SIZE];
  char outputBuffer[BUFFER_SIZE];
  FILE *file;
  size_t bytesRead;

  file = fopen(noto_db_get_path(), "r");

  if (file) {
    setvbuf(file, buffer, _IOFBF, BUFFER_SIZE);
    setvbuf(stdout, outputBuffer, _IOFBF, BUFFER_SIZE);

    printf("\n----------------\n");
    printf("|  Your notes  |\n");
    printf("----------------\n\n");

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
      fwrite(buffer, 1, bytesRead, stdout);
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
