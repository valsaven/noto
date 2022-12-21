#include "noto_create_new_db.h"

char *noto_get_path_to_db();

/**
 * Create new DB file.
 */
void noto_create_new_db() {
  FILE *fp;
  fp = fopen(noto_get_path_to_db(), "w");
  fclose(fp);
  printf("The new DB file has been created.\n");
}
