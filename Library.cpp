#include "Library.h"
#include <iostream>

Library::Library()
{
    numBooks = 0;
    firstBook = nullptr;
    lastBook = nullptr;
}

//Copy constructor
Library::Library( Library& other)
{
   //  implement this function
}

int Library::getnumBooks() const
{
    return numBooks;
}

LibraryBook* Library::getFirstBook()
{
   return firstBook;
}
LibraryBook* Library::getLastBook()
{
   return lastBook;
}

// return a pointer to the n'th book in the linked list
LibraryBook* Library::getBook( const int pos )
{
  // implement this function
}

// add a Book to the end of the linked list
void Library::addBook(Book book)
{
   // implement this function
}


// Move a book to the front of the linked list
void Library::moveToFront (LibraryBook *entry)
{
   // implement this function
}

// print all Books
void Library::printAllBooks() const
{
   // implement this function
}

// print all Books of a single Genre
void Library::printBooksOfOneGenre(string genre)
{
   // implement this function
}
