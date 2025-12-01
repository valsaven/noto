#include "noto.h"
#include <stdlib.h>
#include <string.h>

/**
 * Check if a hash already exists in the database file.
 * Returns 1 if duplicate found, 0 otherwise.
 */
static int hash_exists(const char *hash) {
  FILE *fp = fopen(get_path_to_db(), "r");
  if (!fp) {
    return 0; // File does not exist - no duplicates
  }


  char line[512];
  while (fgets(line, sizeof(line), fp)) {
    // Compare exactly 7 characters: "@abcdef"
    if (strncmp(line, hash, 7) == 0) {
      fclose(fp);
      return 1; // Duplicate found
    }
  }
  fclose(fp);
  return 0; // No duplicate
}

/**
 * Generate a unique 7-character hash starting with '@'.
 * Tries up to 1000 times to find a non-duplicate.
 * Returns the hash on success, NULL on failure.
 */
char *generate_hash(void) {
  constexpr char alphabet[] = "abcdefghijklmnopqrstuvwxyz0123456789";
  constexpr size_t alph_len = sizeof(alphabet) - 1;
  constexpr int max_attempts = 1000;

  char *hash = malloc(8); // @ + 6 chars + '\0' = 8 bytes
  if (!hash) {
    return nullptr;
  }

  for (int attempt = 0; attempt < max_attempts; attempt++) {
    hash[0] = '@';
    for (int i = 1; i <= 6; i++) { // Exactly 6 random characters
      hash[i] = alphabet[(unsigned)rand() % alph_len];
    }
    hash[7] = '\0'; // Null terminator

    if (!hash_exists(hash)) {
      return hash; // Unique - return it
    }
    // Otherwise, try again
  }

  // Highly unlikely, but just in case
  free(hash);
  return nullptr;
}