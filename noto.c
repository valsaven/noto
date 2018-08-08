#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createNewDB();
void showAll();
void Usage(char *filename);
int Search_in_File(char *fname, char *str);

// MAIN
int main(int argc, char *argv[]) {
	int result, errno;

	if (argc == 1) {
		showAll();
		exit(1);
	} else if (argc == 2) { // hash or -r flag without value
		int hasRemoveFlag = strcmp(argv[1], "-r") == 0;
		if (hasRemoveFlag) {
			printf("To delete an entry, specify its hash.\nExample:\nnoto -r #abcdef\n");
		}
	}

	if (argc < 3 || argc > 3) {
		exit(1);
	}

	system("clear");

	result = Search_in_File(argv[1], argv[2]);
	if (result == -1) {
		perror("Error");
		printf("Error number = %d\n", errno);
		exit(1);
	}
	return (0);
}

// FUNCTIONS
void Usage(char *filename) {
	printf("Usage: %s <file> <string>\n", filename);
}

int Search_in_File(char *fname, char *str) {
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char temp[512];

	if ((fp = fopen(fname, "r")) == NULL) {
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

	printf("> Search returned %d results < \n", line_num - 1);

	if (find_result == 0) {
		printf("\nSorry, couldn't find a match.\n");
	}

	// Close the file if still open.
	if (fp) {
		fclose(fp);
	}
	return (0);
}

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
		printf("-----------\n");
		printf("Your notes:\n");
		printf("-----------\n");

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
void showEntry() {}

// Remove the entry.
void removeEntry(char *id) {
	printf("%s entry has been removed.\n", id);
}
