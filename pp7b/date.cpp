/* file: date.cpp 

 * Author: Aminah Juboori, Juvensky P 

 * Description:  

 */ 

 

#include "date.h" 

#include <iostream> 

#include <iomanip>
#include <cstdlib> 

using namespace std; 

 

const int Date::MIN_MONTH = JANUARY; 

const int Date::MAX_MONTH = DECEMBER ; 

const int Date::MIN_YEAR = 1; 

const int Date::MIN_DAY = 1; 

 

/* setYear: 

 * Parameters  

 * Returns: 

 */ 

void Date::setYear ( int y ) { 

 

    if ( y < MIN_YEAR ) year = MIN_YEAR; 

    else year = y; 

} 

 

 

/* setDay: 

 * Parameters  

 * Returns: 

 */ 

void Date::setDay ( int d) { 

    if ( d < MIN_DAY ) day = MIN_DAY; 

    else day = d; 

} 

 

/* setMonth: 

 * Parameters  

 * Returns: 

 */ 

void Date::setMonth ( int m ) { 

 

    if ( m < MIN_MONTH) month = MIN_MONTH; 

    else month = m; 

} 

 

 

/* setDate:  

 * Parameters  

 * Returns: 

 */ 

void Date::setDate ( int m, int d, int y ) { 

     

    setMonth( m ); 

    setYear( y ); 

    setDay( d); 

 

} 

 

/* printDate: prints date in form mm/dd/yyyy 

 * Parameters  

 * Returns: 

 */ 

void Date::printDate() const { 

 

    cout << setfill( '0' ) << setw(2) << 

    (month+1) << '/' << day << '/' << setw(4) << year; 

} 

 

 

/* Date: default constructor sets date to today 

 * Parameters  

 * Returns: 

 */ 

Date::Date(){ 

    time_t t = time(NULL); 

    tm* tPtr = localtime( &t ); 

    month = tPtr->tm_mon; 

    day = tPtr->tm_mday; 

    year = tPtr->tm_year + 1900; 

} 

 

/* 3-arg constructor 

* Parameters: 

* mm month, 1 - 12 

* dd day in month 

* yyyy year 

*/ 

Date::Date( int mm, int dd, int yyyy ) { 

    setMonth( mm ); 

    setYear( yyyy ); 

    setDay( dd ); 

} 

 

 

/* Date( int mm, int yyyy) : default constructor sets date to today 

 * Parameters  

 * Returns: 

 */ 

Date::Date( int mm, int yyyy ) { 

    setMonth( mm ); 

    setYear( yyyy ); 
    day = MIN_DAY;
} 

 

 

/* Date (int yyyy): default constructor sets date to today 

 * Parameters  

 * Returns: 

 */ 

Date::Date( int yyyy ) { 

 
   
    setYear( yyyy ); 

   month = MIN_MONTH;
   day = MIN_DAY; 

} 

 

 

/* Date( const Date& d ): default constructor sets date to today 

 * Parameters  

 * Returns: 

 */ 

Date::Date( const Date& d ) { 

    month = d.month; 

    day = d.day; 

    year = d.year; 

} 

Date::~Date() { 

    printDate(); 

    cout << " destroyed\n"; 

} 

 

Date operator+( const Date& d1, const Date& d2 ) { 

    int month = d1.month, day = d1.day, year = d1.year; 

// The code here just adds the days. It doesn’t 

// check to see if it’s a valid day. This is fine 

// for the purpose of the pair programming. 

    day += d2.day; 

    return Date( month, day, year ); 

} 

bool operator==( const Date& d1, const Date& d2 ) {
   if ( d1.day == d2.day && d1.month == d2.month &&
      d1.year == d2.year ) return true;
   else return false;
}

istream& operator>>( istream& inStream, Date& d ) {
   inStream >> d.month >> d.day >> d.year;
   d.setMonth( d.month-1 ); // since user enters 1 for JAN
   return inStream;
}

ostream& operator<<( ostream& outStream, const Date& d ) {
  outStream << setfill( '0' ) << setw(2) <<
     (d.month+1) << '/' << d.day << '/' << setw(4) << d.year;
   return outStream;
}

Date Date::operator-( ) const {
   return Date( abs(this->month-6), this->day, this->year );
}

