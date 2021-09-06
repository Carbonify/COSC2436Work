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
  if ( whatToDo == 0 ) {
    cout << "Number of books in library is : " << library.getnumBooks() << endl;
  }
  else if ( whatToDo == 1 ) {
    LibraryBook *oneBook = library.getBook(4);
    cout << "Book no. 4 is ";
    oneBook->book.printBook();
  }
  else if ( whatToDo == 2 ) {
    library.printBooksOfOneGenre("Novel");
  }
  else if ( whatToDo == 3 ) {
    library.printAllBooks();
  }
  else if ( whatToDo == 4 ) {
    LibraryBook *oneBook = library.getBook(4);
    library.moveToFront(oneBook);
    library.printAllBooks();
  }
  else if ( whatToDo == 5 ) {
    Library secondLibrary(library);
    secondLibrary.printAllBooks();
  }
  else if (whatToDo == 6) {
    Library manualTest;
    cout << "Initial setup" << endl;
    manualTest.addBook(Book("First title", "jack", "clearing house", "fantasy", 3200));
    manualTest.addBook(Book("Second title", "penny", "generic", "nonfiction", 1000));
    manualTest.addBook(Book("Third title", "william", "theory", "sci fi", 1900));

    manualTest.printAllBooks();
    cout << "moving second book to first" << endl;
    manualTest.moveToFront(manualTest.getBook(1));
    cout << "book moved" << endl;

    manualTest.printAllBooks();


  }
  else {
    cout << "Please provide an argument between 0 and 5\n";
  }
}
