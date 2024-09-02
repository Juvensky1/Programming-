/* 
*File.MoviesLab1.cpp
*Author: Juvensky Hyppolite - Jean
*This program sells tickets to customers for a single movie, prints receipts for
// purchased tickets, tells the user if there are enough seets for an order, and 
// tells if the movie is sold out.
*/
#include <iostream>
using namespace std;

const double TICKET_PRICE = 9.95;
const double TAX_RATE = 0.095;

int main()
{
  int seatingLeft = 300;   // number of empty seats available for purchase
  string movieName = "The Best Movie Ever";  // movie title
  string rating = "PG-13" ;  // Motion Picture Association of America rating
  int startHour = 4;  // start time in 12-hour clock
  int startMinute = 30;
  char ampm = 'P';
  int tickets;  // how many tickets user wants to buy
  double subtotal, tax, total;  // user's receipt values
  int difference;
   cout<< " Welcome to My Theater's Ticketing Program."<< endl ;
   
      do
       {
         cout<< " Today we are showing: " <<movieName<< " rated " <<rating<< " at"<< endl;
         cout<< " "<<startHour<< ":" <<startMinute<< " "<<ampm<< "M"<< endl;
         cout<< " How many tickets (0 to end)? ";
         cin>> tickets;     

         if (tickets > 0 && tickets <= 300){
         cout<< " Tickets purchased: "<<tickets<< endl;
         cout.setf(ios::fixed);
         cout.precision(2);
         subtotal = TICKET_PRICE*tickets;
         tax = TAX_RATE*subtotal;
         total = tax+subtotal;
         cout<< " Subtotal: $"<<subtotal<< endl;
         cout<< " Tax: $"<<tax<< endl;
         cout<< " Total: $"<<total<< endl;
           
         }
         else if (tickets < 0){
            cout<< " Invalid number of tickets: "<<tickets<< endl; 
         }            
         else if (seatingLeft = 0){
            cout<< "I'm sorry. We're SOLD OUT."<< endl;
         }             
         else if (seatingLeft < tickets){
            cout<< "Could not process your request. There are only "<<seatingLeft<< " tickets left."<< endl;
         }
         else if (tickets == 0){
            cout<< " Thank you for using My Theatre's Ticketing Program."<<endl;
             return(0);
         }
   }  while (tickets != 0);  
return(0);
}
  
