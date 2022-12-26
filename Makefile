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
