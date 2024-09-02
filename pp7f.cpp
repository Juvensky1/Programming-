/*
file name: pp7f.cpp
Authors: Jean and Wilson
this program sorts the array by smallest number to largest
*/
#include<iostream>
using namespace std;
const int N = 8;
void selectionSort(int Array[], int N);
int main()
{
int y;
int Array[]= {12,1,0,-5,6,8,18,10};
selectionSort(Array, N);

   for(y=0;y<N;y++)
   { cout<<Array[y]<<" ";
   }
cout<<endl;
}

void selectionSort(int Array[], int N) // sorts the array vaules from smallest to largest 
{
int iMin;
int temp;
int j;
int i;

  for(i=0; i<N; i++) // keeps loop going until the end of Array
  {  
   iMin=i;

      for(j=i+1;j<N;j++)
      {
        if(Array[j] < Array[iMin]) // checks if the vaule at j is smaller than iMin
        iMin=j;
      }

   temp=Array[i];        //puts vaule of the first row in temp
   Array[i]=Array[iMin]; //puts the vaule of the min in the first row
   Array[iMin]= temp;    //puts vaule of temp where the smalles vaule was
  }
}
