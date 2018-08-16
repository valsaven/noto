#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int result, errno;

	switch(argc) {
		case 1:
			// noto
			showAll();
			exit(1);
		case 2:
			// noto -r  |  noto @abcdef  |  noto Helloooo
			if (strcmp(argv[1], "-r") == 0) { // Has -r flag?
				printf("To delete an entry, specify its hash.\nExample:\nnoto -r @abcdef\n");
				exit(1);
			} else {
				// Is it hash?
				if (strlen(argv[1]) != 7) {
					printf(">>> ERROR: Wrong hash!\n");
					createEntry(argv[1]);
					return (-1);
				} else {
					if (argv[1][0] == '@') {
						// Search and print the entry
						showEntry(argv[1]);
					} else {
						printf(">>> No hash here...\n");
					}
				}
			}
		case 3:
			// noto -r @abcdef
			if (strcmp(argv[1], "-r") == 0) { // Has -r flag
				if (argv[2][0] == '@') {
					printf(">>> Hash is %s\n", argv[2]);
					// Search and remove the entry
				} else {
					printf(">>> ERROR: Wrong arguments!\n");
					return (-1);
				}
				return (0);
			} else {
				printf(">>> ERROR: Wrong arguments!\n");
				return (-1);
			}
			break;
		default :
			exit(1);
	}

	system("clear");

	return (0);
}
