#include "noto_db_create.h"

char *noto_db_get_path();

/**
 * Create new DB file.
 */
void noto_db_create() {
  FILE *fp;
  fp = fopen(noto_db_get_path(), "w");
  fclose(fp);
  printf("The new DB file has been created.\n");
}
