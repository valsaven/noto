#include "noto_line_delete.h"

#define BUFFER_SIZE 10000

/**
 * Удаляет заданную строку из файла.
 */
void noto_line_delete(FILE *srcFile, FILE *tempFile, int line) {
  char buffer[BUFFER_SIZE];
  int count = 1;

  // Читаем файл блоками по BUFFER_SIZE байт
  size_t bytesRead;
  while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, srcFile)) > 0) {
    // Обрабатываем каждую строку в буфере
    for (char *p = buffer; p < buffer + bytesRead; p++) {
      // Если текущая строка не является строкой, которую пользователь хотел удалить
      if (line != count) {
        fputc(*p, tempFile);
      }

      // Увеличиваем счетчик строк при встрече символа новой строки
      if (*p == '\n') {
        count++;
      }
    }
  }
}
