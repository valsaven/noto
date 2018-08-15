#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int result, errno;

	if (argc == 1) {
		showAll();
		exit(1);
	} else if (argc == 2) { // hash or -r flag without value
		// Is it -r flag?
		int hasRemoveFlag = strcmp(argv[1], "-r") == 0;
		if (hasRemoveFlag) {
			printf("To delete an entry, specify its hash.\nExample:\nnoto -r @abcdef\n");
		} else {
			// Is it hash?
			if (strlen(argv[1]) != 7) {
				printf(">>> ERROR: Wrong hash!\n");
				// createEntry();
				return (-1);
			} else {
				if (argv[1][0] == '#' || argv[1][0] == '@') { // TODO: Remove # support
					// Search and print the entry
					showEntry(argv[1]);
				} else {
					printf(">>> No hash here...\n");
				}
			}
		}
	} else if (argc == 3) { // 2 args (-r @abcdef)
		printf(">>>>>>>>>>> 3");
		int hasRemoveFlag = strcmp(argv[1], "-r") == 0;
		if (hasRemoveFlag) { // Has -r flag
			if (argv[2][0] == '@') { // TODO: Remove # support
					printf(">>> Hash is %s\n", argv[2]);
					// Search and remove the entry
					removeEntry(argv[2]);
				} else {
					printf(">>> ERROR: Wrong arguments!\n");
					return (-1);
				}
			return (0);
		} else {
			printf(">>> ERROR: Wrong arguments!\n");
			return (-1);
		}
	}

	if (argc < 3 || argc > 3) {
		exit(1);
	}

	system("clear");

	// result = Search_in_File(argv[1], argv[2]);
	// if (result == -1) {
	// 	perror("Error");
	// 	printf("Error number = %d\n", errno);
	// 	exit(1);
	// }
	return (0);
}
