/*
file name pp10d.cpp
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
void sortPets(Pet[], int);

int main()
{
  Pet pets[5]={{"Fido",7,true},{"Puppy",1,false},{"Kityy",1,false},{"Brutus",11,true},{"Bilbo",15,true}};
  sortPets(pets, 5); 
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

void sortPets(Pet pets[], int count)
{
int iMin;
Pet temp;
int j;
int i;

  for(i=0; i<count-1; i++) // keeps loop going until the end of Array
  {
   iMin=i;

      for(j=i+1;j<count;j++)
      {
        if(strcmp(pets[j].name , pets[iMin].name)<0){ // checks if the vaule at j is smaller than iMin
        iMin=j;
       }
      }

   temp=pets[i];        //puts vaule of the first row in temp
   pets[i]=pets[iMin]; //puts the vaule of the min in the first row
   pets[iMin]= temp;    //puts vaule of temp where the smalles vaule was
  }
}

 
