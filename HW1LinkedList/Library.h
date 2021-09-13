#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "LibraryBook.h"

using namespace std;

class Library
{
private:
  LibraryBook* firstBook;
  LibraryBook* lastBook;
  int numBooks;

public:
  Library();
  Library(const Library& other);
  ~Library();

  int getnumBooks() const;
  LibraryBook *getBook( const int pos ) const;
  LibraryBook *getFirstBook () const;
  LibraryBook *getLastBook() const;

  // add a Book to the library
  void addBook(const Book book);

  // Move a book to the front
  void moveToFront (LibraryBook *entry);

  // print all Books
  void printAllBooks() const;

  // print all Books of a single Genre
  void printBooksOfOneGenre(const string genre) const;

};
#endif // LIBRARY_H
