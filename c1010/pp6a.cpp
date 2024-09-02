/* File: chapter6.cpp
 * Author: Cindy Arnold
 * Description: this program reads one number from a file and writes it to a file 
 */
#include <iostream>
#include <fstream>

using namespace std;
void readNum(ifstream& in, double& num);
//reads number from input file
    
void printNum(ofstream& out, double num);
//prints number in output file



int main() { 
   double num;
   ifstream input;
   ofstream output;
   char filename[200];
   char c;

    cout<< "Enter input file name: ";
    cin>>filename;   
    input.open( filename ); //opens filename entered by user
    if (input.fail()){
      cout<< "File "<<filename<< " does not exist"<< endl;
      return(0);
    }
    else{ // file does exist
      input.get(c);
      
       if (input.eof()){ //reads till end of file
        cout<< "File "<<filename<< " is empty"<< endl;
         return (0);
       }

       else{ //file is not empty
        cout<< "Enter output file name: ";
        cin>>filename;
        input.putback(c);
        //continue with rest of code
       }    
    
    }
    output.open( "pp6aoutput.dat" );
    
     readNum(input, num);
     while (!input.eof()){ // not end of file
        printNum(output, num);
        readNum(input, num);
    
    
    } 
	input.close();
	output.close();
   
   return 0;
}

void readNum(ifstream& in, double& num){
     in>> num;
}

void printNum (ofstream& out, double num ){
     
      out.setf(ios::fixed);
      out.precision(2);
      out.setf(ios::showpoint);
      out<<"The number is $"<<num<< endl;
   
}
