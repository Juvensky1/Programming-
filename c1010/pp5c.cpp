#include<iostream>
using namespace std;

void getData(string& name, int& age);

int main()
 {
   string name;
   int age;
  
   getData(name, age);
   cout<<name<< " "<<age<< endl;
   return(0);
 }
  void getData(string& name, int& age)
 {
   cout<< "Enter your name and age: ";
   cin>>name>>age;
 }  
