/*
file name pp10a.cpp
Wilson Jean
this program 
*/
#include<iostream>
#include<cstring>

using namespace std;

struct Pet
{
 char name[20];
 int age;
 bool isNeutered;
};

int main()
{
 char neutered;
 Pet animal;

 cout<< "Enter pet name: ";
 cin.getline(animal.name,20);
 cout<< "Enter pet age: ";
 cin>>animal.age;
 cout<< "Has pet been neutered(y/n): ";
 cin>>neutered;
   if(neutered=='y' || neutered == 'Y')
     neutered = true;
   else 
     neutered=false;
  cout<<animal.name<<" "<<animal.age<<" ";
  animal.isNeutered=neutered;
   if(animal.isNeutered==true){
     cout<<"neutered"<<endl;
   }
   else{
     cout<<"not neutered"<<endl;
   }
return(0);
}
