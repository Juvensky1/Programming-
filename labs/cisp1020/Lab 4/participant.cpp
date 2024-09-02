#include "participant.h"
#include <iomanip>
using std::ifstream;

/* default constructor
 */ 
Participant::Participant(){
	strcpy(key, "");
	strcpy(lastName, "");
	strcpy(firstName, "");
	height = 0.0;
	numActivities = 0;
}

/* copy constructor
 */
Participant::Participant(const Participant& p){
	setHeight(p.height);
	setFirstName(p.firstName);
	setLastName(p.lastName);
	setNumActivities(p.numActivities);	
	setKey(p.key);
	for( int i = 0; i<numActivities; i++){
	     activities[i] = p.activities[i];
    }
}

/* 2-arg constructor
 * Parameters:
 *    first firstname
 *    last lastname
 */
Participant::Participant(const char* first, const char* last){
	setFirstName(first);
	setLastName(last);
	makeKey();
	numActivities = 0;
	height = 0;
}

/* setLastName sets participant's last name
 * Parameter last name
 * Returns: nothing
 */
void Participant::setLastName(const char* last){
	strcpy(lastName, last);
	lastName[0] = toupper(lastName[0]);
	for(int i = 1; i< strlen(lastName); i++){
		lastName[i]= tolower(lastName[i]);
	}
}

/* setFirstName sets participant's first name
 * Parameter first name
 * Returns: nothing
 */
void Participant::setFirstName(const char* first){
	strcpy(firstName, first);
	firstName[0] = toupper(firstName[0]);
	for(int i = 1; i< strlen(firstName); i++){
		firstName[i]= tolower(firstName[i]);
	}
}

/* setKey sets key
 * Parameter key
 * Returns: nothing
 */
void Participant::setKey(const char* k){
	strcpy(key, k);
}

/* setNumActivities sets participant's number of activities
 * Parameter number of activities
 * Returns: nothing
 */
void Participant::setNumActivities(int num){
	if(numActivities >= 0 && numActivities <= MAX_ACTS){
		numActivities = num;
	}
}

/* setHeight sets participant's height
 * Parameter height
 * Returns: nothing
 */
void Participant::setHeight(double h){
	if( h > 0.0){
		height = h;
   }
}

void Participant::setActivity( const Activity& a){
	if(numActivities < MAX_ACTS){
	   activities[numActivities] = a;
	   numActivities++;
    }
}


bool Participant:: operator==( const Participant& p ) const {
   return strcmp(key, p.key) == 0;
}

bool Participant:: operator<(const Participant& p) const {
	return strcmp(key, p.key) < 0 ;
}

ostream& Participant::write(ostream& binOut) const{
	
	binOut.write((char*)this, sizeof(Participant));
	return binOut;
}

istream& Participant::read(istream& binIn){
	binIn.read((char*)this, sizeof(Participant));
	return binIn;
} 

void Participant::makeKey(){
	strcpy(key, lastName);
	strcat(key, firstName);
	for(int i = 0; i< strlen(key); i++){
		key[i]= tolower(key[i]);
	}
}

/* operator>> overloaded for Participant object
 * Parameters:
 *    in the input stream
 *    p the participant
 * Returns the input stream
 */
istream& operator>>(istream& in, Participant& p){
	in>> p.firstName;
	in>> p.lastName >> p.height >> p.numActivities;
	for(int i = 0; i< p.numActivities; i++){
		in >> p.activities[i];
	}
	return in;
}

/* operator<< overloaded for Participant object
 * Parameters:
 *    out the output stream
 *    p the participant
 * Returns the output stream
 */
ostream& operator<<(ostream& out, const Participant& p){
	out << p.firstName<< " ";
	out << p.lastName << " "<<fixed<<showpoint<<setprecision(2)<<p.calcTotalMiles(); 
	return out;
}

/* calcTotalMiles calculates total miles walked
for each aparticipant 
 No parameters
 */
double Participant::calcTotalMiles() const {
	double totalMiles = 0;
	for(int i = 0; i < numActivities; i++){
		totalMiles += activities[i].calcMiles(height);
		
    }
    return totalMiles;
}