/* File: queue.h
 * Author: Juvensky Hyppolite - Jean
 * Description: header file for a queue
 */
#ifndef QUEUE_H
#define QUEUE_H
#include "queueItem.h"
#define MAX_QUEUE_SIZE 10
#define EMPTY_INDEX -1
typedef struct {
           QueueItem array[MAX_QUEUE_SIZE];
              int front; // index of front item in queue
              int rear; // index of rear item in queue
              int count; // number of items in queue
} Queue;
void initQueue( Queue* );
int enqueue( Queue*, QueueItem );
int dequeue( Queue*, QueueItem* );
int isEmpty( Queue );
void printQueue( Queue );
#endif
