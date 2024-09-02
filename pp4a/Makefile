all: myprogram
 
myprogram: mainQueue.o queue.o
	gcc mainQueue.c queue.c -o queueExe
 
mainQueue: mainQueue.c queue.c queue.h queueItem.h
	gcc -c mainQueue.c
 
queue: queue.c queue.h  queueItem.h
	gcc -c queue.c
 
clean:
	rm -rf *.o *.gch queueExe

