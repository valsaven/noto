#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers/generate_hash.h"
#include "headers/get_path_to_db.h"

/**
 * Create the entry.
 */
int create_entry(char *str) {
    FILE *out = fopen(get_path_to_db(), "a");
    srand(time(NULL));
    char *hash = generate_hash();
    fprintf(out, "%s %s\n", hash, str);
    fclose(out);
    printf(" > New entry has been added.\n");
    return (0);
}
