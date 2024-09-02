#ifndef SENSOR_H
#define SENSOR_H
#include "timestamp.h"
class Sensor{
	private:
		int sensorNumber;
		double mileMarker;
		Timestamp stamp;
	public:
		Sensor();
		Sensor(int, double, const Timestamp&);
		Sensor( const Sensor&);
		void setSensorNumber( int num);
		int getSensorNumber() const{ return sensorNumber;}
		void setMileMarker( double marker);
		double getMileMarker() const{ return mileMarker;}
		void setStamp( const Timestamp& stamp);
		Timestamp getStamp() const{ return stamp;}
		// overloaded assignment operator
        Sensor operator=( const Sensor& );
};

#endif