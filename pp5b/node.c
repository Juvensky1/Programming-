/*
* File: node.c
* Authors: Chris Ramos, Juvensky Hyppolite
* Contains all node funtion definitions declared in node.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

node_t* initNode(int n ){
   node_t* nPtr;
   nPtr = (node_t*) malloc(sizeof(node_t)); //dynamically allocates memory in nodes
   nPtr->i = n;
   nPtr -> nextPtr = NULL;
   nPtr -> prevPtr = NULL;
   return (nPtr);
}
