/*
*file.pp2d.cpp
*Author: Wilson Flynn and Juvensky Hyppolite - jean
*This program assigns a letter grade based upon a numeric grade 
*/
#include<iostream>
using namespace std;
int main()
{
 double  grade;
 cout<<"Enter grade: ";
 cin>>grade;
 if (grade >= 93){
  cout<<'A'<< endl;
 }
 else if(grade >= 83){
  cout<<'B'<< endl;
 }
 else if(grade >= 73){
  cout<<'C'<< endl;
 }
 else if(grade >=65){
  cout<<'D'<< endl;
 } 
 else {
  cout<<'F'<< endl;
 }
 return(0);
}
