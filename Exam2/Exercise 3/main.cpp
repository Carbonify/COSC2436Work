#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>


#include "Student.h"
#include "Roster.h"

using namespace std;

void getAllStudentsFromFile (string filename, Roster& roster )
{
  	  
  istringstream inSS;

  ifstream input(filename);
  if (input.is_open())  {
    Student newStudent;
    while (input >> newStudent.name >> newStudent.id ) {            
      roster.addStudent(newStudent);
    }
  }
  else {
    cout << "Error! File not found." << endl;
  }
}


int main ( int argc, char **argv )
{
    Roster roster;
    string file = "students.txt";

    getAllStudentsFromFile ( file, roster);
      
    return 0;
}
