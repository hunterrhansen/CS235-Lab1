#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <fstream>
#include <string>
#include "TodoListInterface.h"
#include <vector>

using namespace std;

class TodoList: public TodoListInterface {
  
  public: 
    vector <string> tasks;

    //Constructor - Runs when object is created
    TodoList() {
      cout << "In Constructor" << endl;
      ifstream infile ("TODOList.txt");
      string line;

      if (infile.is_open()) {
        while (getline(infile, line)) {
          cout << line << endl;
          tasks.push_back(line);
        }
        infile.close();
      }
    }    

    //Destructor - Runs when object is destroyed
    virtual ~TodoList() {
      cout << "In Destructor" << endl;
      ofstream outfile;
      outfile.open("TODOList.txt", ofstream::out | ofstream::trunc);
      for (int i = 0; i < tasks.size(); i++) {
        cout << tasks[i] << endl;
        outfile << tasks[i] << endl;
      }
      outfile.close();

    }  
     
     //Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"        
    virtual void add(string _duedate, string _task) {
      cout << "In add " << _duedate << " " << _task << endl;

      /* If you want to change the whitespace " - " you also need to change how you erase it in the printDaysTasks function as well */
      tasks.push_back(_duedate + " - " + _task);
    }
      
    //Removes an item from the todo list with the specified task name Returns 1 if it removes an item, 0 otherwise
    virtual int remove(string _task) {
      cout << "In remove " << _task << endl;

      for (int i = 0; i < tasks.size(); i++) {
        size_t found = tasks[i].find(_task);
        if (found != string::npos) {
          cout << "Task found!" << endl;
          tasks.erase(tasks.begin() + i);
          return 1;
        }
      }
      return 0;
    }    
      
    //Prints out the full todo list to the console
    virtual void printTodoList() {
      cout << "In list" << endl;

      for (int i = 0; i < tasks.size(); i++) {
        cout << "Task " << i + 1 << ": " << tasks[i] << endl;
      }
      cout << endl;
    }    
    
    //Prints out all items of a todo list with a particular due date (specified by _duedate)
    virtual void printDaysTasks(string _date) {
      cout << "In daystasks" << endl;

			//create vector
      vector <string> tempVec;
      
			//populate vector
      for (int i = 0; i < tasks.size(); i++) {
        size_t found = tasks[i].find(_date);
        if (found != string::npos) {
					//string* newTask = new tasks[i];
          tempVec.push_back(tasks[i]);
        }
      }

			//print days vector to console
      cout << _date << endl;
      for (int i = 0; i < tempVec.size(); i++) {
        size_t found = tempVec[i].find(_date);
        if (found != string::npos) {
          /*The 3 corresponds to the size of the white space we want to erase between the date and task when we originally added to the vector*/
          cout << "Task " << i + 1 << ": " << tempVec[i].erase(found, _date.length() + 3) << endl;
        }
      }

			//Deallocate the memory when you are done using it
			for (int i = 0; i < tempVec.size(); i++) {
				//delete tempVec.at(i);
				tempVec.erase(tempVec.begin() + i);
			}
		}
    
    };

    #endif