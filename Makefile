CC = clang
CFLAGS = -Iinclude -Wall -O2 -std=c17

SRC_FILES = $(wildcard src/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

TEST_SRC_FILES = $(wildcard tests/*.c)
TEST_OBJ_FILES = $(TEST_SRC_FILES:.c=.o)
TEST_EXEC = tests/test_noto

all: noto

noto: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o noto $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f noto $(OBJ_FILES) $(TEST_OBJ_FILES)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJ_FILES) $(filter-out src/main.o src/noto.o, $(OBJ_FILES))
	$(CC) $(CFLAGS) -o $(TEST_EXEC) $(TEST_OBJ_FILES) $(filter-out src/main.o src/noto.o, $(OBJ_FILES)) -lcunit

.PHONY: clean_tests
clean_tests:
	rm -f $(TEST_OBJ_FILES) $(TEST_EXEC)
