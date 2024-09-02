/*
* File.pp2c.cpp
*Author: Wilson Flynn and Juvensky Hyppolite - Jean 
*This program implements an algorithm and prints a message based on age
*/
#include<iostream>
using namespace std;

int main()
{
  int age;
 cout<<" Enter your age: ";
 cin>>age;
  if (age >= 65){
      cout<<"You can collect social security"<< endl;
  }
  else if (age>=25){
      cout<<"You can rent a car"<< endl;
  }
  else if (age>=21){
      cout<<"You can drink"<< endl;
  }
  else if (age>=18){
      cout<<"You can vote"<< endl;
  }
  
 return(0);
}
