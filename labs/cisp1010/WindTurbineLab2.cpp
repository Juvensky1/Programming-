/*
*File.WindTurbineLab2.cpp
*Author: Juvensky Hyppolite - Jean
*This program calculates how many watts are generated per day by a single wind turbine.
*/
#include<iostream>
#include<cmath>
using namespace std;

bool getNameplateCapacity(double& n);
//Prompts user for nameplate capapcity and puts the value in
//the pass-by-reference variable. n is the value entered by the user.
//Returns true if nameplate capacity is not zero, false 
//otherwise.

bool checkNameplateCapacity( double n);
//returns true if n is in the valid range of 300,.....
//8,000,000 inclusive. Prints out error message if false

bool getAndCheckWindSpeed(double& w);
//Prompts the user for wind speed and puts the value in 
//the pass-by-reference parameter. w is the value entered by
//the user. Checks input and prints error message if out of
//range. Returns true if input is in range, otherwise false.

double calcWattsGenerated(double nameplateCapacity, double windSpeed);
//Returns calculated watts generated. The formal parameter named
//nameplate capacity is the amount of watts generated by the turbine.

void printWattsGenerated(double watts);
//prints out watts, kilowatts, or megawatts generated

const double MAX_WIND_SPEED =  55;
const double MIN_WIND_SPEED = 6;
const double MIN_NAMEPLATE_CAPACITY = 300 ;
const double MAX_NAMEPLATE_CAPACITY = 8000000;
const double END = 0;
const double WINDSPEED_BOUNDARY = 25;



int main()
{
  double nameplateCapacity; //max can be generated per day by windmill
  double windSpeed;         //average wind speed in mph per day
  bool goodInput;           //maxWatts or average windspeed error
  double watts;             //watts generated in one particular day
  

  //set precision for all output
  cout.setf(ios::showpoint | ios::fixed);
  cout.precision( 1 );

  //say hello and get maxWatts for the first time
  cout<< "Welcome to the Wind Turbine Calculator.\n";
  while (getNameplateCapacity( nameplateCapacity) )
   {
         
      goodInput = checkNameplateCapacity( nameplateCapacity );

      // if good maxWatts
      if ( goodInput )
      {
        goodInput = getAndCheckWindSpeed( windSpeed );

         //if no error in maxWatts and windSpeed then
        // calculate and print watts generated
        if( goodInput )
        {
           watts = calcWattsGenerated( nameplateCapacity, windSpeed);
           printWattsGenerated( watts);
        }   //end if no input error in maxWatts and windSpeed
      }//end if good maxWatts
    }// end while maxWatts < 0
      cout<< "Thank you for using the Wind Turbine Calculator."<< endl;
     return (0);
}





bool getNameplateCapacity(double& n){
    cout<< "Please enter the generator's nameplate capacity in watts (0 to end): ";
    cin>>n;
    if ( n != END ){
      return true;
    }
    else
      return false;
  }


bool checkNameplateCapacity(double n){
  if (MIN_NAMEPLATE_CAPACITY <= n && n <= MAX_NAMEPLATE_CAPACITY){
   return true;
  }
  else if ( n < END){
   cout<< "Nameplate capacity must be greater than zero."<< endl;
   return false;
  }

  else if ( n > MAX_NAMEPLATE_CAPACITY){
   cout<< "Nameplate capacity must be less than 8,000,000 watts."<< endl;
   return false;
  }
  else if (n < MIN_NAMEPLATE_CAPACITY){
   cout<< "Nameplate capacity must be between 300 and 8,000,000 watts."<< endl;  
  return false;
  }
}


bool getAndCheckWindSpeed(double& w){
  cout<< "Pleaase enter today's average wind speed in miles per hour: ";
  cin>>w; 


 if (MIN_WIND_SPEED <= w && w <= MAX_WIND_SPEED){
    return true;
  }
  else if (w < END){
    cout<< "Wind speed must be greater than zero."<< endl;
    return false;
  }
  else if ( w > MAX_WIND_SPEED){
    cout<< "Wind speeds too high. The turbine is not operating."<< endl;
    return false;
  }
  else if ( w < MIN_WIND_SPEED){
    cout<< "Wind speed is not sufficient to power the generator."<< endl;
    return false;
  }
}
     
double calcWattsGenerated(double n, double w){ 
  double watts; 
   if (w > WINDSPEED_BOUNDARY)
      w = 25;
  return n * (pow ((w / WINDSPEED_BOUNDARY) , 3));
     
  }


void printWattsGenerated(double watts){
  if ( watts >= 1000000){
    watts = watts / 1000000;
    cout<< "The wind turbine generated "<<watts<< " megawatts today."<< endl;
  }
  else if ( watts >= 1000){
    watts = watts / 1000;
    cout<< "The wind turbine generated "<<watts<< " kilowatts today."<< endl;  
  }
  else if ( watts < 1000){
    cout<< "The wind turbine generated "<<watts<< "watts today."<< endl;
  }
}
  
          
