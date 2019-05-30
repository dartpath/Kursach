main: bin/main

build/main.o: src/main.c 
		gcc -std=c99 -Wall -Werror -o build/main.o -c src/main.c

build/text.o: src/text.c
		gcc -std=c99 -Wall -Werror -o build/text.o -c src/text.c

build/filesize.o: src/filesize.c
		gcc -std=c99 -Wall -Werror -o build/filesize.o -c src/filesize.c

build/readfile.o: src/readfile.c
		gcc -std=c99 -Wall -Werror -o build/readfile.o -c src/readfile.c

build/procword.o: src/procword.c
		gcc -std=c99 -Wall -Werror -o build/procword.o -c src/procword.c		

bin/main: build/main.o build/text.o build/filesize.o build/readfile.o build/procword.o
		gcc build/main.o build/text.o build/filesize.o  build/readfile.o build/procword.o -o bin/main

.PHONY : clean

bin:
	mkdir bin

build:
	mkdir build

clean:
	rm -rf build/*.o