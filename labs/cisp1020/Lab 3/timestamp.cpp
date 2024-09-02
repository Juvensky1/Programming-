
#include "timestamp.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using std::right;
using std::left;
using std::setw;
/* copy constructor
 */
Timestamp::Timestamp( const Timestamp& t ) {
   setHour( t.hour );
   setSecond( t.second );
   setMinute( t.minute );
   setMillisecond( t.millisecond );
}

/* default constructor
 */ 
Timestamp::Timestamp() {
   hour = 0;
   minute = 0;
   second = 0;
   millisecond = 0;
   
}


void Timestamp::setHour(const int& h){
	if(h >= 0) hour = h;
	else
	  hour = 0;
}

void Timestamp::setMinute(const int& m){
	if( m >= 0 && m < 60) minute = m;
	else
	  minute = 0;
}

void Timestamp::setSecond(const int& s){
	if( s >= 0 && s < 60) second = s;
	else
	  second = 0;
}

void Timestamp::setMillisecond( const int& milli){
	if (milli >= 0 && milli < 1000) millisecond = milli;
	else
	  millisecond = 0;
}

long Timestamp::calcMilli( ) const{
	long ms= 0;
	ms += hour * 3600000;
	ms += minute * 60000;
	ms += second * 1000;
	ms += millisecond;
	return ms;
}

Timestamp operator-( const Timestamp& t1, const Timestamp& t2){
	Timestamp t;
	long ms1, ms2, diff;
	ms1 = t1.calcMilli();
	ms2 = t2.calcMilli();
	diff = ms1 - ms2;
	t.convert(diff);
    return t;
	
}


void Timestamp::convert(long ms){
	hour = ms/3600000;
	ms %= 3600000;
	minute = ms/60000;
	ms %= 60000;
	second = ms/1000;
	ms %= 1000;
	millisecond = ms;
}

bool operator<(const Timestamp& t1, const Timestamp& t2 ) {
	   return t1.calcMilli() < t2.calcMilli();
}

ostream& operator<<( ostream& outStream, const Timestamp& t ) {
	outStream<<setfill('0')<< setw(2)<< right<<t.getHour()<< ":"<<setw(2)<< right<< t.getMinute()<<":"<<setw(2)<<right<<t.getSecond()<<":"<<setw(3)<< right<< t.getMillisecond()
	<<setfill(' ');
	return outStream;
}