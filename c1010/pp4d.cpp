#include<iostream>
using namespace std;
double cube(double x);

int main()

{ 
  double c;
  double x;
  while (x > 0)
  {
  cout<< " Enter a number (0 to end): ";
  cin>>x;
  cout.setf(ios::fixed);
  cout.precision(3);
  if (x == 0)
  return(0);
  else
  c = cube(x);
  cout<< " The cube of "<<x<< " is "<<c<< endl;
  }
  return(0);
}
double cube(double x)
{
 return x*x*x;
}

