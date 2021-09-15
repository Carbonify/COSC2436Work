#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

#include "Book.h"
#include "Library.h"

using namespace std;

void readBooksFromFile (string filename, Library &library)
{
  ifstream input(filename);
  if (input.is_open())  {
    string title, author, publisher, genre;
    int year;
    while (input >> title >> author >> publisher >> genre >> year ) {
      Book newBook(title, author, publisher, genre, year);
      library.addBook(newBook);
    }
  }
  else {
    cout << "Error! File not found, using manual setup..." << endl;
    library.addBook(Book("MobyDick", "HermanMelville", "CreateSpaceIndependentPublishingPlatform", "Novel", 1851));
    library.addBook(Book("ComputerArchitecture", "JohnLHennessy", "MorganKaufmanPublishers", "TextBook", 2017));
    library.addBook(Book("Hamlet", "WilliamShakespeare", "IndependentPublishers", "Novel", 1600));
    library.addBook(Book("JurassicPark", "MichaelCrichton", "TurtlebackBooks", "ScienceFiction", 1990));
    library.addBook(Book("TheAdventuresOfHuckleberryFinn", "MarkTwain", "CreateSpaceIndependentPublishingPlatform", "Novel", 1884));
    library.addBook(Book("DataStructuresUsingC++", "D.S", "Malik", "CourseTechnologies", 2010));
    library.addBook(Book("ToTheLighthouse", "VirginiaWoolf", "HarcourtBraceJovanovich", "Novel", 1989));
    library.addBook(Book("Solaris", "StanislawLem", "Mariner", "ScienceFiction", 1961));
    library.addBook(Book("ProgrammingModelsForParallelComputing", "PavanBalaji", "MITPress", "TextBook", 2012));
    library.addBook(Book("TheMartian", "AndyWeir", "ThorndikePress", "ScienceFiction", 2015));
  }
}


int main ( int argc, char **argv)
{
  string filename = "books.txt";
  Library library;
  readBooksFromFile ( filename, library);
  int whatToDo = 0;

  if ( argc > 1 ) {
    whatToDo = std::atoi(argv[1]);
  }
  if ( whatToDo == 0 ) { //count numBooks test
    cout << "Number of books in library is : " << library.getnumBooks() << endl;
  }
  else if ( whatToDo == 1 ) { // get specific book
    LibraryBook *oneBook = library.getBook(4);
    cout << "Book no. 4 is ";
    oneBook->book.printBook();
  }
  else if ( whatToDo == 2 ) { //test genre print
    library.printBooksOfOneGenre("Novel");
  }
  else if ( whatToDo == 3 ) { //test full print
    library.printAllBooks();
  }
  else if ( whatToDo == 4 ) { //test move to front
    LibraryBook *oneBook = library.getBook(4);
    library.moveToFront(oneBook);
    library.printAllBooks();
  }
  else if ( whatToDo == 5 ) { //test copy constructor
    Library secondLibrary(library);
    secondLibrary.printAllBooks();
  }
  else if (whatToDo == 6) { //test removeBook
    cout << "Book to remove:" << endl;
    LibraryBook* removeCandidate = library.getBook(3);
    removeCandidate->book.printBook();
    cout << "Removing and printing..." << endl;
    library.removeBook(removeCandidate);
    library.printAllBooks();
  }
  else {
    cout << "Please provide an argument between 0 and 5\n";
  }
}
