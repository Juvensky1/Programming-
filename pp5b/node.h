/*
* File: node.h
* Authors: Chris Ramos and Juvensky Hyppolite
* Description: Contains function headers for node.c
*/
#ifndef NODE_H
#define NODE_H

typedef struct node_t {
   int i;
   struct node_t* nextPtr;
   struct node_t* prevPtr;
} node_t;

node_t* initNode(int n ); 

#endif
