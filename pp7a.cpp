/* file pp7a.cpp
Authors: Wilson Flynn and Jean
this program prints and calulates the sum and average of the grades 
*/
#include<iostream>
using namespace std;
const int MAX_STUDENTS = 5;

int main()
{
int i;
double sum;
double grades[MAX_STUDENTS]={99.9, 65.7,87.8,96.1,56.8};

double gradeTotal[5]={0};

sum=0;
  for(i=0; i<MAX_STUDENTS; i++){
   cout<< grades[i]<<endl;
   sum += grades[i];
  }
cout<<"Average: "<<sum/5<<endl;

return(0);
}
