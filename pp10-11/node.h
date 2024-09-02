#ifndef NODE_H
#define NODE_H

template<class T> class BinarySearchTree; // declaration for friend statement below
template<class T> class Position; // declaration for friend statement below
 
template<class T>
class Node {
public:
   Node(); // default constuctor
   // constructor that takes node’s dat
   Node( const T& ); 
   // copy constructor. 
   Node( const Node<T>& );  
   virtual ~Node<T>() {} // destructor
   void setItem( const T& ); 
   T getItem() const { return item; } 
   Node<T>& operator=( const Node<T>& );
   friend class BinarySearchTree<T>;
   friend class Position<T>; // Position is an iterator class
private:
   Node<T>* leftPtr;
   Node<T>* rightPtr;
   Node<T>* parentPtr;
   T item;
};

template<class T>
Node<T>::Node(){
	leftPtr = rightPtr = parentPtr = NULL;
}

template<class T>
 Node<T>::Node(const Node<T>& n){
	leftPtr = rightPtr = parentPtr = NULL;
	item = n.item;
}

template<class T>
Node<T>& Node<T>::operator=(const Node<T>& n ){
	if(this != &n){
	
		leftPtr = n.leftPtr;
		rightPtr = n.rightPtr;
		parentPtr = n.parentPtr;
    }
	return this;
	
}

template<class T>
Node<T>::Node(const T& data){
	item = data;
	rightPtr = leftPtr = parentPtr = NULL;
}

/* setItem sets the item data values in the node
   Parameter
      i the item
   Pre-condition: T has defined operator=
   Returns: nothing
*/
template<class T>
void Node<T>::setItem( const T& i ) {
   item = i;
}

#endif