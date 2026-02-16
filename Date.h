#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;
class Date
{
    private:
        int Year;
        int Month;
        int Day;
    public:

        Date (int = 1404 , int = 1 , int = 1 );
        void setDate(int , int, int );
        void setDay(int );
        void setMonth(int );
        void setYear(int );
        int getDay()const;
        int getMonth()const;
        int getYear()const; 
        bool operator > (const Date &) const ;
        bool operator < (const Date &)const ;
        friend ostream & operator << (ostream & , const Date &);
};

#endif