/*
file name pp10c.cpp
Wilson Jean
this program
*/
#include<iomanip>
#include<iostream>
#include<cstring>

using namespace std;
  

struct Pet
{
 char name[20];
 int age;
 bool isNeutered;
};

void printPets(Pet[], int);

int main()
{
  Pet pets[5]={{"Fido",7,true},{"Puppy",1,false},{"Kityy",1,false},{"Brutus",11,true},{"Bilbo",15,true}};
  printPets(pets, 5);
  
  return(0);
}

void printPets(Pet pets[], int count)
{
  cout<<setw(15)<<left<<"Name"<<setw(9)<<right<<"Age"<<setw(15)<<right<<"Neutered"<<endl
  <<"--------------------------------------------"<<endl;
  int i;
  
  for(i=0;i<count;i++){
   cout<<setw(15)<<left<<pets[i].name;
   cout<<setw(9)<<right<<pets[i].age;
   if(pets[i].isNeutered == true){
    cout<<setw(15)<<right<<"Yes"<<endl;
    }
   else{
    cout<<setw(15)<<right<<"No"<<endl;
   }   
  }
return;
}
