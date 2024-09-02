/* file name: pp7c.cpp
Auhtors: Wilson and Jean
This Program gets a number and prints it out with a dollar amount
*/
#include<iostream>

using namespace std;
const int MAX_AMOUNTS = 10;
void printMoney(double m); 
// prints out the paramenter in a dollar format 
int main()
{
double x, m;
int i=0;
double amounts[MAX_AMOUNTS];

  do{
   cout<< "Enter number (-1 to end): ";
   cin>> x;
  if (x == -1) // ends at -1
  { 
   break;
  }
  else{
   amounts[i]=x; // sets each array vaule
   i++; // i = i+1
  }

 }
 while(i< MAX_AMOUNTS); // ends loop when i = 10

int y;
 for(y=0;y<i;y++){ // prints the values with $
    printMoney( amounts[y]   );// calls the function
  }
 
return(0);
}
void printMoney(double m)
{
int y;
//double amounts[MAX_AMOUNTS];
 cout.setf(ios::fixed);
 cout.precision(2);
 cout<<"$"<< m   <<endl;
return; 

} 
  
