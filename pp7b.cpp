/*file name: pp7b.cpp
Auhtors Wilson and Jean
program uses a loop to assign powers of two 
*/
#include<cmath>
#include<iostream>
using namespace std;

int main()
{
int i;
int x;
int powers[11];
  for(i=0; i<11; i++){
  powers[i] = pow(2,i);
  }
  for(i=0; i<11; i++){
  cout<<"powers["<<i<<"] = "<<powers[i]<<endl;
  }
return(0);
}

