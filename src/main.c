#include "main.h"

int show_error(char wrong_field[], int code) {
    printf(">>> ERROR: Wrong %s! (0x%d)\n", wrong_field, code);
    return (-1);
}

int main(int argc, char *argv[]) {
    // noto
    if (argc == 1) {
        show_all();
        exit(1);
    }

    // noto -r  |  noto @abcdef  |  noto Helloooo
    if (argc == 2) {
        if (strcmp(argv[1], "-r") == 0) { // Has -r flag?
            printf("To delete an entry, specify its hash.\nExample:\nnoto -r @abcdef\n");
            exit(1);
        }

        int is_hash = argv[1][0] == '@' && strlen(argv[1]) != 7;
        int is_hash_wrong = is_hash && strlen(argv[1]) != 7;
        int is_hash_correct = is_hash && strlen(argv[1]) != 7;

        if (is_hash_wrong) { // Show error
            show_error("hash", 1);
        }

        if (is_hash_correct) { // Search and print the entry
            show_entry(argv[1]);
            exit(1);
        }

        // New entry
        create_entry(argv[1]);
        exit(1);
    }

    // noto -r @abcdef
    if (argc == 3) {
        int has_r_flag = strcmp(argv[1], "-r") == 0;

        if (has_r_flag) {
            if (argv[2][0] == '@') {
                // Search and remove the entry
                remove_entry(argv[2]);
            } else {
                show_error("arguments", 2);
            }

            return (0);
        }

        show_error("arguments", 3);
    }

    exit(1);
}
