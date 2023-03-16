#include "noto.h"

#define HASH_LENGTH 7

typedef enum {
  WRONG_HASH = 1,
  WRONG_ARGUMENTS_2,
  WRONG_ARGUMENTS_3
} ErrorCode;

int noto_entry_create(char *str);
int noto_entry_delete(char *id);
int noto_entry_show(char *str);
void noto_entry_show_all();

int show_error(char wrong_field[], int code) {
  printf(">>> ERROR: Wrong %s! (0x%d)\n", wrong_field, code);
  return -1;
}

int handle_one_argument(char *arg) {
    // noto -d
    if (strcmp(arg, "-d") == 0) { // Has -d flag?
      printf(
          "To delete an entry, specify its hash.\nExample:\nnoto -r @abcdef\n");
      return 1;
    }

    int is_hash = arg[0] == '@';
    int is_hash_wrong = is_hash && strlen(arg) != HASH_LENGTH;
    int is_hash_correct = is_hash && strlen(arg) == HASH_LENGTH;


    // noto @a
    if (is_hash_wrong) { // Show error
      show_error("hash", WRONG_HASH);
    }

    // noto @abcdef
    if (is_hash_correct) { // Search and print the entry
      noto_entry_show(arg);
      return 1;
    }

    // New entry
    int entry_create_result = noto_entry_create(arg);

    if (entry_create_result != 0) {
      printf(">>> ERROR: Unable to create entry! (0x6)\n");
      exit(EXIT_FAILURE);
    }

    return 1;
}

int handle_two_arguments(char *arg1, char *arg2) {
  int has_r_flag = strcmp(arg1, "-d") == 0;

  if (has_r_flag) {
    if (arg2[0] == '@') {
      // Search and remove the entry
      noto_entry_delete(arg2);
    } else {
      show_error("arguments", WRONG_ARGUMENTS_2);
    }

    return 0;
  }

  show_error("arguments", WRONG_ARGUMENTS_3);
}

int main(int argc, char *argv[]) {
 switch (argc) {
    case 1:
      // noto
      noto_entry_show_all();
      break;
    case 2:
      // noto -d  |  noto @abcdef  |  noto Hello | noto "Buy some coffee"
      handle_one_argument(argv[1]);
      break;
    case 3:
      // noto -d @abcdef
      handle_two_arguments(argv[1], argv[2]);
      break;
    default:
      show_error("arguments", WRONG_ARGUMENTS_3);
      return 1;
  }
}
