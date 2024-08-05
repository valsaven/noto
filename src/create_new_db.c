#include "create.h"

/**
 * Create new DB file.
 */
void create_new_db() {
    FILE *fp;
    fp = fopen(get_path_to_db(), "w");
    fclose(fp);
    printf("The new DB file has been created.\n");
}
