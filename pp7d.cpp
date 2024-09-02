/* file name: pp7d.cpp
Auhtors: Wilson and Jean
This Program gets a number and prints it out with a dollar amount
*/
#include<iostream>

using namespace std;
const int MAX_NUMBER=10;
void printMonies(double mArray[], int n);
// prints out the paramenter in a dollar format
int main()
{
int n;
double x;
int i=0;
double mArray[MAX_NUMBER];

  do{
   cout<< "Enter number (-1 to end): ";
   cin>> x;
  if (x == -1) // ends at -1
  {
   break;
  }
  else{
   mArray[n]=x; // sets each array vaule
   n++; // n = n+1
  }

 }
 while(n< MAX_NUMBER); // ends loop when i = 10
  
    printMonies( mArray,n );// calls the function

return(0);
}
void printMonies(double mArray[],int n)
{
int y;
 for(y=0;y<n;y++){
 cout.setf(ios::fixed);
 cout.precision(2);
 cout<<"$"<<mArray[y]  <<endl;
 }
return;
}
