#include "noto_db_create.h"

char *noto_db_get_path();

/**
 * Create new DB file.
 */
void noto_db_create() {
  FILE *fp = fopen(noto_db_get_path(), "w");

  if (fp == NULL) {
    perror("Error opening file");
    fclose(fp);
    return;
  }

  fclose(fp);
  printf("New DB file has been created.\n");
}
