

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "iterator.h"
#include "node.h"
using namespace std;
template<typename T>
class LinkedList {
public:
   /* Default ctor creates an empty list with empty head and
      tail nodes
    */
   LinkedList();
   /* Copy constructor does deep copy of parameter list
    */
   LinkedList( const LinkedList<T>& );
   /* size returns the size of the list
    */
   int size() const { return n; }
   /* empty returns true if the list is empty
    */
   bool empty() const { return n == 0; }
   /* begin returns an iterator to the first element 
      in the list or the tail sentinel node if the list 
      is empty
    */
   Iterator<T> begin() const { 
      return Iterator<T>( headPtr->nextPtr ); }
   /* end returns an iterator to the last element in the list 
      or the tail sentinel node if the list is empty
    */
   Iterator<T> end() const { return Iterator<T>( tailPtr ); }
   /* insert inserts parameter node just before iterator
      parameter position
    * Pre-condition: node type T has copy constructor
    */
   void insert( const Iterator<T>&, const Node<T>& );
   /* insertFront inserts node at beginning of list
    * Pre-condition: node type T has copy constructor
    */
   void insertFront( const Node<T>& );
   /* insertBack inserts parameter node at the end of the list
    * Pre-condition: node type T has copy constructor
    */
   void insertBack( const Node<T>& );
    /* erase removes node from list referred to by iterator
       parameter
    */
   void erase( const Iterator<T>& );
   /* eraseFront removes the first node in the list 
     (not headPtr) if list isn’t empty
   */
   void eraseFront() { erase( begin() ); }
   /* eraseBack removes node from end of list if list is 
      not empty (not tailPtr)
    */
   void eraseBack() { erase( --end()); }
   /* traverseAndPrint traverses entire list and prints node
      items to display.
    * Precondidtion: class T has overloaded <<
    */
   void traverseAndPrint() const;
   /* LinkedList destructor deallocates all nodes including 
      head and tail sentinels
    */
   virtual ~LinkedList() { eraseList(); }
   /* operator= erases current list then deep copies list
      parameter to this list
    * Pre-condition: class T has overloaded copy constructor
    * Returns reference to this list
    */
   LinkedList<T>& operator=( const LinkedList<T>& );
private:
   /* eraseList deallocates all nodes including head and tail
      sentinels. Used by destructor, operator= and copy ctor
    */
   void eraseList(); 
   Node<T>* headPtr;
   Node<T>* tailPtr;
   // n=num nodes in list not counting sentinel head and tail
   int n; 
};

/* traverseAndPrint traverses entire list and prints node 
   items to display.
 * Precondition: class T has overloaded <<
 */
template<typename T>
void LinkedList<T>::traverseAndPrint() const {
     Iterator<T> it( begin() );
     for( ; it != end(); ++it ) {
          cout << it.curPtr->item << endl;
     }
}

template<class T>
void LinkedList<T>::insert( const Iterator<T>& it, const Node<T>& node ) {
     Node<T>* next = it.curPtr; // node after new node
     // node before new node
     Node<T>* prev = it.curPtr->prevPtr; 

     Node<T>* newNode = new Node<T>(node);
     newNode->nextPtr = next;
     newNode->prevPtr = prev;
     prev->nextPtr = newNode;
     next->prevPtr = newNode;
     n++;
}

template<class T>
void LinkedList<T>::insertFront(const Node<T>& n ) {
     insert( begin(), n );
}

template<class T>
void LinkedList<T>::insertBack(const Node<T>& n){
	  insert( end(), n);
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=( const LinkedList<T>& l ) {
   // thisPtr goes through this' list, curPtr goes thru l's
   Node<T>* thisPtr, *nodePtr;
 
   // first, delete original list so no memory  leak
   eraseList();
   
   // get head of new list then copy l to this
   headPtr = new Node<T>;
   thisPtr = headPtr;
   Iterator<T> it = l.begin();
   while( it != l.end() ) {
        nodePtr = new Node<T>( *(it.curPtr) );
        nodePtr->prevPtr = thisPtr;
        thisPtr->nextPtr = nodePtr;
        thisPtr = nodePtr;
        ++it;
   }
   // finally, get tail node of new list
   tailPtr = new Node<T>();
   tailPtr->prevPtr = thisPtr;
   thisPtr->nextPtr = tailPtr; 
   n = l.n;         // set this lists' size
   return *this;
}
/*
* Function: eraseList
* Description: erases entire list by deallocating all memory for all nodes
* Parameters:
        none
* Returns: Nothing
*/
template<class T>
void LinkedList<T>:: eraseList( ){
   Node<T>* curPtr = headPtr;
   while(curPtr != NULL){
   	    Node<T>* nextPtr = curPtr->nextPtr;
   	    delete curPtr;
   	    curPtr = nextPtr;
   }
   headPtr = NULL;
   tailPtr = NULL;
   }

/* LinkedList: copy constructor does a deep copy
 * Parameters
 * l the list to copy from
 */
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& l ) {
 
// thisPtr goes through this' list, curPtr goes thru l's
   Node<T>* thisPtr, *nodePtr;
 
   
   // get head of new list then copy l to this
   headPtr = new Node<T>;
   thisPtr = headPtr;
   Iterator<T> it = l.begin();
   while( it != l.end() ) {
        nodePtr = new Node<T>( *(it.curPtr) );
        nodePtr->prevPtr = thisPtr;
        thisPtr->nextPtr = nodePtr;
        thisPtr = nodePtr;
        ++it;
   }
   // finally, get tail node of new list
   tailPtr = new Node<T>();
   tailPtr->prevPtr = thisPtr;
   thisPtr->nextPtr = tailPtr; 
   n = l.n;         // set this lists' size
}

template<class T>
LinkedList<T>::LinkedList(){
	headPtr = new Node<T>();
	tailPtr = new Node<T>();
	headPtr->nextPtr = tailPtr;
	tailPtr->prevPtr = headPtr;
	n = 0;
}

template<class T>
void LinkedList<T>::erase( const Iterator<T>& it){
	Node<T>* prev = it.curPtr->prevPtr; // node after new node
     // node before new node
     Node<T>* next = it.curPtr->nextPtr; 

     prev->nextPtr= next;
     next->prevPtr = prev;
     delete(it.curPtr);
     n--;
}
#endif
