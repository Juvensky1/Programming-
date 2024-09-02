/*
*File.lab4.cpp
*Author: Juvensky Hyppolite - Jean
*This program reads data from file by asking user for name, opens, reads from it
*into an array of structures and closes the file.
*/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;


const int SIZE = 20;
const int EXTROVERSION = 0;
const int AGREEABLENESS = 1;
const int CONSCIENTIOUSNESS = 2;
const int NEUROTICISM = 3;
const int OPEN_TO_EXPERIENCE = 4;
const int NUM_QUESTIONS = 50;
const int NUM_TRAITS = 5;
const int MAX_ASSESSMENTS = 26;


struct Big5Assessment {
   string firstName;
   string lastName;
   int age;
   int answers[NUM_QUESTIONS]; // assessment answers
   double normalizedTraits[NUM_TRAITS];   // trait scores
};

void readData( Big5Assessment[], ifstream& input, int& count);
//reads Data from the file
//Precondition: File exists and is not empty
//Postcondition: File has been read
//Parametrs: array of Big5Assessment, number of people in file

void calc ( Big5Assessment people[], int numPerson);
//calculates the score for each trait for each person
//Precondition: data has been read from the file
//Postcondition: The score for each trait has been calculated
//Parameters: array of Big5Assesment , number of people in file

void print (Big5Assessment people[], int count);
//prints out the chart nicely
//Precondition: all the scoresfor each trait have been calculated and names have been sorted
//Postcondition:The chart has been printed out in the correct format
//Parameters: array of Big5Assessmet, number of people in filr

void selectionSort(Big5Assessment people[], int N);
//sorts array of Big5Assessment structures by last name
//Precondition: data has been read and the scores of traits calculated
//Postcondition: array has been sorted by last name
//Parameters: array of Big5Assessment, number of people in file

 int main(){
 ifstream input;
 string filename;
 char c;  
 Big5Assessment people[MAX_ASSESSMENTS];
 int count; 
 int numPerson;
 int i;





  cout<< "Welcome to the Big 5 Assessment Reporter."<<endl;
  cout<< "Enter input file name: ";
  cin>>filename;
  input.open(filename.c_str()); //opens filename entered by user
  if (input.fail()){
      cout<< " Input file "<<filename<< " does not exist."<<endl;
      
  }
  else{ // file does exist
      input.get(c);
 
      if (input.eof()){ //reads till end of file
       cout<< " Input file "<<filename<< " is empty."<<endl;
       
      }
      input.putback(c); //file is not empty
     
      
  }
            
  readData (people , input, numPerson);
     
  input.close();

  calc( people, numPerson);

  selectionSort(people, numPerson);
       
  print(people, MAX_ASSESSMENTS);

  double avgE, avgA, avgC, avgN, avgO;
  for(i=0; i < numPerson; i++){  // calculates the average

        avgE= avgE + people[i].normalizedTraits[EXTROVERSION];
        avgA= avgA + people[i].normalizedTraits[AGREEABLENESS];
        avgC= avgC + people[i].normalizedTraits[CONSCIENTIOUSNESS];
        avgN= avgN + people[i].normalizedTraits[NEUROTICISM];
        avgO= avgO + people[i].normalizedTraits[OPEN_TO_EXPERIENCE];
  }
  cout <<"-----------------------------------------------------------------"<<endl;
  cout<<setw(15)<<left<<"Averages"<<setw(24)<<right<<avgE/numPerson<<setw(4)<<right
  <<avgA/numPerson<<setw(4)<<right<<avgC/numPerson<<setw(4)<<right<<avgN/numPerson
  <<setw(4)<<right<<avgO/numPerson<<endl;



  cout<<"Thank you for using the Big 5 Assessment Reporter. "<<endl;



  return (0);
 }



void readData ( Big5Assessment people[] , ifstream& input, int& count  )
{
   int i = 0;
   int j;
   input>> people[i].firstName >> people[i].lastName >> people[i].age;
      
   while (!input.eof() && i < MAX_ASSESSMENTS){    
       for (j=0; j < NUM_QUESTIONS; j++){
            input>> people[i].answers[j] ;
       }
       i++;
       if(i<MAX_ASSESSMENTS){
         input>> people[i].firstName >> people[i].lastName >> people[i].age;
       }
   }
   count = i;
}

void calc ( Big5Assessment people[] , int numPerson)
{
   int i;
   for ( i=0 ; i<numPerson; i++)
   {
      cout.setf(ios::fixed);
      cout.precision(1);
      cout.setf(ios::showpoint);

      people[i].normalizedTraits[EXTROVERSION] = (20+ people[i].answers[0]
      - people[i].answers[5] + people[i].answers[10] - people[i].answers[15] 
      + people[i].answers[20]
      - people[i].answers[25] + people[i].answers[30] - people[i].answers[35]
      + people[i].answers[40] - people[i].answers[45] + 10.0)/10.0;

      people[i].normalizedTraits[AGREEABLENESS] = (14- people[i].answers[1]
      + people[i].answers[6] - people[i].answers[11] + people[i].answers[16] 
      - people[i].answers[21]
      + people[i].answers[26] - people[i].answers[31] + people[i].answers[36]
      + people[i].answers[41] + people[i].answers[46] + 10.0)/10.0;

      people[i].normalizedTraits[CONSCIENTIOUSNESS] = (14+ people[i].answers[2]
      - people[i].answers[7] + people[i].answers[12] - people[i].answers[17]
      + people[i].answers[22] - people[i].answers[27] + people[i].answers[32]
      - people[i].answers[37] + people[i].answers[42] + people[i].answers[47]
      + 10.0)/10.0;

      people[i].normalizedTraits[NEUROTICISM] = (38- people[i].answers[3]
      + people[i].answers[8] - people[i].answers[13] + people[i].answers[18]
      - people[i].answers[23] - people[i].answers[28] - people[i].answers[33]
      - people[i].answers[38] - people[i].answers[43] - people[i].answers[48]
      + 10.0)/10.0;

      people[i].normalizedTraits[OPEN_TO_EXPERIENCE] = (8 + people[i].answers[4] 
      - people[i].answers[9] + people[i].answers[14] - people[i].answers[19]
      + people[i].answers[24] - people[i].answers[29] + people[i].answers[34]
      + people[i].answers[39] + people[i].answers[44] + people[i].answers[49]
      + 10.0)/10.0;
   }

}

void print( Big5Assessment people[], int numPerson)
{
  cout<<setw(15)<<left<<"Last Name"<<setw(9)<<left<<"First Name"<<setw(9)
  <<right<<"Age"<<setw(4)<<right<<"E"<<setw(4)<<right<<"A"<<setw(4)<<right
  <<"C"<<setw(4)<<right<<"N"<<setw(4)<<right<<"O"<<endl
  <<"------------------------------------------------------------------"<<endl;

  int i;
  for(i=0; i<numPerson; i++){
      cout<<setw(15)<<left<<people[i].lastName;
      cout<<setw(9)<<left<<people[i].firstName;
      cout<<setw(9)<<right<<people[i].age;
      cout<<setw(6)<<right<<people[i].normalizedTraits[EXTROVERSION];  
      cout<<setw(4)<<right<<people[i].normalizedTraits[AGREEABLENESS];
      cout<<setw(4)<<right<<people[i].normalizedTraits[CONSCIENTIOUSNESS];
      cout<<setw(4)<<right<<people[i].normalizedTraits[NEUROTICISM];
      cout<<setw(4)<<right<<people[i].normalizedTraits[OPEN_TO_EXPERIENCE]<<endl;
  } 

}


void selectionSort(Big5Assessment people[], int N) // sorts the array vaules from smallest to largest 
{
int iMin;
Big5Assessment temp;
int j;
int i;
  for(i=0; i < N - 1; i++) // keeps loop going until the end of Big5Assessment
  {  
   iMin=i;
      for(j=i+1;j<N;j++)
      {
        if(people[iMin].lastName > people[j].lastName) // checks if the vaule at j is smaller than iMin
        iMin=j;
      }
   temp=people[i];        //puts vaule of the first row in temp
   people[i]=people[iMin]; //puts the vaule of the min in the first row
   people[iMin]= temp;    //puts vaule of temp where the smalles value was
  }
}
