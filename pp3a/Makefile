all: myprogram
myprogram: mainSearch.o binarySearch.o
	gcc mainSearch.c binarySearch.c -o exampleExe
main: mainSearch.c binarySearch.h
	gcc -c main.c
example: binarySearch.c binarySearch.h
	gcc -c binarySearch.c
clean:
	rm -rf *.o *.gch exampleExe

