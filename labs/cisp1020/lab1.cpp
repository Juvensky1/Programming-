/*
*File : lab1.cpp
*Author: Juvensky Hyppolite - Jean
*Date: 1/17/2023
*This program searches for a job by title or by skill.
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int MAX_JOBS = 10;
const int MAX_SKILLS = 10;
const int MAX_STRING_LENGTH = 256;


struct Job {
   char jobTitle[MAX_STRING_LENGTH];
   int numSkills;
   char skills[MAX_SKILLS][ MAX_STRING_LENGTH];
   double salary;
   char company[MAX_STRING_LENGTH];
};

void readData( Job[], ifstream& input, int& count);
//reads Data from the file
//Precondition: File exists and is not empty
//Postcondition: File has been read
//Parametrs: array of Job, number of jobs in file

void print (Job job);
//prints out the chart nicely
//Precondition: user has inputted skill or job Title 
//Postcondition:The chart has been printed out in the correct format
//Parameters: array of Job, number of jobs in filr

void selectionSort(Job jobs[], int N);
//sorts array of Job structures by alphabetical order
//Precondition: data has been read 
//Postcondition: array has been sorted alphabetically
//Parameters: array of Job, number of jobs in file

void printHeader();
// prints the header 
//Precondition: 
//Postcondition:

 int main(){
 ifstream input;
 string filename;
 char c;
 int i;
 int j;
 Job jobs [MAX_JOBS];
 int numJobs;
 int count;
 int answer;
 char skill[30], title[30];

 cout<< " Welcome to the Jobs.com"<< endl;
 cout<< " Jobs file: ";
 cin>>filename;
 input.open(filename.c_str()); //opens filename entered by user
 if (input.fail()){
      cout<< " Input file "<<filename<< " does not exist. Please" 
      <<" contact the administrator. "<<endl;
      cout<< " Thank you for using Jobs.com."<<endl;
      exit(0);
  }
  else{ // file does exist
      input.get(c);
 
      if (input.eof()){ //reads till end of file
       cout<< " Input file "<<filename<< " is empty. Please contact"
       <<" the administrator."<<endl;
       cout<< " Thank you for using Jobs.com. "<<endl;
       exit(0);
       
      }
      input.putback(c); //file is not empty
     
      
  }
   
  readData (jobs, input, numJobs);

  input.close();

  selectionSort(jobs, numJobs);
 
  do{
    cout<< "1 Search for job by title"<< endl;
    cout<< "2 Search for a job by skill"<< endl;
    cout<< "3 Quit"<< endl;
    cout<< "Option> ";
    cin>> answer;
    if ( answer != 1 && answer != 2 && answer != 3){
       cout<< "Invalid"<< endl;
    }
    else if (answer == 1){
        bool choice = true;
        cout<< "Job Title: ";
        cin>> title;
        title[0] = toupper (title[0]);
        for ( i = 0; i< numJobs; i++){
         if  ( strstr( jobs[i].jobTitle, title ) != NULL ){
            if ( choice){
               printHeader();
               choice = false; // doesn't repeat header
            }
            print(jobs[i]);
         }
       }
        
     
    }
    else if ( answer == 2){
        bool choice = true;
        cout<< "Job skill: ";
        cin>> skill;
        skill[0] = toupper (skill[0]);
        for (i = 0; i< numJobs; i++){
            for (j = 0; j < jobs[i].numSkills; j++){
                if (strstr (jobs[i].skills[j], skill) != NULL ){ 
                   if (choice){
                      printHeader();
                      choice = false; // doesn't keep printing header
                   }
                print(jobs[i]);
                }
             }
         }
    }
    else if ( answer == 3){
        cout<< "Thank you for using Jobs.com."<< endl;
    }
  } while ( answer != 3);
  
   return (0);
 }


void readData ( Job jobs[], ifstream& input, int& count )
{
    int i = 0;
    int j;
    input.getline ( jobs[i].jobTitle, MAX_STRING_LENGTH);
     

     while (!input.eof() && i < MAX_JOBS){
        input >> jobs[i].numSkills;
        input.get();               
   
       for (j=0; j < jobs[i].numSkills; j++){
            input.getline ( jobs[i].skills[j], MAX_STRING_LENGTH); // reads skills line
       }
     input >> jobs[i].salary;
     input.get();
     input.getline (jobs[i].company, MAX_STRING_LENGTH); // reads company line 
     i++;
    
       if ( i< MAX_JOBS){  
          input.getline ( jobs[i].jobTitle, MAX_STRING_LENGTH);
       }
     }
    
     count = i;
}


void selectionSort(Job jobs[], int N) // sorts the array vaules from smallest to largest 
{
int iMin;
Job temp;
int j;
int i;
  for(i=0; i < N - 1; i++) // keeps loop going until the end of Job
  {  
   iMin=i;
      for(j=i+1;j<N;j++)
      {
        if( strcmp (jobs[iMin].jobTitle , jobs[j].jobTitle) > 0) // checks if the vaule at j is smaller than iMin
        iMin=j;
      }
   temp=jobs[i];        //puts vaule of the first row in temp
   jobs[i]=jobs[iMin]; //puts the vaule of the min in the first row
   jobs[iMin]= temp;    //puts vaule of temp where the smalles value was
  }
}


void print(Job job)
{
  int i;
  int j;
  cout<<setw(30)<<left<<job.jobTitle
      <<setw(2)<<"$ "
      <<setw(7)<<right<<job.salary
      <<setw(9)<<" "
      <<setw(20)<<left<<job.company<<endl;
  for (j = 0; j < job.numSkills; j++){
      cout<<setw(5)<<" "<<left<<job.skills[j]<<endl;
  } 

}

void printHeader()
{
 cout<<setw(30)<<left<<"Job Title"
     <<setw(6)<<left<<"Salary"
     <<setw(12)<<" "
     <<setw(20)<<left<<"Company"<<endl;
 cout<<setfill('-')<<setw(90)<< "-"<<setfill(' ')<<endl;
}
