#include "get.h"

char *get_path_to_db() {
    char *home = getenv("HOME");

    if (home == NULL) { // If not linux
        char path[512];

        strcpy(path, getenv("HOMEDRIVE"));
        strcat(path, getenv("HOMEPATH"));

        home = path;

        if (home == NULL) printf(">>> ERROR: Can't find HOME env!");
    }

    char *path = "/db";
    size_t len = strlen(home) + strlen(path) + 1;
    char *full_path = malloc(len);
    if (full_path == NULL) printf(">>> ERROR: Can't get full path!");

    strcpy(full_path, home);
    strcat(full_path, path);

    return full_path;
}
