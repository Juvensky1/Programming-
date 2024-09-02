
#include "racer.h"
#include <vector>
#include "sensor.h"
#include "timestamp.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

using std::right;
using std::left;
using std::setw;

/* default constructor
 */ 
Racer::Racer() {
   name ="";
   number = 0;
   totalDistance = 0.0;
   totalTime = Timestamp();
   
}

/* copy constructor
 */
Racer::Racer( const Racer& r ) {
	setName(r.name);
   setnumber( r.number );
   setTotalTime( r.totalTime );
   setTotalDistance( r.totalDistance );
   sensors = r.sensors;
}

/* overloaded assignment operator
 * Parameter racer on right-hand side of =
 * Returns: the racer on the left-hand side of the =
 */
Racer& Racer::operator=( const Racer& r ) {
   if ( this != &r ) { // don't copy the same object to itself
      name = r.name;
      number = r.number;
      totalTime = r.totalTime;
      totalDistance = r.totalDistance;
      sensors = r.sensors;
      //totalSpeed = r.totalSpeed;
   }
   return *this;
}


/* operator< returns true if one racer r1 < r2 
 * Parameters two racers
 * Returns true if 
 */
bool operator<(const Racer& r1, const Racer& r2 ) {
       return r1.getTotalTime() < r2.getTotalTime();
}

/* operator<< overloaded for Racer object
 * Parameters:
 *    outStream the output stream
 *    r the racer
 * Returns the output stream
 */
ostream& operator<<( ostream& outStream, const Racer& r ) {
	if( r.cheater){
		outStream<<"*";
		outStream <<setw(41)<<left<<r.getName() << " " <<setw(6)<<right<< r.getnumber()<< "    "<<setw(12)<<right<< r.getTotalTime()<<endl; 
	}
	else{
   outStream <<setw(41)<<left<< r.getName() << " " <<setw(6)<<right<< r.getnumber()<< "    "<<setw(12)<<right<< r.getTotalTime()<<endl; 
   }
   return outStream;
}

/* operator>> overloaded for Racer object
 * Parameters:
 *    inStream the input stream
 *    r the racer
 * Returns the input stream
 */
istream& operator>>( istream& inStream, Racer& r )  {
	Sensor sen;
	Timestamp t;
	string fornow;
	r.sensors.clear();
	getline(inStream, fornow);

	// sets racer name
	size_t found = fornow.find(';');
	r.setName(fornow.substr(0,found));
	fornow.erase(0, found+1);
	
	//sets racer number
    found = fornow.find(';');
	r.setnumber (stoi(fornow.substr(0,found)));
	fornow.erase(0, found+1);
	
	
	
   while( found != std::string::npos){
   	  // sets sensor number
   	  found = fornow.find(';');
	  sen.setSensorNumber(stoi(fornow.substr(0,found)));
	  fornow.erase(0, found+1);
	  
	  // sets mile marker
	  found = fornow.find(';');
      sen.setMileMarker(stod(fornow.substr(0,found)));
	  fornow.erase(0, found+1);
	  
	  // sets hours
	  found = fornow.find(':');
      t.setHour(stoi(fornow.substr(0, found)));
      fornow.erase(0, found+1);

    // sets minutes
      found = fornow.find(':');
      t.setMinute (stoi(fornow.substr(0, found)));
      fornow.erase(0, found+1);

      //sets seconds
      found = fornow.find(':');
      t.setSecond (stoi(fornow.substr(0, found)));
      fornow.erase(0, found+1);
      
      // sets milliseconds
      found = fornow.find(';');
      t.setMillisecond(stoi(fornow.substr(0, found)));
      fornow.erase(0, found+1);
	  
	  sen.setStamp(t);
	  r.sensors.push_back(sen);
	  
   }
   r.setTotalTime(r.sensors.back().getStamp() - r.sensors.front().getStamp());
   return inStream;
}
   
void Racer::setSensors(const Sensor& s){

  sensors.push_back(s);
}

void Racer::setName(string n){
	if(n != "") name = n;
}

void Racer::setnumber( int n){
	if( n > 0) number = n;
}

void Racer::setTotalTime( Timestamp t){
	totalTime = t;
	
}

void Racer::setTotalDistance(double d){
	totalDistance = d;
}

void Racer::setTotalSpeed( double s){
	totalSpeed = s;
	
}



double calcSpeed(Sensor s1, Sensor s2){
	Timestamp t1 = s1.getStamp() - s2.getStamp();
	double ms = t1.calcMilli();
    double m = s1.getMileMarker() - s2.getMileMarker();
    ms /= 3600000;
	return m/ms;
}

void Racer::isCheater( int num){
	int i;
	for( i = 1; i<sensors.size(); i++){
		double var = calcSpeed(sensors[i], sensors[i-1]);
		if(var > 14.0 || num !=sensors.size()){
			cheater = true;
			break;
	   }
	}
	
}