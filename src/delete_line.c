#include "main.h"

#define BUFFER_SIZE 1000

/**
 * Delete a given line from file.
 */
void delete_line(FILE *srcFile, FILE *tempFile, int line) {
    char buffer[BUFFER_SIZE];
    int count = 1;

    while ((fgets(buffer, BUFFER_SIZE, srcFile)) != NULL) {
        /* If current line is not the line user wanted to remove */
        if (line != count) {
            fputs(buffer, tempFile);
        }
        count++;
    }
}
