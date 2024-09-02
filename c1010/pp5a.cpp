#include<iostream>
using namespace std;

void myswap(int& variable1, int& variable2);

int main()
{
  int variable1, variable2;
 
  cout<< "Enter first number: ";
  cin>>variable1;
  cout<< "Enter second number: ";
  cin>>variable2;
  myswap(variable1, variable2);
  cout<< "First number: "<<variable1<< endl;
  cout<< "Second number: "<<variable2<< endl;
  return(0);
}
 void myswap(int& variable1,int& variable2)
{
  int temp;
  temp = variable1;
  variable1 = variable2;
  variable2 = temp;
}
