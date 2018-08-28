#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1000
#define CHUNK 1024 /* read 1024 bytes at a time */

char *getPathToDB() {
	char *home = getenv("HOME");
	if (home == NULL) printf(">>> ERROR: Can't find HOME env!");

	char *path = "/db";
	size_t len = strlen(home) + strlen(path) + 1;
	char *fullpath = malloc(len);
	if (fullpath == NULL) printf(">>> ERROR: Can't get full path!");

	strcpy(fullpath, home);
	strcat(fullpath, path);

	return fullpath;
}

/**
 * Create new DB file.
 */
void createNewDB() {
	FILE *fp;
	fp = fopen(getPathToDB(), "w");
	fclose(fp);
	printf("The new DB file has been created.\n");
}

/**
 * Show all entries.
 */
void showAll() {
	char buf[CHUNK];
	FILE *file;
	size_t nread;

	file = fopen(getPathToDB(), "r");

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
		createNewDB();
	}
}

/**
 * Show the entry.
 */
int showEntry(char *str) {
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char temp[512];

	if ((fp = fopen(getPathToDB(), "r")) == NULL) {
		fp = fopen(getPathToDB(), "w");
		fclose(fp);
		printf("The new DB file has been created.");
		return (0);
	}

	while (fgets(temp, 512, fp) != NULL) {
		if ((strstr(temp, str)) != NULL) {
			printf("%s\n", temp);
			find_result++;
		}
		line_num++;
	}

	if (find_result == 0) {
		printf("\n>> An entry with this hash doesn't exist. <<\n");
	}

	// Close the file if still open.
	if (fp) {
		fclose(fp);
	}
	return (0);
}

char *generateHash() {
	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz0123456789";
	int len = 7;
	char *hash = malloc((len + 1) * sizeof(char));
	int i;

	hash[0] = '@';

	for (i = 1; i < len; i++) {
		hash[i] = alphabet[rand() % (strlen(alphabet))];
	}

	hash[len] = '\0';

	return hash;
}

/**
 * Create the entry.
 */
int createEntry(char *str) {
	FILE *out = fopen(getPathToDB(), "a");
	srand(time(NULL));
	char *hash = generateHash();
	fprintf(out, "%s %s\n", hash, str);
	fclose(out);
	printf(" > New entry has been added.\n");
	return (0);
}

/**
 * Remove the entry.
 */
int removeEntry(char *id) {
	FILE *fp;
	FILE *srcFile;
	FILE *tempFile;

	int line_num = 1;

	char temp[512];
	char *path = getPathToDB();
	char *tempMask = ".tmp";

	size_t len = strlen(path) + strlen(tempMask) + 1;
	char *temp_path = malloc(len);
	strcpy(temp_path, path);
	strcat(temp_path, tempMask);

	if ((fp = fopen(getPathToDB(), "r")) == NULL) {
		printf(">>> ERROR: Can't open DB file! (0x4)\n");
		return (-1);
	}

	while (fgets(temp, 512, fp) != NULL) {
		if ((strstr(temp, id)) != NULL) {
			// Close the file if still open.
			if (fp) fclose(fp);

			/* Try to open file */
			srcFile = fopen(path, "r");
			tempFile = fopen(temp_path, "w");

			/* Exit if file not opened successfully */
			if (srcFile == NULL || tempFile == NULL) {
				printf(">>> ERROR: Unable to open file! (0x5)\n");
				exit(EXIT_FAILURE);
			}

			// Move src file pointer to beginning
			rewind(srcFile);
			// Delete given line from file.
			deleteLine(srcFile, tempFile, line_num);

			/* Close all open files */
			fclose(srcFile);
			fclose(tempFile);

			/* Delete src file and rename temp file as src */
			remove(path);
			rename(temp_path, path);

			printf("\n>> The %s entry has been removed.\n", id);

			return (0);
		}

		line_num++;
	}

	printf("\n>> An entry with this hash doesn't exist. <<\n");

	return (0);
}

/**
 * Delete a given line from file.
 */
void deleteLine(FILE *srcFile, FILE *tempFile, int line) {
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
