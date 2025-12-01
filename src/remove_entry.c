#include "noto.h"

/**
 * Remove the entry.
 */
int remove_entry(char *id) {
  const char *path = get_path_to_db();
  const char *tempMask = ".tmp";

  const size_t len = strlen(path) + strlen(tempMask) + 1;

  char *const temp_path = malloc(len);
  if (!temp_path) {
    perror("malloc");
    return -1;
  }
  strcpy(temp_path, path);
  strcat(temp_path, tempMask);

  // Open DB and find line number
  FILE *fp = fopen(path, "r");
  if (!fp) {
    free(temp_path);
    printf(">>> ERROR: Can't open DB file! (0x4)\n");
    return -1;
  }

  int line_num = 1;
  char line[512];
  int found = 0;

  while (fgets(line, sizeof(line), fp)) {
    if (strstr(line, id)) {
      found = 1;
      break;
    }
    line_num++;
  }
  fclose(fp);

  if (!found) {
    free(temp_path);
    printf("\n>> An entry with this hash doesn't exist.\n");
    return 0;
  }

  // Now actually delete the line
  FILE *srcFile  = fopen(path, "r");
  FILE *tempFile = fopen(temp_path, "w");
  if (!srcFile || !tempFile) {
    perror("fopen");

    fclose(srcFile);
    fclose(tempFile);
    free(temp_path);

    return -1;
  }

  delete_line(srcFile, tempFile, line_num);

  fclose(srcFile);
  fclose(tempFile);

  if (remove(path) != 0 || rename(temp_path, path) != 0) {
    perror("remove/rename");
    free(temp_path);
    return -1;
  }

  free(temp_path);
  printf("\n>> The %s entry has been removed.\n", id);
  return 0;
}
