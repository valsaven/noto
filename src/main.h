#ifndef NOTO_MAIN_H
#define NOTO_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *generate_hash();
char *get_path_to_db();

int create_entry(char *str);
int remove_entry(char *id);
int show_entry(char *str);

void create_new_db();
void delete_line(FILE *srcFile, FILE *tempFile, int line);
void show_all();

#endif //NOTO_MAIN_H
