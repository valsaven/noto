#include <CUnit/CUnit.h>
#include <string.h>
#include <ctype.h>
#include "../include/noto_hash_generate.h"

void test_noto_hash_generate() {
  char *hash1 = noto_hash_generate();
  CU_ASSERT_PTR_NOT_NULL_FATAL(hash1);
  CU_ASSERT_TRUE(hash1[0] == '@');

  char *hash2 = noto_hash_generate();
  CU_ASSERT_PTR_NOT_NULL_FATAL(hash2);
  CU_ASSERT_TRUE(hash2[0] == '@');

  CU_ASSERT_STRING_NOT_EQUAL(hash1, hash2);

  for (int i = 0; i < 2; ++i) {
    char *hash = i == 0 ? hash1 : hash2;
    CU_ASSERT_PTR_NOT_NULL_FATAL(hash);
    CU_ASSERT_EQUAL(strlen(hash), 7);

    for (int j = 1; j < 7; ++j) {
      CU_ASSERT_TRUE(islower(hash[j]) || isdigit(hash[j]));
    }
  }

  free(hash1);
  free(hash2);
}
