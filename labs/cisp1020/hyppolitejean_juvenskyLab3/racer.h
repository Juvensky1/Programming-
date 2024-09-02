#ifndef RACER_H
#define RACER_H
#include "timestamp.h"
#include "sensor.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Racer{
private:
	int number;
	string name;
	Timestamp totalTime;
	double totalDistance;
	double totalSpeed;
	vector <Sensor> sensors;
	bool cheater;
public:
	Racer();
	Racer(const Racer&);
	// destructor
   virtual ~Racer(){}
    void setName(string name);
    string getName() const {return name;}
	void setnumber(int n);
	int getnumber() const{return number;}
	void setTotalTime(Timestamp t);
	Timestamp getTotalTime() const{ return totalTime;}
	void setTotalDistance(double d);
	int getTotalDistance() const{return totalDistance;}
	Sensor getSensors( int i) const{ return sensors[i];}
	void setSensors(const Sensor& s);
	void setTotalSpeed(double speed);
	int getTotalSpeed() const{ return totalSpeed;}
	Racer& operator=(const Racer& r);
	friend ostream& operator<<( ostream&, const Racer& );
    friend istream& operator>>( istream&, Racer& );  
    // overloaded ==
    friend bool operator==( const Racer&, const Racer& );
    // overloaded <
    friend bool operator<( const Racer&, const Racer& );
    friend double calcSpeed( Sensor,  Sensor);
    void isCheater();
};
#endif