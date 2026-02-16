#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>
#include <map>
#include "Date.h"

using namespace std;

enum Status 
{
    Done, NotDone 
};

enum Olaviat 
{ 
    Low, Medium, High 
};

extern map<int, string> statustostring;
extern map<int, string> olaviattostring;

vector<string> split(const string &, char );

class Task
{
protected:
    string Title;
    string Description;
    Status status;
    Olaviat olaviat;
    
    Date Createdate;
    Date Deadline;
    Date Today;

public:
    Task(string = "", string = "", Status = NotDone, int = 1,Date = Date(), Date = Date(), Date = Date());
    void SetTitle(string);
    void SetDescription(string);
    void Set_Status(Status);
    void Set_Olaviat(int);
    string GetTitle();
    string GetDescription();
    Status Get_Status();
    int Get_Olaviat();

    Date Get_CreateDate() const { return Createdate; }
    Date Get_Today() const { return Today; }
    Date Get_Deadline();

    void ToggleStatus();
    void Display();
    bool isbackward(const Date&) const;

    string Serialize() const;
    static Task Deserialize(const string &line);
};

#endif
