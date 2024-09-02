/*
file name: pp8a.cpp
Authors Wilson and Jean
this program gets two words from user and prints them in order
*/
#include<iostream>
#include<cstring> 

using namespace std;

int main()
{
   char word1[6];
   char word2[6];
   cout<<"Enter first word: "; 
   cin>>word1;
   cout<<"Enter second word: ";
   cin>>word2;
   
   //  print word one and word two in order
   if(strcmp( word1, word2)<0){
      cout<<word1<<" "<<word2<<endl;
   }

   else{
     cout<<word2<<" "<<word1<<endl;
   }
   return(0);
}
