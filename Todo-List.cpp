#include <iostream>
#include <string>
#include <vector>
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
        Olaviat olaviat;    
        Date createdate;
        Date deadline;
        Date today;

    protected: 
        Status status;
        
    public:
        Task(string = "" , string = "" , Status = NotDone , int = 1 , Date , Date , Date );
        void setTitle(string );
        void setDescription(string );
        void setolaviat(int );
        void setstatus(Status );
        string getTitle();
        string getDescription();
        int getolaviat();
        Status getstatus();
        void ToggleStatus();
        void display();
        bool isbackward();
    };
    Task ::  Task(string T  , string D , Status s , int a  , Date c , Date d , Date t )
    {
        setTitle(T) ;
        setDescription(D) ;
        setstatus(s);
        setolaviat(a); 
        createdate = c ;
        deadline = d ; 
        today = t ;
    };
void Task :: setTitle(string T)
{
    cin>>T;
    this -> Title = T;
}
void Task :: setDescription(string D)
{
    getline(cin , D);
    this -> Description = D;
}
void Task :: setolaviat(int a)
{
    switch (a)
    {
    case 1:
        olaviat = Low;
        break;
    case 2:
        olaviat = Medium;
        break;
    case 3:
        olaviat = High;
        break;
    default:
        olaviat = Low;
        break;
    }
}
void Task :: setstatus(Status s)
{
    this -> status = s;
}
string Task :: getTitle()
{
    return Title;
}
string Task :: getDescription()
{
    return Description;
}
int Task :: getolaviat()
{
    return olaviat;
}
Status Task :: getstatus()
{
    return status;
}
void Task :: ToggleStatus()
{
    if(status == Done)
        status = NotDone;
    else
        status = Done;
};
void Task :: display()
{
    cout<<"***Title:"<<Title<<"***\n"<<"Description:"<<Description<<"\n"<<"olaviat:"<<olaviat<<"\t"<<"status:"<<status<<"\n";
};
bool Task :: isbackward()
{
    return today > deadline;
};


class TodoList : public Task 
{
    private: 
        vector <Task> tasks;
    public:
        void NewTask(Task );
        void DeleteTask(string ); 
        void toggletask(string ) ;
        void ShowAll();
        void D_NTasks();
        void Showbackward();
};
void TodoList :: NewTask(Task t)
{
    tasks.push_back(t);
}
void TodoList :: DeleteTask(string s)
{
    for(int i=0 ; tasks.size() ; i++)
    {
        if(tasks[i].getTitle()== s)
        {
            tasks.erase(tasks.begin() + i);
            break;
        }
    }
}
void TodoList :: toggletask(string s)
{
    for (int i=0 ; i<tasks.size() ; i++) 
    {
        if(tasks[i].getTitle() == s)
        {
            tasks[i].ToggleStatus();
            break;
        }
    }
}
void TodoList :: ShowAll()
{
    for(Task t : tasks)
    {
        t.display();       
    }
}
void TodoList :: D_NTasks()
{
    cout<<"Done tasks is:";
    for(Task t : tasks)
    {
        if(t.getstatus() == Done)
        {
            t.display();
        }
        else
        {
            cout<<"NotDone tasks is:";
            t.display();
        }
    }
}
void TodoList :: Showbackward()
{
    for(Task t : tasks)
    {
        if(t.isbackward())
        {
            t.display();
        }
    }
}