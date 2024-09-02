//* File: queue.c
 * Author: Juvensky hyppolite - jean
 * Description: contains functions for queue manipulations
 */
#include <stdio.h>
#include "queue.h"
#include "queueItem.h"
/* initQueue: initializes queue by setting front and count to zero
 * and rear to MAX_QUEUE_SIZE - 1
 * Parameter q  pointer to the queue
 * Returns nothing
 */
// ADD CODE HERE
void initQueue(Queue* q){
	q -> rear = MAX_QUEUE_SIZE - 1;
        q -> front = 0;
        q -> count = 0;
}
/* enqueue: adds an item on the queue if it isn't full
 * Parameters:
 *    q pointer to the queue
 *    num the item to be enqueued
 * Returns true if queue successful, false otherwise 
 */
// ADD CODE HERE
int enqueue(Queue *q, QueueItem  num){
	if(q -> count < MAX_QUEUE_SIZE){ // queue is not full
		
		q -> count++;
                q -> rear = (q -> rear + 1 ) % MAX_QUEUE_SIZE;
                q -> array[ q -> rear] = num;
		return 1;
	}
	return 0;
}
/* dequeue: removes an item off the queue if it isn't empty
 * Parameters 
 *    q pointer to the stack
 *    num the item to be removed, a pointer
 * Postcondition: num will have the item dequeued if the stack wasn't empty
 * Returns true if an item was dequeued 
 */
// ADD CODE HERE
int dequeue(Queue* q, QueueItem* num){
	if(q -> count > 0 ){
                
		q -> count--;
		*num = q ->array[ q -> front];
                q -> front = (q ->  front + 1) % MAX_QUEUE_SIZE;
                return 1;
        }
        return 0;
}
/* isEmpty: returns true if queue is empty
 * Parameter q the queue
 * Returns: true if queue is empty
 */
// ADD CODE HERE
int isEmpty(Queue q){
	if(q.count == 0){
		return 1;
	}else{
		return 0;
	}
}
/* printQueue: prints the queue
 * Parameter q the queue
 * Returns nothing
 */
void printQueue( Queue q ) {
   int i;
   printf("QUEUE\n");
   if ( q.count > 0 ) {
      for( i = q.front; i != q.rear; i = (i+1) % MAX_QUEUE_SIZE ) {
         printf ("| %4d ", q.array[i] );
      }
   }
   if ( q.count > 0 )
      printf ("| %4d |\n", q.array[q.rear] );
   else
      printf( "| |\n" );
}

