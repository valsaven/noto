#include "noto_entry_create.h"
#include "noto_hash_is_unique.h"

char *noto_hash_generate();
char *noto_db_get_path();

#define MAX_ATTEMPTS 100

/**
 * Create the entry.
 */
int noto_entry_create(char *str) {
  // Открываем файл в режиме добавления
  FILE *out = fopen(noto_db_get_path(), "a");
  if (!out) {
    perror("Error opening file");
    return -1;
  }

  // Генерируем хеш
  char *hash = noto_hash_generate();
  if (!hash) {
    perror("Error generating hash");
    fclose(out);
    return -1;
  }

  // Проверяем уникальность хеша
  int attempts = 0;
  while (!noto_hash_is_unique(hash, out) && attempts < MAX_ATTEMPTS) {
    free(hash);
    hash = noto_hash_generate();
    if (!hash) {
      perror("Error generating hash");
      fclose(out);
      return -1;
    }
    attempts++;
  }

  if (attempts == MAX_ATTEMPTS) {
    fprintf(stderr, "Error: too many hash collisions. Try again later or use another string.\n");
    fclose(out);
    free(hash);
    return -1;
  }

  // Записываем хеш и строку в файл
  fprintf(out, "%s %s\n", hash, str);

  // Закрываем файл
  fclose(out);
  printf(" > New entry has been added.\n");

  // Освободить память, выделенную для хеша
  free(hash);

  return 0;
}
