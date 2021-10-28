#include <iostream>
#include <fstream>
#include <sstream>

#include "Student.h"
#include "hashSet.h"

using namespace std;

void getAllStudentsFromFile (string filename, hashSet& myHashSet )
{

  istringstream inSS;

  ifstream input(filename);
  if (input.is_open())  {
    Student newStudent;
    while (input >> newStudent.name >> newStudent.id ) {
      myHashSet.insert(newStudent);
    }
  }
  else {
    cout << "Error! File not found." << endl;
  }
}


int main ( int argc, char **argv )
{
    hashSet table;
    string file = "students.txt";

    getAllStudentsFromFile ( file, table );

    return 0;
}