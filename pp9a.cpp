#include<iostream>
#include<string>
using namespace std;

void swap(string *word1, string *word2);

int main()
{
  string word1, word2;

  cout<< "Enter first word: ";
  cin>>word1;
  cout<< "Enter second word: ";
  cin>>word2;
  swap(word1, word2);
  cout<< "First word: "<<word1<< endl;
  cout<< "Second word: "<<word2<< endl;
  return(0);
}
 void swap(string *word1, string *word2)
{
  string temp;
  temp = *word1;
  *word1 = *word2;
  *word2 = temp;
}


