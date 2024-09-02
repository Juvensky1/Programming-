#include "activity.h"
#include <cmath>
/* default constructor
 */ 
Activity::Activity() {
   minutes = code = 0;
}

void Activity::setMinutes(int m){
	if(m >= 0 && m <= 60)minutes = m;
}

void Activity::setCode(int c){
	code = c;
}

double Activity::calcMiles( double height) const {
	double steps = STEPS[code] * minutes;
	double distance = ((0.413* height) / 12) * steps;
	return distance / 5280.0;
}

Activity& Activity::operator=(const Activity& a){
	if(this != &a){
		code = a.code;
		minutes = a.minutes;
	}
	return *this;
}

istream& operator>>(istream& in, Activity& a){
	in >> a.code;
	in >> a.minutes;
	return in;
}

