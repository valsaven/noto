#include "noto.h"

char *get_path_to_db() {
  const char *home = getenv("HOME");

  if (home == NULL) { // If not linux
    home = getenv("USERPROFILE");

    if (home == NULL) {
      printf(">>> ERROR: Can't find HOME env!");
    }
  }

  const char *path = "/noto_db.txt";
  const size_t len = strlen(home) + strlen(path) + 1;
  char *full_path = malloc(len);
  if (full_path == NULL) {
    printf(">>> ERROR: Can't get full path!");
  }

  strcpy(full_path, home);
  strcat(full_path, path);

  return full_path;
}
