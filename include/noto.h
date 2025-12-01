#ifndef NOTO_H
#define NOTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define BUFFER_SIZE 1000

// Function prototypes
char *get_path_to_db(void);
char *generate_hash(void);

int create_entry(char *str);
void create_new_db(void);

void delete_line(FILE *srcFile, FILE *tempFile, int line);

int remove_entry(char *id);

void show_all(void);
int show_entry(char *str);

#endif // NOTO_H
