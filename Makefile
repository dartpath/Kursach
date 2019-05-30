main: bin/main

build/main.o: src/main.c 
		gcc -std=c99 -Wall -Werror -o build/main.o -c src/main.c

build/alphsort.o: src/alphsort.c
		gcc -std=c99 -Wall -Werror -o build/alphsort.o -c src/alphsort.c

build/filesize.o: src/filesize.c
		gcc -std=c99 -Wall -Werror -o build/filesize.o -c src/filesize.c

build/readfile.o: src/readfile.c
		gcc -std=c99 -Wall -Werror -o build/readfile.o -c src/readfile.c

build/removepunct.o: src/removepunct.c
		gcc -std=c99 -Wall -Werror -o build/removepunct.o -c src/removepunct.c		

bin/main: build/main.o build/alphsort.o build/filesize.o build/readfile.o build/removepunct.o
		gcc build/main.o build/alphsort.o build/filesize.o  build/readfile.o build/removepunct.o -o bin/main

.PHONY : clean

bin:
	mkdir bin

build:
	mkdir build

clean:
	rm -rf build/*.o