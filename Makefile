CC = clang
CFLAGS = -Iinclude -Wall -O2 -std=c17

SRC_FILES = $(wildcard src/*.c)
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
