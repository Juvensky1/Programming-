#include<iostream>
using namespace std;
int main()
{
 double rate;
 double hours;
 double salary; 
 cout<< "enter hours (0 to end): "; 
 cin>> hours; 
 cout.setf(ios::fixed);
 cout.precision(2);
 while (hours > 0)
  {
  cout<< "Enter rate: ";
  cin>>rate; 
  if (hours<=40)
  salary= rate*hours;
  else 
  salary= rate*40+(hours -40)*rate*1.5; 
  cout<<"salary is $"<< salary<< endl;
  cout<<"Etnter hours (0 to end): ";
  cin>> hours;
  }
return(0);
}
