main: main

build/main.o: src/main.c build
		gcc -std=c99 -Wall -Werror -o build/main.o -c src/main.c

build/filesize.o: src/filesize.c
		gcc -std=c99 -Wall -Werror -o build/filesize.o -c src/filesize.c

main: build/main.o build/filesize.o 
		gcc build/main.o build/filesize.o -o main

.PHONY : clean

build:
	mkdir build

clean:
	rm -rf build/*.o
