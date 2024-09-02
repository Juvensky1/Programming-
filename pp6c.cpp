#include<iostream>
#include<iomanip>

using namespace std; 
void readline(); 
int main() { 
 string fulline, firstWord, secondWord;// declareing the words used 
 char c; 
 cout<<"Enter a word: "; 	// asking users for the first word

 do{ 
   cin.get( c );//reads all characters
   if(!isspace(c))
      firstWord += c;// adds one character to the word each loop
   
   }while(!isspace(c));//keeps the loop going while the chraracter being read is not a white space

 if(c != '\n')
	readline();// calls to the function 

 cout<<"Enter another word: ";// asking user for the second word 
 
do{// this is the same loop as the first one but it uses the second word instead of the first 
    cin.get( c );//reads all characters
    if(!isspace(c))
	secondWord += c;

    }while(!isspace(c));//second loops ends if the character is a white space

 if(c != '\n')
        readline();

 cout<<firstWord<<" "<<secondWord<<endl;// prints final words 
}
void readline()
{
 char c;
 string fulline;
	do{
	cin.get( c );//reads all characters
	fulline += c;
	}while( c!='\n');
}

