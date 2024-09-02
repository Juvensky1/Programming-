/* File: binaryRead.c
 * Author: Juvensky
 * Description: example of reading binary data in a structure
 */
#include <stdio.h>

#define MAX_NAME_LENGTH 30

typedef struct employee {
   char firstName[MAX_NAME_LENGTH];
   char lastName[MAX_NAME_LENGTH];
   int age;
   double salary;
} Employee;

int main( int argc, char *argv[] ) {
   Employee e[5]; 

   FILE *in; //  file pointer
   
   int i;

  if (argc != 2){ //checks for input file
       printf(" usage: %s filename\n", argv[0] );
       return 0;
  }
  i = 0;
  in = fopen( argv[1], "rb"); // rb is read binary, open file
  if (in == NULL){// checks if empty 
      printf( " %s is empty\n" , argv[1] );
     
  }
  else if ( in != NULL){ // open didn't fail
           fread( &e[i], sizeof(Employee), 1, in);
           // read employees one by one into structure
           while (!feof(in) ){
                 i++;
                 fread( &e[i], sizeof(Employee), 1, in);
           } 
  }
  ,
  
   fclose(in);// close the input file

         // print employees read
         for( i= 0; i  < 5; i++ ) {
            printf("%s %s %d %lf\n", e[i].firstName, e[i].lastName, e[i].age, e[i].salary );
         }

   return 0;
}
