#include "noto.h"

/**
 * Remove the entry.
 */
int remove_entry(char *id) {
  FILE *fp;
  FILE *srcFile;
  FILE *tempFile;

  int line_num = 1;

  char temp[512];
  char *path = get_path_to_db();
  char *tempMask = ".tmp";

  size_t len = strlen(path) + strlen(tempMask) + 1;
  char *temp_path = malloc(len);
  strcpy(temp_path, path);
  strcat(temp_path, tempMask);

  if ((fp = fopen(get_path_to_db(), "r")) == NULL) {
    printf(">>> ERROR: Can't open DB file! (0x4)\n");
    return (-1);
  }

  while (fgets(temp, 512, fp) != NULL) {
    if ((strstr(temp, id)) != NULL) {
      // Close the file if still open.
      if (fp) {
        fclose(fp);
      }

      /* Try to open file */
      srcFile = fopen(path, "r");
      tempFile = fopen(temp_path, "w");

      /* Exit if file not opened successfully */
      if (srcFile == NULL || tempFile == NULL) {
        printf(">>> ERROR: Unable to open file! (0x5)\n");
        exit(EXIT_FAILURE);
      }

      // Move src file pointer to beginning
      rewind(srcFile);
      // Delete given line from file.
      delete_line(srcFile, tempFile, line_num);

      /* Close all open files */
      fclose(srcFile);
      fclose(tempFile);

      /* Delete src file and rename temp file as src */
      remove(path);
      rename(temp_path, path);

      printf("\n>> The %s entry has been removed.\n", id);

      return (0);
    }

    line_num++;
  }

  printf("\n>> An entry with this hash doesn't exist. <<\n");

  return (0);
}
