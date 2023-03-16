#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#include "noto_db_get_path.h"

char *noto_db_get_path() {
  const char *home = getenv("HOME");

  if (home == NULL) {
    home = getenv("HOMEDRIVE");

    if (home != NULL) {
      home = getenv("HOMEPATH");
    }

    if (home == NULL) {
      fprintf(stderr, ">>> ERROR: Can't find HOME env!\n");
      return NULL;
    }
  }

  const char *path = "/noto_db.txt";
  long path_max = pathconf(path, _PC_PATH_MAX);

  if (path_max == -1) {
    path_max = 4096; // Default value
  }

  char *full_path = malloc(path_max);

  if (full_path == NULL) {
    fprintf(stderr, ">>> ERROR: Can't get full path!\n");
    return NULL;
  }

  int result = snprintf(full_path, path_max, "%s%s", home, path);

  if (result < 0 || result >= path_max) {
    fprintf(stderr, ">>> ERROR: Can't create full path!\n");
    free(full_path);
    return NULL;
  }

  return full_path;
}
