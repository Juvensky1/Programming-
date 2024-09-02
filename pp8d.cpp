/*
file name: pp8d.cpp
Authors Wilson and Jean
this program replaces a * with a word
*/
#include<fstream>
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

void replaceAsterisk(char line1[],char word[], char line2[]);
   //makes new phrase 
int main()
{
int i;
char line1[50];
char word[15];
char line2[50];
cout<<"Enter phrase: ";
cin.getline(line1,50);
cout<<"Enter word: ";
cin.getline(word, 50);
replaceAsterisk(line1, word, line2);
cout<<line2<<endl;
return(0);
}

void replaceAsterisk(char line1[], char word[], char line2[])
{
int i;
int yl;
yl=strlen(line1);
for(i=0; line1[i]!='*';i++){
  if(line1[i] == '*')break;
}
if (i<yl){
strncpy(line2,line1,i);
line2[i]='\0';
strcat(line2,word);
strcat(line2, &line1[i+1]);
}
return;
}
