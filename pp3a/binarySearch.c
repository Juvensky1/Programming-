/* File: binarySearch.c
 * Author: hamza awad ,ahmed ghazi, juvensky hyppolite - jean.
 * Description: example of linear, binary search algorithm iterative and
 *    recursive versions
 */
#include <stdio.h>
#include <math.h>
#include "binarySearch.h"

/* linearSearch linearly searches for key and returns index where found or -1
 * Parameters
 *    a array to search
 *    n number elements in array
 *    k key to find
 *    iPtr number of iterations made
 *    cPtr number of comparisons made
 * Precondition: *iPtr and cPtr have been initialized to 0
 * Postcondition: *iPtr contain number of iterations for the search
 *    and cPtr number of comparisons
 * Returns: index where key found or -1
 */
int linearSearch( double a[], int n, double k, int *iPtr, int *cPtr ) {
       int i;
       for(i=0; i<n; i++){
          ++(*iPtr);
          if(++(*cPtr)&&a[i]==k){
               return i;
          }
     }
     return(-1);

}

/* iterativeBSearch uses an iterative binary search to find key and
 *    returns index where found or -1
 * Parameters
 *    a array to search
 *    n number elements in array
 *    k key to find
 *    iPtr pointer to number of iterations made
 *    cPtr pointer to number of comparisons made
 * Precondition: * iPtr and *cPtr has been initialized   
 * to 0
 * Postcondition: *cPtr contain number of comparisons 
 * for the search
 *    and iPtr the number of iterations
*/
int iterativeBSearch( double a[], int n, double k, int *iPtr, int *cPtr ) {
      int middleIndex;
      int bottom=0;
      int top=n-1;
      while(bottom<=top){
         ++(*iPtr);
           middleIndex=(bottom+top)/2;
           if(++(*cPtr)&&k==a[middleIndex]){
              return middleIndex;
           }
     else if(++(*cPtr)&&k<a[middleIndex]){
            top=middleIndex-1;
     }
     else{
         bottom=middleIndex+1;
     }
   }
 return -1;
}

/* recursiveBSearch uses a recursive binary search to find key and
 *    returns index where found or -1
*/
int recursiveBSearch( double a[], int b, int t,  double k, int *iPtr, int *cPtr )  {
     ++(*iPtr);
     int middleIndex=(b+t)/2;
     if(++(*cPtr)&&k==a[middleIndex]){
        return middleIndex;

     }
     else if(++(*cPtr)&& b>t){
        return -1;
    }
    else if(++(*cPtr)&&k<a[middleIndex]){
        t=middleIndex-1;
        return recursiveBSearch(a,b,t,k,iPtr,cPtr);
    }
   else{
       b=middleIndex+1;
       return recursiveBSearch(a,b,t,k,iPtr,cPtr);

  }
}

