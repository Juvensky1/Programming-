#include<iostream>
using namespace std;
bool isPositive(int number);
int main()
{
int number;

  do
  {
  cout<<"Enter number (0 to end): ";
  cin>>number;

  if(isPositive(number))
    cout<<number<<" is positive"<<endl;
  else
    cout<<number<<" is negative"<<endl;
  }
 while (number!=0);

return(0);
}
bool isPositive(int number){
 if (number>=0) return true;
 return false;
 }
