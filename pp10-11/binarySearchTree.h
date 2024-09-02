#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "position.h"
#include "node.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::max ;

// declaration for friend statement below
template<class T> class Position; 
 
const int PREORDER = 1;
const int INORDER = 2;
const int POSTORDER = 3;
 
template<class T>
class BinarySearchTree {
public:
   BinarySearchTree();
   BinarySearchTree( const BinarySearchTree& );
   // returns num nodes in tree
   int size() const { return numNodes; } 
   // returns true if tree empty of real nodes
   bool empty() const { return numNodes == 0; } 
   // superroot right pointer always points to real root node
   Position<T> root() const { 
      return Position<T>( superRootPtr->rightPtr ); 
   } 
   void traverseAndPrint( const Position<T>& p, int type ) const;
   int depth( const Position<T>& ) const;
   int height( const Position<T>& ) const; 
   Position<T> begin() const;
   // returns NULL iterator
   Position<T> end() const { return Position<T>( ); } 
   Position<T> find( const T& ) const;
   Position<T> insert( const T& );
   bool erase( const T& );
   bool erase( const Position<T>& );
   virtual ~BinarySearchTree() { deleteUtility(superRootPtr); }
   friend class Position<T>;
private:
   Node<T>* superRootPtr;
   // number real nodes in tree, not including fake super 
   // root and fake ends nodes 
   int numNodes; 
   void preorderTraverseAndPrint( const Position<T>& ) const;
   void inorderTraverseAndPrint( const Position<T>& ) const;
   void postorderTraverseAndPrint( const Position<T>& ) const;
   // finds item in tree starting at position
   Position<T> findUtility( const T& item, const Position<T>& ) const;
   // inserts item into tree
   Position<T> insertUtility( const T& item );
   // deletes all nodes in the tree
   void deleteUtility( Node<T>* );
   // erases just one node from the tree at position p
   Position<T> eraseUtility( const Position<T>& p);
   // insert item data at position p
   void expandExternal( const T& item, Position<T>& p); 
   // remove node above fake leaf node at position p
   Position<T> removeAboveExternal( const Position<T>& p );
   Node<T>* copyTree(Node<T>* p, Node<T>* n);
    
};

/* depth returns distance from root to node at parameter
 * position
 * Parameter:
 *   p position to compute depth of
 * Returns depth or -1 if position p is superroot
*/
template<class T>
int BinarySearchTree<T>::depth( const Position<T>& p ) const {
   if ( p.isSuperRoot()) return -1;
   if ( p.isRoot()) return 0;
   else {
      return 1+depth( p.parent() );
   }
}

/* height returns distance from node at parameter position to
 * lowest leaf
 * Parameter: position to computer height of
*/
template<class T>
int BinarySearchTree<T>::height( const Position<T>& p ) const {
   // if leaf
   if ( p.isExternal() ) return 0;
   int h = 0;
   // h = max of 0 and height of left subtree
   h= max( h, height( Position<T>( p.nodePtr->leftPtr ))); 
   // h = max of height of left subtree and 
   // height of right subtree
   h = max( h, height( Position<T>( p.nodePtr->rightPtr )));
   return 1 + h; 
}

/* begin: returns position iterator to first node on tree - the leftmost
 */
template<class T>
Position<T> BinarySearchTree<T>::begin() const {
   if ( numNodes > 0 ) {
      Position<T> p = root();
      while (p.isInternal()) {
         p = p.left();
      }
      return p.parent();
   }
   else return Position<T>( superRootPtr );
}

/* finds a T object in tree
 * Parameters: the object to find
 * Pre-condition: class T has overloaded operator==
 * Returns iterator to object, superroot iterator if tree
 *   is empty, fake leaf postion if not found
 */
template<class T>
Position<T> BinarySearchTree<T>::find( const T& item ) const {
   if ( numNodes > 0 ) {
      Position<T> v = findUtility( item, root());
      return v;
   }
   else return Position<T>(superRootPtr);
}

/* inserts object T in the binary tree
 * Parameter: the object to insert
 * Pre-condition: class T has overloaded operator<
 * Returns iterator to newly inserted object or superRootPtr
 *    if item already in tree
 */
template<class T>
Position<T> BinarySearchTree<T>::insert( const T& item ) {
   // root() = superroot's right ptr 

   Position<T> p = insertUtility( item ); 
   // return iterator to position where new node inserted
   return p; 
}

/* erase removes a node above Position p
 * Precondition position p is a valid position in tree
 * Returns true if successful
 */
template<class T>
bool BinarySearchTree<T>::erase( const T& item ) {
   // can't remove superroot or fake external node
   Position<T> p = find(item);
   if ( !p.isSuperRoot() && !p.isExternal() ) { 
      eraseUtility( p);
      return true;
   }
   else
      return false;
}

template<class T>
bool BinarySearchTree<T>::erase( const Position<T>& p ) {
   // can't remove superroot or fake external node
   if ( !p.isSuperRoot() && !p.isExternal() ) { 
      eraseUtility( p );
      return true;
   }
   else
      return false;
}

template<class T>
Position<T> BinarySearchTree<T>::eraseUtility( const Position<T>& p){
	Position<T> w;
	Position<T> u;
	if(p.left().isExternal()){
		w = p.left();
	}
	else if(p.right().isExternal()){
		w=p.right();
	}
	else{
		w = p.right();
		do{
			w=w.left();
		
	    }while(w.isInternal());
		u = w.parent();
		p.nodePtr->item = u.nodePtr->item;
	
   }
	return removeAboveExternal(w);
}
	
	
	
template<class T>
Position<T> BinarySearchTree<T>::findUtility(const T& item, const Position<T>& p) const{
	if(p.isExternal()) return p;
	if( p.nodePtr->item == item) return p;
	if( item < p.nodePtr->item){
		return findUtility(item, p.left());
	}
	
	else{
		return findUtility(item, p.right());
   }
}

template<class T>
Position<T> BinarySearchTree<T>::insertUtility(const T& item){
	Position<T> foundPosition = findUtility(item , root());
	if(foundPosition.isExternal()){
		 expandExternal(item, foundPosition);
		return foundPosition ;
	}
	else{
		return Position<T>(superRootPtr);
	}
}

/* default ctor sets up an empty tree with two nodes: 
 * fake root whose right ptr points to fake end
 */
 template<class T>
BinarySearchTree<T>::BinarySearchTree() {
            superRootPtr = new Node<T>();
            superRootPtr->rightPtr = new Node<T>();
            superRootPtr->rightPtr->parentPtr = superRootPtr;
            superRootPtr->leftPtr = NULL;
            numNodes = 0;
}

template<class T>
void BinarySearchTree<T>::deleteUtility(Node<T>* nodePtr){
   if (nodePtr != NULL){ 
	   deleteUtility( nodePtr->leftPtr);
	   deleteUtility( nodePtr->rightPtr);
	   delete nodePtr;
   }
}

template<class T>
BinarySearchTree<T>::BinarySearchTree( const BinarySearchTree& b ){
	numNodes = b.numNodes;
	superRootPtr = new Node<T>();
	if( b.superRootPtr->rightPtr == NULL){
		superRootPtr->rightPtr = new Node<T>();
		superRootPtr->rightPtr->parentPtr = superRootPtr;
   }
    else{
    	superRootPtr->rightPtr = copyTree( superRootPtr, b.superRootPtr->rightPtr);
	}
}

template<class T>
Position<T> BinarySearchTree<T>::removeAboveExternal( const Position<T>& p){
	Node<T>* w = p.nodePtr;
	Node<T>* v = w->parentPtr;
   Node<T>* siblingPtr; 
   Node<T>* grandParentPtr;

	if(w == v->leftPtr){
		siblingPtr = v->rightPtr;
   }
   else{
   	siblingPtr = v->leftPtr;
   }
   if( v== superRootPtr->rightPtr){
   		superRootPtr->rightPtr = siblingPtr;
   		siblingPtr->parentPtr = superRootPtr;
   }
   else{
     	grandParentPtr = v->parentPtr;
    	if(grandParentPtr->leftPtr == v){
    		grandParentPtr->leftPtr = siblingPtr;
    	}
    	else{
    		grandParentPtr->rightPtr = siblingPtr;
      }
      siblingPtr->parentPtr = grandParentPtr;
   	}
   	delete w;
   	delete v;
   	numNodes--;
   	return Position<T>(siblingPtr); 

}

template<class T>
Node<T>* BinarySearchTree<T>::copyTree(Node<T>* p, Node<T>* n){
	if(n != NULL){
		Node<T>* newNode = new Node<T>(*n);
		newNode->parentPtr = p;
		newNode->leftPtr = copyTree(newNode, n->leftPtr);
		newNode->rightPtr = copyTree(newNode, n->rightPtr);
		return newNode;
	}
	else return NULL;
}

template <class T>
void BinarySearchTree<T>::expandExternal(const T& item, Position<T>& p) {

     Node<T>* left = new Node<T>();
     Node<T>* right = new Node<T>();
	p.nodePtr->leftPtr = left;
   p.nodePtr->rightPtr = right;
   left->parentPtr = p.nodePtr;
   right->parentPtr = p.nodePtr;
   p.nodePtr->item = item;
   numNodes++;

}



template <class T>
void BinarySearchTree<T>::preorderTraverseAndPrint(const Position<T>& p ) const {
    if (p.nodePtr != NULL && p.nodePtr->item != 0) {
        cout << p.nodePtr->item << " ";
        preorderTraverseAndPrint(p.nodePtr->leftPtr);
        preorderTraverseAndPrint(p.nodePtr->rightPtr);
    }
}


template<class T>
void BinarySearchTree<T>::inorderTraverseAndPrint(const Position<T>& p) const {
    if (p.nodePtr != NULL && p.nodePtr->item != 0) {
        inorderTraverseAndPrint(p.nodePtr->leftPtr);
        cout << p.nodePtr->item << " ";
        inorderTraverseAndPrint(p.nodePtr->rightPtr);
    }
}


template<class T>
void BinarySearchTree<T>::postorderTraverseAndPrint(const Position<T>& p) const {
    if (p.nodePtr != NULL && p.nodePtr->item != 0) {
        postorderTraverseAndPrint(p.nodePtr->leftPtr);
        postorderTraverseAndPrint(p.nodePtr->rightPtr);
        cout << p.nodePtr->item << " ";
    }
}

template<class T>
void BinarySearchTree<T>::traverseAndPrint(const Position<T>& p, int type) const{
	switch(type){
		case PREORDER:
			preorderTraverseAndPrint(p);
			break;
		case INORDER:
			inorderTraverseAndPrint(p);
			break;
		case POSTORDER:
			postorderTraverseAndPrint(p);
			break;
	}
}
#endif