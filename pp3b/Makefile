all: myprogram
 
myprogram: mainStack.o stack.o
	gcc mainStack.c stack.c -o exampleExe
 
mainStack: mainStack.c stack.c stack.h stackItem.h
	gcc -c mainStack.c
 
stack: stack.c stack.h  stackItem.h
	gcc -c stack.c
 
clean:
	rm -rf *.o *.gch exampleExe

