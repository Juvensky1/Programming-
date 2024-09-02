/*
*File.MadLibHaikusLab3.cpp
*Author: Juvensky Hyppolite - Jean
*This program creats haikus based upon user input.
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;

const int MAX_CHAR = 51;
const int MAX_ROW = 111;

void getData(char noun[], char adjective[], char gerund[]);   
     //gets data from user
    //PreCondition: File has been opened and read

void replaceAsterisk(char line[], char word[], char newLine[]);
    //replaces asterisk with word and makes new phrase
   //Precondition: Have gotten data from user

int main(){
ifstream input;
char c;
char haiku[MAX_ROW][MAX_CHAR];
char noun[20];
char adjective[20];
char gerund[20];
   srand (time(0));
   input.open("haikus.dat"); //opens file
   if (input.fail()){
      cout<< "Haiku file non-existent. Please contact the administrator."<<endl;
      return 1;
   }
   else{ // file does exist
      input.get(c);
 
      if (input.eof()){ //reads till end of file
       cout<< "Haiku file is empty. Please contact the administrator."<<endl;
       return 1;
      }
      input.putback(c); //file is not empty
     
      
   }
   int i; // i is number of things put into the array
      for(i=0;  (!input.eof()) && i < MAX_ROW; i++){
        input.getline(haiku[i],MAX_CHAR); // reads the file
      }
  
      input.close();

     cout<< " Welcome to Mad Lib Haikus! "<<endl;
    
     
      
     
     char x;
    
     do{
     int lineNumber = i/3 ; // finds lineNumber for each Haiku
     int randomHaiku = rand () % lineNumber; // picks random haiku
     randomHaiku = randomHaiku * 3; //makes sure each haiku has the correct 3 lines
        

     getData(noun, adjective, gerund);

     char newLine1[MAX_CHAR];
     char newLine2[MAX_CHAR];
     char newLine3[MAX_CHAR];   
     replaceAsterisk(haiku[randomHaiku], noun, newLine1 );
     replaceAsterisk(haiku[randomHaiku+1], adjective, newLine2);
     replaceAsterisk(haiku[randomHaiku+2], gerund, newLine3);
      
     cout<< "Your Mad Lib Haiku: "<< endl;
     cout<<'\t'<<newLine1<<endl;  
     cout<<'\t'<<newLine2<<endl;
     cout<<'\t'<<newLine3<<endl;
     
  
     cout<< "Continue (Y/N)? ";
     cin>>x;
     } while(x == 'Y' || x == 'y');


    
   cout<< "Thank you for using Mad Lib Haikus!"<<endl;

   return (0);
}

void getData(char noun[20], char adjective[20], char gerund[20])
{

       cout<< "Enter a one syllable noun: ";
       cin>>noun;
       cout<< "Enter a two syllable adjective: ";
       cin>>adjective;
       cout<< "Enter a two syllable gerund (a verb ending in \"ing\" like \"asking\"): ";
       cin>>gerund;
       
}

void replaceAsterisk(char line[], char word[], char newLine[])
{
  
  int i;
  int yl;
  yl=strlen(line);
  for(i=0; line[i]!='*';i++){
     if(line[i] == '*')break;
  }
  if (i<yl){
     strncpy(newLine,line,i);
     newLine[i]='\0';
     strcat(newLine,word);
     strcat(newLine, &line[i+1]);
  }
   if( i == 0){
     newLine[i] = toupper(newLine[i]);
   }
} 
     
