#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include "Date.h"
#include "Task.h"
using namespace std;

class TodoList : public Task 
{
    public:
        TodoList(string = "" , string = "" , Status = NotDone , int = 1 , Date = Date() , Date = Date() , Date = Date(),string = "", string = "", Status = NotDone , int = 1 );
        vector <Task> tasks;
        void NewTask(Task );
        void DeleteTask(string ); 
        void toggletask(string ) ;
        void ShowAll();
        void D_NTasks();
        void Showbackward();
        void sortbyolaviat_Deadline();
        void sortbyolaviat();
        void sortbyDeadline();
        void printMenu();
        int getchoice();
        bool SaveToFile(const string & filename ) const;
        bool LoadFromFile(const string & filename);
};
TodoList :: TodoList (string T  , string D , Status S , int A , Date C , Date dd , Date t , string a , string b , Status c , int d) : Task(T,D,S,A,C,dd,t)
{
    SetTitle(a);
    SetDescription(b);
    Set_Status(c);
    Set_Olaviat(d);
}

void TodoList :: NewTask(Task t)
{

    tasks.push_back(t);
}
void TodoList :: DeleteTask(string s)
{
    for(int i=0 ; tasks.size() ; i++)
    {
        if(tasks[i].GetTitle()== s)
        {
            tasks.erase(tasks.begin() + i);
            break;
        }
    }
}
void TodoList :: toggletask(string s)
{
    for (Task &t : tasks) 
    {
        if(t.GetTitle() == s)
        {
            t.ToggleStatus();
            break;
        }
    }
}
void TodoList :: ShowAll()
{
    for(Task t : tasks)
    {
        t.Display();       
    }
}
void TodoList :: D_NTasks()
{
    cout<<"Done tasks is:";
    for(Task &t : tasks)
    {
        if(t.Get_Status() == Done)
        {
            t.Display();
        }
    }
    cout<<"NotDone tasks is:";
    for(Task &t : tasks)
    {
        if(t.Get_Status() == NotDone)
        {
            t.Display();
        }
    }
}
void TodoList :: Showbackward()
{
    int y,m,d;
    cout << "Enter today (y m d): ";
    cin >> y >> m >> d;
    cin.ignore(1000, '\n');

    Date today;
    today.setDate(y,m,d);

    for(Task &t : tasks)
        if(t.isbackward(today))
            t.Display();
}

// void TodoList :: bublesort()
// {
//     bool Flag = true;
//     for(int i=0; i<tasks.size()-1 && Flag; i++)
//     {   
//         Flag = false; 
//         for (int j = 0; j < tasks.size() - 1; j++)
//         {
//             if (tasks[j].getolaviat() > tasks[j + 1].getolaviat())
//             {
//                 int temp = tasks[j].getolaviat();
//                 tasks[j].setolaviat(tasks[j + 1].getolaviat());
//                 tasks[j + 1].setolaviat(temp);  
//                 Flag = true;
//             }
//         }
//     }
// }
void TodoList :: sortbyolaviat_Deadline()
{
    sort(tasks.begin() , tasks.end() , [](Task &a , Task &b)
    {
        if(a.Get_Olaviat() != b.Get_Olaviat())
            return a.Get_Olaviat() > b.Get_Olaviat();
        return a.Get_Deadline() < b.Get_Deadline();
    });
}
void TodoList :: sortbyolaviat()
{
    sort(tasks.begin() , tasks.end() , [](Task &a , Task &b)
    {
        return a.Get_Olaviat() > b.Get_Olaviat();
    });
}
void TodoList :: sortbyDeadline()
{
    sort(tasks.begin() , tasks.end() , [](Task &a , Task &b)
    {
        return a.Get_Deadline() < b.Get_Deadline();
    });
}
void TodoList :: printMenu()
{
    cout << "\n****** TodoList Menu ******\n-------------------------------------------------------------------------\n";
    cout << "1. Add New Task\n";
    cout << "2. Delete Task\n";
    cout << "3. Toggle Task Status\n";
    cout << "4. Show All Tasks\n";
    cout << "5. Show Backward Tasks\n";
    cout << "6. Sort By Priority\n";
    cout << "7. Sort By Deadline\n";
    cout << "8. Sort By Priority & Deadline\n";
    cout << "9. load from file\n";
    cout << "10. save to file\n";
    cout << "0. Exit\n-------------------------------------------------------------------------\n";
    cout << "Choose: ";
}
int TodoList :: getchoice()
{
    int c;
    cin>>c;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(1000 , '\n');
        cout<<"your choice is invalid!(Enter number:[0,10])";
        cin>>c;
    }
    cin.ignore(1000 , '\n');
    return c;
}


bool TodoList::SaveToFile(const string &filename) const
{
    ofstream out(filename);
    if(!out) return false;

    for(const Task &t : tasks)
        out << t.Serialize() << "\n";

    return true;
}

bool TodoList::LoadFromFile(const string &filename)
{
    ifstream in (filename);
    if(!in) return false;

    tasks.clear();

    string line;
    while(getline(in, line))
    {
        if(line.empty()) continue;
        tasks.push_back(Deserialize(line));
    }
    return true;
}


void runMenu(TodoList &T)
{
    int choice;
    do
    {
        T.printMenu();
        choice = T.getchoice();
        
        switch(choice)
        {
        case 1:
        {
            system("cls");
            cout<<"*** Add New Task ***\n";
            string title, desc;
            int ov;
            Date c, d, t;

            cout << "Title: ";
            getline(cin, title);

            cout << "Description: ";
            getline(cin, desc);

            cout << "olaviat (1:Low , 2:Medium , 3:High): ";
            cin >> ov;
            cin.ignore(1000, '\n');

            
            int y, m, day;
            cout << "Deadline (y m d): ";
            cin >> y >> m >> day;
            cin.ignore(1000, '\n');
            d.setDate(y, m, day);

            cout << "CreateDate (y m d): ";
            cin >> y >> m >> day;
            cin.ignore(1000, '\n');
            c.setDate(y, m, day);

            Task newTask(title, desc, NotDone, ov, c, d, c);
            T.NewTask(newTask);
            system("cls");
            cout << "Task added.\n";
            break;
        }

        case 2:
        {
            system("cls");
            cout<<"*** Delete Task ***\n";
            string title;
            cout << "Enter title to delete: ";
            getline(cin, title);
            T.DeleteTask(title);
            cout << "Deleted (if existed).\n";
            break;
        }

        case 3:
        {
            system("cls");
            cout<<"*** Toggle Task Status ***\n";
            string title;
            cout << "Enter title to toggle: ";
            getline(cin, title);
            T.toggletask(title);
            cout << "Toggled (if existed).\n";
            break;
        }
        case 4:
        {
            system("cls");
            cout<<"*** Show All Tasks ***\n";
            T.ShowAll();
            break;
        }
        case 5:
        {
            system("cls");
            cout<<"*** Show Backward Tasks ***\n";
            T.Showbackward();
            break;
        }
        case 6:
        {
            system("cls");
            cout<<"*** Sort By Priority(olaviat) ***\n";
            T.sortbyolaviat();
            cout << "Sorted by olaviat:\n";
            T.ShowAll();
            break;
        }
        case 7:
        {
            system("cls");
            cout<<"*** Sort By Deadline ***\n";
            T.sortbyDeadline();
            cout << "Sorted by deadline:\n";
            T.ShowAll();
            break;
        }
        case 8:
        {
            system("cls");
            cout<<"*** Sort By Priority & Deadline ***\n";
            T.sortbyolaviat_Deadline();
            cout <<"Sorted by olaviat & deadline:\n";
            T.ShowAll();
            break;
        }
        case 9:
        {
            system("cls");
            cout<<"*** load from file ***\n";
            string fname;
            cout << "Please Enter Filename to load: ";
            getline(cin, fname);
            if(T.LoadFromFile(fname))
            {
                cout << "Loaded.\n";
            }
            else
            {
                cout << "Cannot open file.\n";
            }

            break;
        }
        case 10:
        {
            system("cls");
            string fname;
            cout << "Filename to save: ";
            getline(cin, fname);
            if(T.SaveToFile(fname))
                cout << "Saved.\n";
            else   
                cout << "Cannot write file.\n";
            break;
        }

        case 0:
        {
            system("cls");
            cout << "GoodLuck.\n";
            break;
        }
        default:
            cout << "Invalid choice.\n";
        }

    } while(choice != 0);
}
int main()
{
    TodoList T1;
    runMenu(T1);
}