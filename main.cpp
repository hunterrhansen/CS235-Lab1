#include <iostream>
#include <fstream>
#include <string>
#include "TodoList.h"

using namespace std;

int main(int argc, char *argv[]) {
  TodoList mylist;
  string firstarg = argv[1];
  
  ofstream myfile;
  for (int i = 0; i < argc; i++) {
    cout << "argv[" << i << "]=" << argv[i] << endl;
  }
  cout << endl;

  if (firstarg.compare("add") == 0) {
    cout << "Doing an add..." << endl;

    string date = argv[2];
    string task = argv[3];
    
    cout << "date: " << date << " task: " << task << endl;
    mylist.add(date, task);

    cout << endl;
  }

  if (firstarg.compare("remove") == 0) {
    cout << "Doing a remove..." << endl;

    string task = argv[2];

    cout << "task: " << task << endl;
    mylist.remove(task);

    cout << endl;
  }

  if (firstarg.compare("printList") == 0) {
    cout << "Printing list..." << endl;

    mylist.printTodoList();

  }

  if (firstarg.compare("printDay") == 0) {
    cout << "Printing tasks in date..." << endl;
    
    string date = argv[2];

    cout << "date: " << date << endl;
    mylist.printDaysTasks(date);

    cout << endl;
  }
}