#include "sensor.h"
#include "timestamp.h"
/* copy constructor
 */
Sensor::Sensor( const Sensor& s ) {
   setSensorNumber( s.sensorNumber );
   setMileMarker( s.mileMarker );
   setStamp( s.stamp);
}

/* default constructor
 */ 
Sensor::Sensor() {
   sensorNumber = 0;
   mileMarker = 0.0;
}

Sensor::Sensor( int num, double mile, const Timestamp& tstamp ) {
   sensorNumber = num;
   mileMarker = mile;
   stamp = tstamp;
}

/* overloaded assignment operator
 * Parameter sensor on right-hand side of =
 * Returns: the sensor on the left-hand side of the =
 */
Sensor Sensor::operator=( const Sensor& s ) {
   if ( this != &s ) { // don't copy the same object to itself
      sensorNumber = s.sensorNumber;
      mileMarker = s.mileMarker;
      stamp = s.stamp;
   }
   return *this;
}

void Sensor::setSensorNumber(int num){
	 sensorNumber = num;
}

void Sensor::setMileMarker(double mile){
	 mileMarker = mile;
}

void Sensor::setStamp(const Timestamp& tstamp){
	 stamp = tstamp;
}
