all: myprogram

myprogram: mainDblLinkedList.o node.o dbl_linked_list.o
	gcc mainDblLinkedList.c node.c dbl_linked_list.c -o mainExe

main: mainDblLinkedList.c node.h dbl_linked_list.h
	gcc -c mainDblLinkedList.c

node: node.c node.h
	gcc -c node.c

dbllinkedList: dblLinkedList.c node.h dbl_linked_list.h
	gcc -c dbl_linked_list.c

clean:
	rm -rf *.o *.gch mainExe
