#include "participant.h"

using std::ifstream;

Participant::Participant(){
	strcpy(key, "");
	strcpy(lastName, "");
	strcpy(firstName, "");
	height = 0.0;
	numActivities = 0;
}

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

void Participant::setLastName(const char* last){
	strcpy(lastName, last);
}

void Participant::setFirstName(const char* first){
	strcpy(firstName, first);
}

void Participant::setKey(const char* k){
	strcpy(key, k);
}

void Participant::setNumActivities(int num){
	if(numActivities >= 0 && numActivities <= MAX_ACTS){
		numActivities = num;
	}
}

void Participant::setHeight(double h){
	if( height > 0.0){
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

istream& operator>>(istream& in, Participant& p){
	in>> p.firstName;
	in>> p.lastName >> p.height >> p.numActivities;
	for(int i = 0; i< p.numActivities; i++){
		in >> p.activities[i];
	}
	return in;
}

ostream& operator<<(ostream& out, const Participant& p){
	out << p.firstName<< " ";
	out << p.lastName <<" "<< p.height<< " "<<p.calcTotalMiles(); 
	return out;
}

double Participant::calcTotalMiles() const {
	double totalMiles = 0;
	for(int i = 0; i < numActivities; i++){
		totalMiles += activities[i].calcMiles(height);
		
    }
    return totalMiles;
}