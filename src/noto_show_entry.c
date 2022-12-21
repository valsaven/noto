#include "noto_show_entry.h"

char *noto_get_path_to_db();

/**
 * Show the entry.
 */
int noto_show_entry(char *str) {
  FILE *fp;
  int line_num = 1;
  int find_result = 0;
  char temp[512];

  if ((fp = fopen(noto_get_path_to_db(), "r")) == NULL) {
    fp = fopen(noto_get_path_to_db(), "w");
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
