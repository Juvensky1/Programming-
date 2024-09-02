/*
*File.pp2e.cpp
*Author: Wilson Flynn and Juvensky Hyppolite - Jean
*This program prints your status 
*/
#include<iostream>
using namespace std;

int main()
{ 
 char status;
 cout<<"Enter status(M or S): ";
 cin>>status;
switch(status){
 case'M': case'm':
  cout<<"You entered married"<< endl;
   break;
  case'S': case's':
  cout<<"You entered single"<< endl;
   break;
  default:
  cout<<" Invalid status ?"<< endl;
 }
 return(0);
}
  
