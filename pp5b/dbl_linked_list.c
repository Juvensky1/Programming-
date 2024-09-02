s:/*
* File: dbl_linked_list.c
* Author: Chris Ramos and Juvensky Hyppolite
* Description: Contains all function definitions declared in dbl_linked_list.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "dbl_linked_list.h"

/*
* Function: createList
* Description: creates an empty doubly linked list
* Parameters:
	listPtr: a pointer to the double linked list structure
* Returns: Nothing 
*/
void createList( dbl_linked_list_t* listPtr ){
   if( listPtr != NULL ){	//if list exists
	listPtr -> headPtr = NULL; //makes list empty
	listPtr -> tailPtr = NULL;
	listPtr -> count = 0;
   } 
}

/*
* Function: insertNode
* Description: Inserts node at the head of the list
* Parameters:
        listPtr: a pointer to the double linked list structure
	nPtr: Pointer to the node structure
* Returns: Nothing
*/
void insertNode( dbl_linked_list_t* listPtr, node_t* nPtr ){
   if( listPtr != NULL ){	  //Checks if list exists
	listPtr -> count++;
   	if( listPtr -> headPtr == NULL ){ 	 //Checks if list is empty
	   listPtr -> headPtr = nPtr;		 
	   listPtr -> tailPtr = nPtr;
   	}
	else{					//list already has nodes in it
	   nPtr -> nextPtr = listPtr -> headPtr;
	   listPtr -> headPtr -> prevPtr = nPtr;
	   listPtr -> headPtr = nPtr;
	}
   }
}

/*
* Function: popNode
* Description: pops the last node inserted from the head of the list
* Parameters:
        listPtr: a pointer to the double linked list structure
* Returns: 
	nPtr: The last node inserted in the list if list exists and is not empty
	NULL: if list does not exist
*/
node_t* popNode( dbl_linked_list_t* listPtr ){
   if (listPtr != NULL && listPtr -> headPtr != NULL ){	//list exists and is not empty
	listPtr -> count--;
	node_t* nPtr;
	nPtr = listPtr -> headPtr;		//return value
	listPtr -> headPtr = nPtr -> nextPtr;	//sets new head
	if( listPtr -> headPtr != NULL ){	//after popping checks if list is still not empty
	   listPtr -> headPtr -> prevPtr = NULL;
	}
	else{
	   listPtr -> tailPtr = NULL;
	}
	nPtr -> prevPtr = NULL;
	nPtr -> nextPtr = NULL;
	return( nPtr );
   }
   else{
	return( NULL );
   }
}

/*
* Function: dequeueNode
* Description: dequeues the first node inserted from the head of the list
* Parameters:
        listPtr: a pointer to the double linked list structure
* Returns:
	nPtr: The first node inserted if list exists and is not empty
	NULL: if list does not exist
*/
node_t* dequeueNode( dbl_linked_list_t* listPtr ){
   if (listPtr != NULL && listPtr -> tailPtr != NULL ){
        listPtr -> count--;
        node_t* nPtr;
        nPtr = listPtr -> tailPtr;		//return value
        listPtr -> tailPtr = nPtr -> prevPtr;
        if( listPtr -> tailPtr != NULL ){	//checks to make sure list still has values
           listPtr -> tailPtr -> nextPtr = NULL;
        }
        else{
           listPtr -> headPtr = NULL;
        }
        nPtr -> prevPtr = NULL;
        nPtr -> nextPtr = NULL;                 
        return( nPtr );
   }
   else{
        return( NULL );
   }
}

/*
* Function: deleteList
* Description: deletes entire list by deallocating all memory for all nodes
* Parameters:
        listPtr: a pointer to the double linked list structure
* Returns: Nothing
*/
void deleteList( dbl_linked_list_t* listPtr ){
   if( listPtr != NULL && listPtr -> headPtr != NULL ){
	node_t* curPtr;
	curPtr = listPtr -> headPtr;
	while( curPtr != NULL ){		//deallocates memory in nodes
	   listPtr -> headPtr = curPtr -> nextPtr;
	   free( curPtr );
	   curPtr = listPtr -> headPtr;
	}
	listPtr -> tailPtr = NULL;
	listPtr -> count = 0;
   }
}

/*
* Function: traverseStack
* Description: traverses and prints data from head to tail
* Parameters:
        listPtr: a pointer to the double linked list structure
* Returns: Nothing
*/
void traverseStack( const dbl_linked_list_t* listPtr ){
   if( listPtr != NULL ){
	node_t* curPtr;
	curPtr = listPtr -> headPtr;
	while( curPtr != NULL ){	//prints all values in list until last value
	   printf( "%d " , curPtr -> i );
	   curPtr = curPtr -> nextPtr;
	}
   }
}

/*
* Function: traverseQueue
* Description: traverses and prints data from tail to head
* Parameters:
        listPtr: a pointer to the double linked list structure
* Returns: Nothing
*/
void traverseQueue( const dbl_linked_list_t* listPtr ){
   if( listPtr != NULL ){
	node_t* curPtr;
	curPtr = listPtr -> tailPtr;
	while( curPtr != NULL ){	prints all value in list in reverse order
	   printf( "%d ", curPtr -> i );
	   curPtr = curPtr -> prevPtr;
	}
   }
}
