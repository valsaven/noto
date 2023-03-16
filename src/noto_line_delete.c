#include "noto_line_delete.h"

#define BUFFER_SIZE 10000

/**
 * Удаляет заданную строку из файла.
 */
int noto_line_delete(FILE *srcFile, FILE *tempFile, int line) {
  if (srcFile == NULL || tempFile == NULL) {
    // Обработка ошибки открытия файла
    return -1;
  }

  char buffer[BUFFER_SIZE];
  int count = 1;

  while (fgets(buffer, BUFFER_SIZE, srcFile) != NULL) {
    if (count != line) {
      fputs(buffer, tempFile);
    }
    count++;
  }

  return 0;
}
