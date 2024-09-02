/* File: grades.c
 * Author: Chris Ramos and Juvensky Hyppolite - Jean
 * Description: demonstrates dynamically allocates array
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
   int count, i;
   double *grades;
 
   double sum=0, average;
   
   // ask user how many grades
   printf( "How many grades?  " );
   scanf( "%d", &count );
  
   grades = (double*) malloc(sizeof(double)*count);
   // dynamically allocate count grades

   if ( grades != NULL){  
       for ( i=0; i< count; i++){ // gets grades from user
           printf( "Enter grade: ");
           scanf( "%lf", &grades[i]);
           sum += grades[i];
       }
       average = sum/count; // finds average of grades
       printf("Average: %.2lf ",average );
       printf( "\n");
  
       free(grades); // removes allocated memory
       grades = NULL;
       return(0);
   }
   else {
        return (-1);
   }

}
