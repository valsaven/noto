#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create new DB file.
void createNewDB() {
	FILE *fp;
	fp = fopen("db", "w");
	fclose(fp);
	printf("The new DB file has been created.\n");
}

// Show all entries.
void showAll() {
	#define CHUNK 1024 /* read 1024 bytes at a time */
	char buf[CHUNK];
	FILE *file;
	size_t nread;

	file = fopen("db", "r");

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

// Show the entry.
int showEntry(char *str) {
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char temp[512];

	if ((fp = fopen("db", "r")) == NULL) {
		fp = fopen("db", "w");
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
		printf("\nSorry, couldn't find a match.\n");
	}

	// Close the file if still open.
	if (fp) {
		fclose(fp);
	}
	return (0);
}

// Remove the entry.
void removeEntry(char *id) {
	printf("%s entry has been removed.\n", id);
}
