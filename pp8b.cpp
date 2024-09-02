/*
file name: pp8b.cpp
Authors Wilson and Jean
this program gets two strings and then combines them
*/
#include<iostream>
#include<cstring>

using namespace std;

void myStrcat(char word1[50],const char word2[50]);
   // this function changes the first parameter snd returns notthing
int main()
{
   char word1[50];
   char word2[50];
   cout<<"Enter first string: ";
   cin>>word1;
   cout<<"Enter second string: ";
   cin>>word2;
   myStrcat( word1, " " );
   myStrcat(word1, word2);
   cout<<"First string: "<<word1<<endl;

   return(0);
}
void myStrcat(char word1[50],const char word2[50])
{
   int i;
   int y;
   for(i=0,y=strlen(word1);word2[i]!='\0';i++,y++){
      word1[y]=word2[i];
   }
   word1[y]='\0';
}
