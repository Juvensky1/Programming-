/*
file name: pp7e.cpp
Auhtors: Wilson and Jean
This programs gets a key and then checks the array for it
*/
#include <iostream>
using namespace std; 
const int NOT_FOUND = -1;
const int N = 8;
int linearSearch(int array[],int N,int key);

int main()
{
int array[N]={12,1,0,-5,6,8,10,18};
int foundIndex;
int key; 
cout<<"Enter key: "; // asks for key
cin>> key;
foundIndex=linearSearch(array, N, key); // calls the function 
if(foundIndex==NOT_FOUND)cout<<"Not found\n";
 else cout<<"Found element "<<array[foundIndex]<<
  " at index "<<foundIndex<<endl;
}
int linearSearch(int array[],int N,int key)
{
int i;
 for(i=0; i<N; i++){ // looks for the key in the array
  if (array[i]== key) 
   return(i);
  }

return(NOT_FOUND);
}
