#include "main.h"

int main(int argc, char *argv[]) {

    // Если первый аргумент --help - выводим подсказку
    // Если -r - запускается ф-я удаления записи, где проверяется наличие хэша
    // Иначе всё до нажатия Enter - текст для записи
    int count;
    char* entryText;
    char* firstWord = argv[1];

    entryText = malloc(strlen(firstWord) + 4 * sizeof(char) + 1);

//    char* name_with_extension;
//    name_with_extension = malloc(strlen(name)+1+4); /* make space for the new string (should check the return value ...) */
    strcpy(entryText, firstWord); /* copy name into the new var */

//    strcpy(entryText, name); /* copy name into the new var */
//    strcat(entryText, extension); /* add the extension */

    for (count = 2; count < argc; count ++) {
        printf("%d: %s\n", count, argv[count]);

        entryText = malloc(strlen(firstWord) + strlen(argv[count]) + 4 * sizeof(char) + 1);

        strcat(entryText, argv[count]);

        free(entryText);
    }

    printf("\nfirstWord: %s\n", firstWord);
    printf("\nentryText: %s\n", entryText);
    printf("\n");

//    printf("Общее кол-во аргументов: %d\n", count - 1);

	switch (argc) {
		case 1:
			// noto
			show_all();
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
						show_entry(argv[1]);
						exit(1);
					} else { // New entry
						create_entry(argv[1]);
						exit(1);
					}
				}
			}
		case 3:
			// noto -r @abcdef
			if (strcmp(argv[1], "-r") == 0) { // Has -r flag
				if (argv[2][0] == '@') {
					// Search and remove the entry
                    remove_entry(argv[2]);
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
