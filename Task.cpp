#include <iostream>
#include <sstream>
#include "Task.h"

using namespace std;

map<int,string> statustostring {{0,"Done"} , {1,"NotDone"}};
map<int,string> olaviattostring {{0,"Low"},{1,"Medium"},{2,"High"}};

vector<string> split(const string &s, char delim)
{
    vector<string> parts;
    string part;
    for(char ch : s)
    {
        if(ch == delim)
        {
            parts.push_back(part);
            part.clear();
        }
        else part += ch;
    }
    parts.push_back(part);
    return parts;
}

Task::Task(string T, string D, Status s, int a, Date c, Date d, Date t)
{
    SetTitle(T);
    SetDescription(D);
    Set_Status(s);
    Set_Olaviat(a);
    Createdate = c;
    Deadline = d;
    Today = t;
}

void Task::SetTitle(string T){ Title = T; }
void Task::SetDescription(string D){ Description = D; }
void Task::Set_Status(Status s){ status = s; }

void Task::Set_Olaviat(int a)
{
    switch (a)
    {
    case 1: olaviat = Low; break;
    case 2: olaviat = Medium; break;
    case 3: olaviat = High; break;
    default: olaviat = Low; break;
    }
}

string Task::GetTitle(){ return Title; }
string Task::GetDescription(){ return Description; }
Status Task::Get_Status(){ return status; }
int Task::Get_Olaviat(){ return (int)olaviat; } // چک شود
Date Task::Get_Deadline(){ return Deadline; }

void Task::ToggleStatus()
{
    status = (status == Done) ? NotDone : Done;
}

void Task::Display()
{
    cout << "Title:" << Title << "\n";
    cout << "Description:" << Description << "\n";
    cout << "CreateDate:" << Createdate << "\t" << "Deadline: " << Deadline << "\n";
    cout << "olaviat:" << olaviattostring[olaviat] << "\n";
    cout << "status:" << statustostring[status] << "\n";
}

bool Task::isbackward(const Date& today) const
{
    return today > Deadline;
}

string Task::Serialize() const
{
    string line;
    line += Title + "|";
    line += Description +"|";
    line += to_string((int)status)+ "|";
    line += to_string((int)olaviat)+ "|";
    line += to_string(Createdate.getYear())+ " "+ to_string(Createdate.getMonth())+" "+ to_string(Createdate.getDay()) + "|";
    line += to_string(Deadline.getYear())+ " "+ to_string(Deadline.getMonth())+ " " + to_string(Deadline.getDay()) + "|";
    line += to_string(Today.getYear())+ " "+ to_string(Today.getMonth())+ " " + to_string(Today.getDay());
    return line;
}

Task Task::Deserialize(const string &line)
{
    vector<string> p = split(line, '|');
    if(p.size() != 7) return Task();

    string title = p[0];
    string desc = p[1];
    Status status = (Status)stoi(p[2]);
    int olaviat= stoi(p[3]);
    int prInput = olaviat + 1;

    auto parseDate = [](const string &s)->Date
    {
        int y,m,d;
        stringstream ss(s);
        ss >> y >> m >> d;
        Date dt;
        dt.setDate(y,m,d);
        return dt;
    };

    Date c = parseDate(p[4]);
    Date d = parseDate(p[5]);
    Date t = parseDate(p[6]);

    return Task(title, desc, status, prInput, c, d, t);
}