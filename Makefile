CC = clang
CFLAGS = -Iinclude -Wall -O2 -std=c17

SRC_FILES = src/noto.c src/noto_create_entry.c src/noto_create_new_db.c src/noto_delete_line.c src/noto_generate_hash.c src/noto_get_path_to_db.c src/noto_remove_entry.c src/noto_show_all.c src/noto_show_entry.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: noto

noto: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o noto $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f noto $(OBJ_FILES)

# TARGET = noto

# all: $(TARGET)

# $(TARGET): $(TARGET).c
# 	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

# noto: noto.o
# 	$(CC) $(CFLAGS) -o noto noto.o

# noto.o: noto.c
# 	$(CC) $(CFLAGS) -o noto.c

# clean:
# 	rm -f noto noto.o


# build:
# 	@echo "[+] Building..."
# 	@gcc -Wall noto.c functions.c -o noto
# 	@echo "[+] Done!"
