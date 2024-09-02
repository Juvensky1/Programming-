#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <iostream>
#include <string>
using std::istream;
using std::string;
using std::ostream;

const int STEPS[] =  {85, 152, 136, 242, 121, 242, 61, 167, 242, 182,91, 99, 91,
212, 212, 303, 348, 409, 70, 212, 152, 273, 212, 212, 100, 152, 121, 76};

const string ACTIVITY_NAMES[] = {"Assembly line", "Baseball", "Basketball (shooting baskets)",
"Basketball game", "Bicycling under 10mph", "Bicycling", "Cooking", "Dance", "Football", "Hiking",
"House cleaning", "Gardening", "Miniature golf", "Racquetball", "Rowing", "Running 6 mph", "Running 7 mph", "Running 8 mph",
"Shopping", "Soccer", "Softball", "Stairs", "Swimming laps", "Tennis", "Walking 3mph", "Walking 4mph", "Weightlifting", "Yoga"};

class Activity {
private:
	int minutes;
	int code;
	
public:
	Activity();
	void setMinutes( int m);
	int getMinutes() const {return minutes;}
	void setCode( int c);
	int getCode() const {return code;}
	double calcMiles(double height) const;
	Activity& operator=(const Activity& a);
	friend istream& operator>>(istream& , Activity&);
	friend ostream& operator<<(ostream& , const Activity&);
};

#endif