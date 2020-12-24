#include "functions.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	switch (argc) {
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
				if (argv[1][0] == '@' && strlen(argv[1]) != 7) {
					printf(">>> ERROR: Wrong hash! (0x1)\n");
					return (-1);
				} else {
					if (argv[1][0] == '@' && strlen(argv[1]) == 7) {
						// Search and print the entry
						showEntry(argv[1]);
						exit(1);
					} else { // New entry
						createEntry(argv[1]);
						exit(1);
					}
				}
			}
		case 3:
			// noto -r @abcdef
			if (strcmp(argv[1], "-r") == 0) { // Has -r flag
				if (argv[2][0] == '@') {
					// Search and remove the entry
					removeEntry(argv[2]);
				} else {
					printf(">>> ERROR: Wrong arguments! (0x2)\n");
					return (-1);
				}
				return (0);
			} else {
				printf(">>> ERROR: Wrong arguments! (0x3)\n");
				return (-1);
			}
		default :
			exit(1);
	}
}
