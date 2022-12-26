#include "noto_hash_generate.h"

char *noto_hash_generate() {
  // Символы, из которых состоит хеш
  const char alphabet[] = "abcdefghijklmnopqrstuvwxyz0123456789";

  // Длина хеша
  const int len = 7;

  // Выделяем память под хеш
  char *hash = malloc((len + 1) * sizeof(char));
  if (!hash) {
    perror("Error allocating memory for hash");
    return NULL;
  }

  // Инициализируем генератор случайных чисел
  srand(time(NULL));

  hash[0] = '@';

  // Заполняем хеш случайными символами
  for (int i = 1; i < len; i++) {
    hash[i] = alphabet[rand() % (strlen(alphabet))];
  }

  // Добавляем нулевой символ в конец хеша
  hash[len] = '\0';

  return hash;
}
