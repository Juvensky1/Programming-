/*
* File.pp4a.cpp
*Author: Wilson Flynn and Juvensky Hyppolite - Jean
*This program randomly selects a card from a regular 52-card deck of cards.
*/
#include<iostream>
#include<cstdlib> //for srand and rand functions
#include<ctime> //for time function
using namespace std;

const int ACE = 1;
const int TWO = 2;
const int CLUBS = 0;
const int SPADES = 1;
const int DIAMONDS = 2;
const int HEARTS = 3;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;
const int SIX = 6;
const int SEVEN = 7;
const int EIGHT = 8;
const int NINE = 9;
const int TEN = 10;
const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;

int main()
{ 
  int randomNumber;
  srand( time(0)); //only seed once
  randomNumber = rand() % 13 +1; //between 1 and 13

switch(randomNumber)
 {
  case ACE:
  cout<< " Ace of ";
  break;
  case TWO:
  cout<< " Two of ";
  break;
  case THREE:
  cout<< " Three of ";
  break;
  case FOUR:
  cout<< " Four of ";
  break;
  case FIVE:
  cout<< " Five of ";
  break;
  case SIX:
  cout<< " Six of ";
  break;
  case SEVEN:
  cout<< " Seven of ";
  break;
  case EIGHT:
  cout<< " Eight of ";
  break;
  case NINE:
  cout<< " Nine of ";
  break;
  case TEN:
  cout<< " Ten of ";
  break;
  case JACK:
  cout<< " Jack of ";
  break;
  case QUEEN:
  cout<< " Queen of ";
  break; 
  case KING:
  cout<< " King of ";
  break;
 }

  randomNumber = rand() % 4;

switch(randomNumber)
 {
  case CLUBS:
  cout<<"clubs"<< endl;
  break;
  case SPADES:
  cout<<"spades"<< endl;
  break;
  case DIAMONDS:
  cout<<"diamonds"<< endl;
  break;
  case HEARTS:
  cout<<"hearts"<< endl;
  break;
 }
return(0);
}


