#include "headers/show_all.h"

#include "headers/get_path_to_db.h"
#include "headers/create_new_db.h"

#define CHUNK 1024 /* read 1024 bytes at a time */

/**
 * Show all entries.
 */
void show_all() {
    char buf[CHUNK];
    FILE *file;
    size_t nread;

    file = fopen(get_path_to_db(), "r");

    if (file) {
        printf("\n----------------\n");
        printf("|  Your notes  |\n");
        printf("----------------\n\n");

        while ((nread = fread(buf, 1, sizeof buf, file)) > 0) {
            fwrite(buf, 1, nread, stdout);
        }

        if (ferror(file)) {
            printf("Error! Opening file.\n");
            exit(1);
        }

        fclose(file);
    } else { // Can't open file
        create_new_db();
    }
}
