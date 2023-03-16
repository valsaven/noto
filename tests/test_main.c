#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include "test_noto.h"

int main() {
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry()) {
    return CU_get_error();
  }

  pSuite = CU_add_suite("NotoSuite", NULL, NULL);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (NULL == CU_add_test(pSuite, "test_noto_hash_generate", test_noto_hash_generate)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();

  return CU_get_error();
}
