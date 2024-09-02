#include <fstream>
#include "participant.h"
#include "activity.h"

int main() {
   Participant p;
   ofstream binOut;
   int i;
   ifstream in;
   in.open( "fitness2023.txt", ios::in );
   // open tracking.bin for writing binary
   binOut.open( "tracking.bin", ios::out | ios::binary );
    
   // get p  from stdin and write them to a binary file called tracking.bin
   while(in >> p) { // overloaded >> in Participant class 
      p.write( binOut );
   }
   in.close();
   binOut.close();
   
   // test binary write by reading binary file and printing contents to screen
   ifstream binIn;
   binIn.open( "tracking.bin", ios::in | ios::binary );
    while( p.read(binIn)) {
        cout << p << endl;
   }
   return 0;
}