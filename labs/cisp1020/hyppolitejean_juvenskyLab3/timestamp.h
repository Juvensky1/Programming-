#ifndef TIMESTAMP_H
#define TIMESTAMP_H
#include <string>
#include <iostream>

using namespace std;

class Timestamp{
	private:
		int hour;
		int minute;
		int second;
		int millisecond;
	public:
		Timestamp();
		Timestamp( const Timestamp& );
		virtual ~Timestamp(){}
		int getHour() const {return hour ;} 
        void setHour( const int& h );
		int getMinute() const {return minute;}
		void setMinute( const int& m);
		int getSecond() const {return second;}
		void setSecond(const int& s);
		int getMillisecond() const {return millisecond;}
		void setMillisecond(const int& milli);
		long calcMilli() const;
		friend Timestamp operator-(const Timestamp& , const Timestamp&);
		void convert(long ms);
		friend bool operator<( const Timestamp&, const Timestamp& );
		friend ostream& operator<<( ostream&, const Timestamp& );
		
	 

};
#endif