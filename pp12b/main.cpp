#include <iostream>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	double x;
	cout<<"Enter a double key(0 to end): ";
	cin>>x;
	while(x != 0){
	
		int len = sizeof( x );  // x is the key 
		int n = 8;
		int a = 6;
		// p = x as an array of characters (NOT a C-string, though)
  		const char* p = reinterpret_cast<const char*>(&x);
   		int hashCode = (unsigned int) p[0];
   		for( int i = 1; i < len; i++ ) {
    		hashCode = (hashCode << a ) | (hashCode >> (n-a));
      		hashCode += (unsigned int) p[i];
   		}
   		int b = 59;
   		int hCompressed = abs((17 * hashCode) + b) % 997;
   		cout<< "Compressed hash code: "<< hCompressed << endl;
   		cout<< "Enter a double key(0 to end): ";
   		cin>>x;
	}
	return 0;

}