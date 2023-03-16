#include "noto_hash_is_unique.h"

bool noto_hash_is_unique(const char *hash, FILE *file) {
  char line[512];
  fseek(file, SEEK_SET, 0); // Перемещаем указатель файла в начало

  while (fgets(line, sizeof(line), file) != NULL) {
    if (strstr(line, hash) != NULL) {
      return false;
    }
  }

  return true;
}
