/* File: exampleStart.c
 * Author: Juvensky Hyppolite - Jean and Ahmed Ghazi
 * Description: read/write names and salaries from/to a file
 */
#include "example.h"

int main()
{
   Employee e[ARRAY_LENGTH];
   int count;

   count = readData( e );   
   printData( e, count );
   
   return( 0 );
}



