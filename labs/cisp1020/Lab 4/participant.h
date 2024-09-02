#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include<cstring>
#include"activity.h"
#include<iostream>

using namespace std;

const int MAX_NAME = 30;
const int MAX_ACTS = 365;

class Participant{
	private:
		double height;
		Activity activities[MAX_ACTS];
		int numActivities;
		char firstName[MAX_NAME];
		char lastName[MAX_NAME];
		char key[MAX_NAME*2];
	public:
		Participant();
		Participant(const Participant& p);
		Participant(const char* first, const char* last);
		~Participant(){}
		void setHeight(double h);
		double getHeight() const {return height;}
		void setActivity( const Activity& a);
		Activity getActivity(int i) const {return activities[i];}
		void setFirstName(const char* first);
		const char* getFirstName() const {return firstName;}
		void setLastName(const char* last);
		const char* getLastName() const {return lastName;}
		int getNumActivities() const {return numActivities;}
		void setNumActivities( int num);
		void setKey(const char* key);
		const char* getKey() const {return key;}
		 bool operator<(const Participant& p) const ;
		 bool operator==(const Participant& p) const;
	    ostream& write(ostream& outBin) const;
	    istream& read(istream& inBin );
	    void makeKey();
	    friend istream& operator>>(istream& , Participant&);
	    friend ostream& operator<<(ostream& , const Participant&);
		double calcTotalMiles() const;
};

#endif