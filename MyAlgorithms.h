#ifndef MYALGORITHMS_H
#define MYALGORITHMS_H




/* mySwap: template function that swaps the actual values of it parameters
    Parameters: two items to swap
   Pre-condition: type T has operator= defined
   Returns: nothing
*/
template<class T>
void mySwap( T& item1, T& item2 ) {
   T temp;
   temp = item1;
   item1 = item2; 
   item2 = temp;
}

template<class T>
void mySort(T a[], int n) // sorts the array vaules from smallest to largest 
{
int iMin;
T temp;
int i, top;
int nMinus1 = n - 1;
  for(top=0; top < nMinus1; top++) // keeps loop going until the end of Big5Assessment
  {  
   iMin=top ;
      for(i=top+1;i<n;i++)
      {
        if(a[i] < a[iMin]){ // checks if the vaule at j is smaller than iMin
        iMin=i;
        }
      }
   mySwap( a[iMin], a[top]);
  }
}

template<class T>
int mySearch( T a[], int n, T key)
{
	int i;
  for(i = 0; i<n; i++){
  	if (a[i] == key){
	return i;
    }	
  }
  return -1;
}


template<class T>
T myMin (const T &item1, const T &item2)
{
	if(item1 < item2){
	return item1;
    }
    return item2;
}

#endif