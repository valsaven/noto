#include "noto.h"

int noto_entry_create(char *str);
int noto_entry_delete(char *id);
int noto_entry_show(char *str);
void noto_entry_show_all();

int show_error(char wrong_field[], int code) {
  printf(">>> ERROR: Wrong %s! (0x%d)\n", wrong_field, code);
  return (-1);
}

int main(int argc, char *argv[]) {
  // noto
  if (argc == 1) {
    noto_entry_show_all();
    exit(1);
  }

  // noto -d  |  noto @abcdef  |  noto Hello | noto "Buy some coffee"
  if (argc == 2) {
    // noto -d
    if (strcmp(argv[1], "-d") == 0) { // Has -d flag?
      printf(
          "To delete an entry, specify its hash.\nExample:\nnoto -r @abcdef\n");
      exit(1);
    }

    int is_hash = argv[1][0] == '@';
    int is_hash_wrong = is_hash && strlen(argv[1]) != 7;
    int is_hash_correct = is_hash && strlen(argv[1]) == 7;

    // noto @a
    if (is_hash_wrong) { // Show error
      show_error("hash", 1);
    }

    // noto @abcdef
    if (is_hash_correct) { // Search and print the entry
      noto_entry_show(argv[1]);
      exit(1);
    }

    // New entry
    noto_entry_create(argv[1]);
    exit(1);
  }

  // noto -d @abcdef
  if (argc == 3) {
    int has_r_flag = strcmp(argv[1], "-d") == 0;

    if (has_r_flag) {
      if (argv[2][0] == '@') {
        // Search and remove the entry
        noto_entry_delete(argv[2]);
      } else {
        show_error("arguments", 2);
      }

      return (0);
    }

    show_error("arguments", 3);
  }

  exit(1);
}
