#include <time.h>
#include "noto_hash_generate.h"

char *noto_hash_generate() {
  // Символы, из которых состоит хеш
  const char alphabet[] = "abcdefghijklmnopqrstuvwxyz0123456789";
  const size_t alphabet_size = sizeof(alphabet) - 1;

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

  // Получаем текущее время
  time_t current_time = time(NULL);

  // Используем счетчик для увеличения уникальности хеша
  static unsigned int counter = 0;
  counter++;

  // Создаем уникальный идентификатор на основе текущего времени и счетчика
  unsigned long long unique_id = (unsigned long long)current_time * 1000 + counter;

  hash[0] = '@';

  // Генерируем хеш на основе уникального идентификатора
  for (int i = 1; i < len; i++) {
    hash[i] = alphabet[unique_id % alphabet_size];
    unique_id /= alphabet_size;
  }

  // Добавляем нулевой символ в конец хеша
  hash[len] = '\0';

  return hash;
}
