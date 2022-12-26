#include "noto_entry_create.h"

char *noto_hash_generate();
char *noto_db_get_path();

/**
 * Create the entry.
 */
int noto_entry_create(char *str) {
  // Открываем файл в режиме добавления
  FILE *out = fopen(noto_db_get_path(), "a");
  if (!out) {
    perror("Error opening file");
    fclose(out);
    return 1;
  }

  // Генерируем хеш
  char *hash = noto_hash_generate();
  if (!hash) {
    perror("Error generating hash");
    fclose(out);
    return 1;
  }

  // Записываем хеш и строку в файл
  fputs(hash, out);
  fputs(" ", out);
  fputs(str, out);
  fputs("\n", out);

  // Закрываем файл
  fclose(out);
  printf(" > New entry has been added.\n");

  return 0;
}
