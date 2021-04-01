#include "main.h"

// Необходимые функции:
// Запуск логики удаления записи
// Запуск логики показа помощи
// Запуск логики полной очистки
// Запуск логики создания записи (нужна проверка хэша на коллизию)

/*
 * 1. Если argc === 1 - выводим список всех записей
 * 2. Если argc > 1, то:
 * Если argv[1] === '--prune':
 *  : 1. Предупреждаем, что все записи будут удалены и спрашиваем точно ли юзер этого хочет (y/N:)
 *  : 2.1. Если y - удаляем файл с базой записей
 *  : 2.2. Если N - return 0;
 *
 * Если argv[1] === '-h' || argv[1] === '--help':
 *  : 1. Выводим подсказку с помощью и основными командами
 *
 * Если argv[1] начинается с '@':
 *
 * // TODO: Подумать насчёт возможной формы записи `noto -r @abc123 @abc456 @abc789` для удаления нескольких записей
 * Если argv[1] === '-r':
 *  : 1. Если argc === 2 - вывести ошибку, что нужен хэш удаляемой записи
 *  : 1.1. Если argc === 3 - проверить начинается ли argv[2] на '@':
 *      1.1.1. Если да и длина в порядке - пытаемся удалить запись с этим хэшем.
 *      1.1.2. Если нет - выводим ошибку, что не удалось удалить запись с указанным хэшем
 *
 *
 * Если ничего из условий выше:
 *  : 1. Запускаем создание записи для всех принятых аргументов
 * */

int main(int argc, char *argv[]) {
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
