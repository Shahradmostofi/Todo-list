#include <iostream>
#include <string>
#include "Date.h"
using namespace std;


enum Status
{
    Done , NotDone
};


enum Olaviat
{
    Low , Medium , High
};

class Task 
{
    private:
        string Title;
        string Description;
        Status status;
        Olaviat olaviat;
        Date createdate;
        Date deadline;
        Date today;
    public:
        Task(string = "" , string = "" , Status = NotDone , Olaviat = Medium /* , Date , Date , Date */);
        void ToggleStatus();
        void display();
        bool isbackward();
};
Task ::  Task(string T  , string D , Status s , Olaviat o /* , Date c , Date d , Date t */)
{
    Title = T ;
    Description = D ;
    status = s ;
    olaviat = o ; 
};
void Task :: ToggleStatus()
{
    if(status == Done)
        status =NotDone;
    else
        status = Done;
};
void Task :: display()
{
    
};
bool Task :: isbackward()
{
    //return today > deadline;
};