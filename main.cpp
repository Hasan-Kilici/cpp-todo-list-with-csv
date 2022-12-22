#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;
bool status;

struct task {
  int id;
  int userid;
  string task;
};

void addTaskToCSV(const string& filename, const task& newTask) {
  ofstream file(filename, ios::app);
  file << newTask.id << "," << newTask.userid << "," << newTask.task << endl;
  file.close();
}

int main() {
  int command;
  
  while (true) {
    cout << "Komut giriniz";
    cin >> command;
    cin.ignore(); 
    switch (command) {
      case 1:{
        ifstream file("tasks.csv");
        string line;
        vector<task> tasks;

        while (getline(file, line)) {
          stringstream lineStream(line);
          string cell;
          task task;
          int i = 0;
          while (getline(lineStream, cell, ',')) {
            if (i == 0) {
              task.id = stoi(cell);
            } else if (i == 1) {
              task.userid = stoi(cell);
            } else if (i == 2) {
              task.task = cell;
            }
            ++i;
          }
          tasks.push_back(task);
        }
        for (const auto& task : tasks) {
          cout << task.task << endl;
        }
        break;
        }
      case 2:
       string cintask;
       cout << "Ne yapacaksın?";
       getline(cin, cintask);
       task newTask;
       newTask.id = 123;
       newTask.userid = 456;
       newTask.task = cintask;

       addTaskToCSV("tasks.csv", newTask);
       return 0;
       break;
      defult:
      cout << "Komut giriniz";
      cin >> command;
      break;
    }
  }
}

