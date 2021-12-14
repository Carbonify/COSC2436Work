#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "linkedList.h"

using namespace std;

void getAllStudentsFromFile (string filename, linkedList& list )
{

  istringstream inSS;

  ifstream input(filename);
  if (input.is_open())  {
    Student newStudent;
    while (input >> newStudent.name >> newStudent.id ) {
      list.insertLast(newStudent);
    }
  }
  else {
    cout << "Error! File not found." << endl;
  }
}


int main ( int argc, char **argv )
{
    linkedList roster;
    string file = "students.txt";

    getAllStudentsFromFile ( file, roster);
    roster.printList();

    roster.removeDuplicates ();
    cout << "--------\n";
    roster.printList();

    return 0;
}