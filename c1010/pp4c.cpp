#include <iostream>
using namespace std;
const double Tax_Rate=0.0925;
double totalcost(double numberItems, double price);



 int main()
{ 
 double price, numberItems, cost;
 cout<<" Enter cost of one item and number of items: ";
 cin>> price >> numberItems;
 cout<< "$";
 cout.setf(ios::fixed);
 cout.precision(2);
 cost = totalcost(numberItems, price);
 cout<<cost<< endl;
return(0);
}
 double  totalcost( double numberItems, double price){
 double cost, total;
 cost=(numberItems*price);
 total=(cost*Tax_Rate)+ cost;
 return ( total);
}
