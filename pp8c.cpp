/*
file name: pp8c.cpp
Authors Wilson and Jean
this program gets the users age and says when they where born
*/
#include<fstream>
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;


int main()
{
   char strAge[4];
   int age;
   int i;
   bool isValidint = true;
   cout<<"Enter age: ";
 

   cin.getline(strAge, 4);
   for(i=0;strAge[i] !='\0';i++){
     if(isdigit(strAge[i])== false){
      isValidint=false;
       break;
     }
   }
     

   if(isValidint){
    age=atoi(strAge);
     cout<<"Born in "<< 2022-age<<endl;
   }
   else{
    cout<<"Age must be a postive integer"<<endl;
   }
return(0);
}
