#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Usage(char * filename);
int Search_in_File(char * fname, char * str);

// MAIN
int main(int argc, char * argv[]) {
	int result, errno;

	if (argc < 3 || argc > 3) {
		Usage(argv[0]);
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
void Usage(char * filename) {
	printf("Usage: %s <file> <string>\n", filename);
}

int Search_in_File(char * fname, char * str) {
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
