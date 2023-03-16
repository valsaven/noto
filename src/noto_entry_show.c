#include "noto_entry_show.h"

#define BUFFER_SIZE 512

char *noto_db_get_path();

/**
 * Show the entry.
 */
int noto_entry_show(char *str) {
  FILE *fp;
  size_t find_result = 0;
  char temp[BUFFER_SIZE];

  if ((fp = fopen(noto_db_get_path(), "r")) == NULL) {
    fp = fopen(noto_db_get_path(), "w");

    fclose(fp);

    printf("The new DB file has been created.");

    return 0;
  }

  while (fgets(temp, BUFFER_SIZE, fp) != NULL) {
    if ((strstr(temp, str)) != NULL) {
      // Находим позицию пробела после хеша
      char *space_position = strchr(temp, ' ');

      if (space_position != NULL) {
        // Выводим значение, начиная с символа после пробела
        printf("%s", space_position + 1);
      } else {
        printf("Invalid entry format: %s\n", temp);
      }

      find_result++;
    }
  }

  if (find_result == 0) {
    printf("\n>> An entry with this hash doesn't exist. <<\n");
  }

  // Close the file.
  fclose(fp);

  return 0;
}
