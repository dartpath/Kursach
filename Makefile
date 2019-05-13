main: main

build/main.o: src/main.c build
		gcc -std=c99 -Wall -Werror -o build/main.o -c src/main.c

build/text.o: src/text.c
		gcc -std=c99 -Wall -Werror -o build/text.o -c src/text.c

main: build/main.o build/text.o 
		gcc build/main.o build/text.o -o main

.PHONY : clean

build:
	mkdir build

clean:
	rm -rf build/*.o
