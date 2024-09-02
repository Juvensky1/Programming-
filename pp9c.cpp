#include<iostream>
#include<string>
using namespace std;

void getData(char[], int *);

int main()
 {
   char name[50];
   int age;

   getData(name, &age);
   cout<<name<< " was "<<age<<" in 2020"<<endl;
   return(0);
 }
  void getData(char name[], int *agePtr)
 {
   cout<< "Enter name: ";
   cin.getline(name, 50);
   cout<< "Enter age: ";
   cin>>*agePtr;
 }


