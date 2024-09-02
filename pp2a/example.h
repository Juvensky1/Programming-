/* File: example.h
 * Author: Juvensky Hyppolite - Jean and Ahmed Ghazi
 * Description: read/write names and salaries from/to a file
 */
#ifndef EXAMPLE_H
#define EXAMPLE_H
#define MAX_NAME_LENGTH 21
#define ARRAY_LENGTH 5

typedef struct employee {
   char name[MAX_NAME_LENGTH];
   double salary;
} Employee;

int readData( Employee[] );
void printData( Employee[], int );

#endif
