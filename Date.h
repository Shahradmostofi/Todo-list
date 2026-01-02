#ifndef DATE_H
#define DATE_H
class Date
{
    private:
        int Year;
        int Month;
        int Day;
    public:
    Date (int = 1400 , int = 1 , int = 1 );
    void setDate(int = 1400, int=1 , int = 1 );
    void setDay(int );
    void setMonth(int );
    void setYear(int );
    int getDay()const;
    int getMonth()const;
    int getYear()const;
    friend ostream & operator << (ostream & , const Date &);
    bool operator > (const Date &);
};

#endif