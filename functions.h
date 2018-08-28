#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>

void createNewDB();
void showAll();
int showEntry(char *str);
int createEntry(char *str);
void deleteLine(FILE *srcFile, FILE *tempFile, int line);
int removeEntry(char *id);

#endif
