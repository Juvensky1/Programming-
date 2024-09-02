/*
*File.pp2a.cpp
*Author: Wilson Flynn and Juvensky Hyppolite - Jean
*This program prints an output statement using the variable x
*/
#include<iostream>
using namespace std;

int main()
{
  double x = 42.1298;
  cout<< "The answer to the question of\n"
           << "Life , The Universe, and Everything is ";
  cout.precision(0);
  cout.setf(ios::fixed);
  cout<<x;//prints 42
  cout<< ", not ";
  cout.precision(1);
  cout<<x; //print 42.1
  cout<< " and not $";
  cout.precision(2);
  cout<<x<< endl; //prints 42.13
  return(0);
}
