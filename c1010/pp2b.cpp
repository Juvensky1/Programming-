/*
*file.pp2b.cpp
*Author: Wilson FLynn and Juvensky Hyppolite - Jean
*this program computes and prints vaules 
*/
 #include <iostream>
 using namespace std; 

 int main()
 {
  int i = 3;
  int j = 10; 
  double x  = 9.9;
  double y = -0.6;
  cout<<" i/j is "<< i/j<< endl;
  cout<<" i&j is "<<i%j<< endl;
  cout<<" j/i is "<<j/i<< endl;
  cout<<" j%i is "<<j%i<< endl;
  cout<< " x*i/j is "<<x*i/j<< endl;
  cout.setf(ios::fixed);
  cout.precision(2);
  cout<< " x*(i/j) is "<<x*(i/j)<< endl;
  cout.precision(1);
  cout<< " x/y+i is "<<x/y+i<< endl;
  cout.precision(5);
  cout<< " j+y/x is "<<j+y/x<< endl;
  cout.precision(2);
  cout<< " static_cast<double>(i)/j+y is "<<static_cast<double>(i)/j+y<< endl;
  return(0);
 }

