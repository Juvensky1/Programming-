/* file: date.h 

 * Author: Aminah Juboori, Juvensky P 

 * Description:  

 */ 

 

#ifndef DATE_H 

#define DATE_H 

#include <iostream> 

 

using namespace std; 

 

enum month_t { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, 

JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER }; 

 

class Date{ 

public: 

    static const int MIN_MONTH; 

    static const int MAX_MONTH; 

    static const int MIN_YEAR; 

    static const int MIN_DAY; 

       int getYear() const {return year ;} 

      void setYear( int y ); 

      void setMonth( int m ); 

       int getMonth() const { return month; } 

      void setDay( int d ); 
 
      int getDay() const { return day; } 

      void setDate( int, int, int ); 

      void printDate () const ; 

      Date(); 

      Date( int mm , int dd , int yyyy ); // month, day, year 

      Date( int mm , int yyyy ); // month, year parameters 

      Date( int yyyy ); // year parameter 

      Date( const Date& d ); 

    virtual ~ Date(); 

    friend Date operator+( const Date& d1, const Date& d2 ); 
    friend bool operator==(const Date& d1, const Date& d2);
     Date operator -() const;
    friend ostream& operator<<(ostream& outStream, const Date& d);
     friend istream& operator>>( istream& inStream, Date& d);

private: 

    int month; // 0 = January 

    int day; 

    int year; 

}; 

#endif 
