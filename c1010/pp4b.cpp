#include<iostream>
using namespace std;
void squareAndPrint();
int main()
{
squareAndPrint();
return(0);
}
void squareAndPrint()
{
double x;
double square;
cout<<" Enter a number: ";
cin>>x;
cout.setf(ios::fixed);
cout.precision(2);
square=x*x;
cout<< "The square of "<<x<<" is "<<square<<endl; 
}
