#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "hashTable.h"

using namespace std;

void getAllPuppiesFromFile (string filename, hashTable& allPuppies )
{
  	  
  istringstream inSS;

  ifstream input(filename);
  if (input.is_open())  {
    Puppy newPuppy;
    while (input >> newPuppy.name >> newPuppy.breed >> newPuppy.age ) {            
      allPuppies.insert(newPuppy);
    }
  }
  else {
    cout << "Error! File not found." << endl;
  }
}


int main ( int argc, char **argv )
{
  string filename = "puppies.txt";

  int size=0;
  std::cin >> size;
   
  hashTable allPuppies(size);

  
  getAllPuppiesFromFile ( filename, allPuppies );

  allPuppies.printAll();
  
  return 0;
}
