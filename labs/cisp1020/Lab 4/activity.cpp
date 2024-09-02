#include "activity.h"
#include <cmath>

/* default constructor
 */ 
Activity::Activity() {
   minutes = code = 0;
}

/* setMinutes sets activity's minutes
 * Parameter minute
 * Returns: nothing
 */
void Activity::setMinutes(int m){
	if(m >= 0)minutes = m;
}

/* setCode sets activity's code
 * Parameter code
 * Returns: nothing
 */
void Activity::setCode(int c){
	code = c;
}

/* calcMiles calculates miles walked
for each activity 
 Takes height as parameter
 */
double Activity::calcMiles( double height) const {
	double steps = STEPS[code] * minutes;
	double distance = ((0.413* height) / 12) * steps;
	return distance / 5280.0;
}

/* overloaded assignment operator
 * Parameter activity on right-hand side of =
 * Returns: the activity on the left-hand side of the =
 */
Activity& Activity::operator=(const Activity& a){
	if(this != &a){
		code = a.code;
		minutes = a.minutes;
	}
	return *this;
}

/* operator>> overloaded for Activity object
 * Parameters:
 *    in the input stream
 *    a the activity
 * Returns the input stream
 */
istream& operator>>(istream& in, Activity& a){
	in >> a.code;
	in >> a.minutes;
	return in;
}

