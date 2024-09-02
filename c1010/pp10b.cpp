/*
file name pp10b.cpp
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

void getPet(Pet& animal);
void printPet(const Pet& animal);
int main()
{
  Pet animal;
  getPet(animal);
  printPet(animal);
  return(0);
}


void getPet(Pet& animal)
{
  char neutered;
  cout<<"Enter pet name: ";
  cin.getline(animal.name,20);
  cout<<"Enter pet age: ";
  cin>>animal.age;
  cout<<"Has pet been neutered(y/n): "; 
  cin>>neutered;

    if(neutered=='y' || neutered == 'Y'){
     neutered = true;
    }
    else{
     neutered=false;
    }
    animal.isNeutered=neutered;
return;
}


void printPet(const Pet& animal)
{
 cout<<animal.name<<" "<<animal.age<<" ";
  if(animal.isNeutered == true){
   cout<<"neutered"<<endl;
   } 
 else{
   cout<<"not neutered"<<endl;
 }
return;
}
