/* this progroam gets and prints account numbers and balances 
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>  
using namespace std;

int main() {
char filename[16];
ifstream input;
ofstream output; 
char c;
double num;
string accountNumber, balance;


cout<<setw(15)<<left<<"Account number"<<setw(9)<<right<<"Balance "<<endl
<<"-------------------------"<<endl;
input.open("pp6b.dat");
  if (input.fail( )){
	cout<< "Inputfile opening failed."<<endl;
	exit(1);
  }
  input >> accountNumber;
  input >> balance;
	
  while(!input.eof()){
  
  cout<<setw(15)<<left<<accountNumber;
  cout<<'$';
  cout<<setw(9)<<right<<balance<<endl;
   input >> accountNumber;
   input >> balance;

}

return(0);
} 
