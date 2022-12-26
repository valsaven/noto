#include "noto_entry_show.h"

char *noto_db_get_path();

/**
 * Show the entry.
 */
int noto_entry_show(char *str) {
  FILE *fp;
  int line_num = 1;
  int find_result = 0;
  char temp[512];

  if ((fp = fopen(noto_db_get_path(), "r")) == NULL) {
    fp = fopen(noto_db_get_path(), "w");
    fclose(fp);
    printf("The new DB file has been created.");
    return (0);
  }

  while (fgets(temp, 512, fp) != NULL) {
    if ((strstr(temp, str)) != NULL) {
      printf("%s\n", temp);
      find_result++;
    }
    line_num++;
  }

  if (find_result == 0) {
    printf("\n>> An entry with this hash doesn't exist. <<\n");
  }

  // Close the file if still open.
  if (fp) {
    fclose(fp);
  }
  return (0);
}
