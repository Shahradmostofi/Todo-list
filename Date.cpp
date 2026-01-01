#include "Date.h"
#include <iostream>
using namespace std;
Date :: Date (int y , int m , int d )
{
    setDate(y,m,d);
}
void Date :: setDay(int d)
{
    int days[12]={31,31,31,31,31,31,30,30,30,30,30,29};
    if(Month<=6 && Month>=1)
        for(int i=0 ; i<6 ; i++) 
            if(d<=days[i] && d>0)
                this ->Day = d;
    else if(Month>6 && Month<12)
        for(int i=6 ; i<=12 ; i++)
            if(d<=days[i] && d>0)
                this ->Day = d;
};
void Date :: setMonth(int m)
{
    if(m>0 && m<=12)
        this ->Month = m;
};
void Date :: setYear(int y)
{
    if(y>=1400 && y<0)
        this -> Year = y;
};
void Date :: setDate(int y, int m, int d)
{
    setYear(y);
    setMonth(m);
    setDay(d);
}
int Date :: getDay() const
{
    return Day;
}
int Date :: getMonth() const
{
    return Month;
}
int Date :: getYear() const
{
    return Year;
}