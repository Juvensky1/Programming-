all: myprogram
 
myprogram: main.o example.o
	gcc main.c example.c -o exampleExe
 
main: main.c example.h
	gcc -c main.c
 
example: example.c example.h
	gcc -c example.c
 
clean:
	rm -rf *.o *.gch exampleExe


