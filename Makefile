.PHONY : clean bin main test

CC := gcc
CFLAGS := -Wall -Werror
BUILD_SRC := ./build/src
BUILD_TEST := ./build/test
MAIN := ./bin/alphabet
TEST := ./bin/test

main: $(MAIN)

$(MAIN): $(BUILD_SRC)/main.o $(BUILD_SRC)/alphsort.o $(BUILD_SRC)/filesize.o $(BUILD_SRC)/readfile.o $(BUILD_SRC)/removepunct.o
		$(CC) $(BUILD_SRC)/main.o $(BUILD_SRC)/alphsort.o $(BUILD_SRC)/filesize.o  $(BUILD_SRC)/readfile.o $(BUILD_SRC)/removepunct.o -o $(MAIN)

$(BUILD_SRC)/main.o: src/main.c 
		$(CC) -std=c99 $(CFLAGS) -o $(BUILD_SRC)/main.o -c src/main.c

$(BUILD_SRC)/alphsort.o: src/alphsort.c src/alphsort.h
		$(CC) -std=c99 $(CFLAGS) -o $(BUILD_SRC)/alphsort.o -c src/alphsort.c

$(BUILD_SRC)/filesize.o: src/filesize.c src/filesize.h
		$(CC) -std=c99 $(CFLAGS) -o $(BUILD_SRC)/filesize.o -c src/filesize.c

$(BUILD_SRC)/readfile.o: src/readfile.c src/readfile.h
		$(CC) -std=c99 $(CFLAGS) -o $(BUILD_SRC)/readfile.o -c src/readfile.c

$(BUILD_SRC)/removepunct.o: src/removepunct.c src/removepunct.h
		$(CC) -std=c99 $(CFLAGS) -o $(BUILD_SRC)/removepunct.o -c src/removepunct.c	

test: $(TEST)

$(TEST): $(BUILD_TEST)/main.o $(BUILD_TEST)/alphsort.o $(BUILD_TEST)/filesize.o $(BUILD_TEST)/readfile.o $(BUILD_TEST)/removepunct.o
		$(CC) $(CFLAGS) $(BUILD_TEST)/main.o $(BUILD_TEST)/alphsort.o $(BUILD_TEST)/filesize.o $(BUILD_TEST)/readfile.o $(BUILD_TEST)/removepunct.o	-o $(TEST)

$(BUILD_TEST)/main.o: test/main.c build
		$(CC) $(CFLAGS) -c test/main.c -o $(BUILD_TEST)/main.o

$(BUILD_TEST)/alphsort.o: src/alphsort.c src/alphsort.h
		$(CC) $(CFLAGS) -c src/alphsort.c -o $(BUILD_TEST)/alphsort.o

$(BUILD_TEST)/filesize.o: src/filesize.c src/filesize.h
		$(CC) $(CFLAGS) -c src/filesize.c -o $(BUILD_TEST)/filesize.o

$(BUILD_TEST)/readfile.o: src/readfile.c src/readfile.h
		$(CC) $(CFLAGS) -c src/readfile.c -o $(BUILD_TEST)/readfile.o

$(BUILD_TEST)/removepunct.o: src/removepunct.c src/removepunct.h
		$(CC) $(CFLAGS) -c src/removepunct.c -o $(BUILD_TEST)/removepunct.o

bin:
	mkdir bin
	
build:
	mkdir

clean:
	rm -rf build/src/*.o
	rm -rf build/test/*o