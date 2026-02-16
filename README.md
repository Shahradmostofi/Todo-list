# TodoList (C++ Console Application)

A console-based Todo List manager written in modern C++.

This project allows users to manage tasks with priorities, deadlines, and status control through a simple interactive menu.

---

## Features

- Add new task
- Delete task by title
- Toggle task status (Done / NotDone)
- Display all tasks
- Display overdue (backward) tasks
- Sort tasks:
  - By Priority
  - By Deadline
  - By Priority + Deadline
- Save tasks to file
- Load tasks from file

---

## Project Structure

This project uses the following main classes:

- `TodoList`
- `Task`
- `Date`

Required files:
Todo-List.cpp
Task.h
Task.cpp
Date.h
Date.cpp
README.md


---

## How It Works

Each task contains:

- Title
- Description
- Status (Done / NotDone)
- Priority (1: Low, 2: Medium, 3: High)
- Create Date
- Deadline

Tasks are stored in a `vector<Task>` and sorted using `std::sort` with custom lambda functions.

---

## Build & Run

### Using g++ (Linux / macOS / MinGW)

Make sure all `.cpp` files are in the same directory.

Compile:

```bash
g++ -std=c++17 main.cpp Task.cpp Date.cpp -o todo
Run:

./todo

Windows (MinGW)
g++ -std=c++17 main.cpp Task.cpp Date.cpp -o todo.exe
todo.exe

Menu Options
After running, the application displays:

1. Add New Task
2. Delete Task
3. Toggle Task Status
4. Show All Tasks
5. Show Backward Tasks
6. Sort By Priority
7. Sort By Deadline
8. Sort By Priority & Deadline
9. Load from file
10. Save to file
0. Exit

Save & Load

Tasks are saved as text using:

Task::Serialize()

Deserialize(string)

When saving, the program automatically appends .txt to the filename.
Example:
If you enter:
tasks
File saved as:
tasks.txt




Design Notes:

Sorting is implemented using std::sort with lambda expressions.

Status toggling is handled inside the Task class.

Overdue detection compares task deadline with today's date.

File operations use <fstream>.

Future Improvements

Prevent duplicate task titles

Replace system("cls") with a cross-platform clear-screen solution

Add task IDs instead of searching by title

Improve file format robustness (e.g., JSON support)
