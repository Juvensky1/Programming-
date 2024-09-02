#include<iostream>
#include<cctype>
using namespace std;
int main()
{
char c;

cout<<"Enter one character: ";
cin.get(c);

if (isupper(c))// checks to see is letter is uppercase
  cout<<"is uppercase"<<endl;
if(islower(c))// checks to see if letter is lowercase
  cout<<"is lowercase"<<endl;
if(isalpha(c))// checks to see if character is alphabetic
  cout<<"is alphabetic"<<endl;
if(isdigit(c))// checks to see if character is a digit
  cout<<"is a digit"<<endl;
if(isspace(c))//checks to see if character is a blank space 
  cout<<"is white space"<<endl;

return(0);
}
