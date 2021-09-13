#include "Library.h"
#include <iostream>

Library::Library() : firstBook(nullptr), lastBook(nullptr), numBooks(0)
{
}

//destructor
Library::~Library() {
  LibraryBook* current = lastBook;
  while(current) {
    delete current->next;
    current = current->prev;
  }
  delete current;
}

//Copy constructor
Library::Library(const Library& other) : firstBook(nullptr), lastBook(nullptr), numBooks(0)
{
  //  implement this function
  LibraryBook* current = other.getFirstBook();

  while(current) {
    addBook(current->book);
    current = current->next;
  }
}

int Library::getnumBooks() const
{
  return numBooks;
}

LibraryBook* Library::getFirstBook() const
{
  return firstBook;
}
LibraryBook* Library::getLastBook() const
{
  return lastBook;
}

// return a pointer to the n'th book in the linked list
LibraryBook* Library::getBook( const int pos ) const
{
  if (pos > numBooks || pos < 0) {
    cout << "Book at position " << pos << " not available." << endl;
    return nullptr;
  }
  LibraryBook* current = firstBook;
  for(int i = 0; i < pos; i++) {
    current = current->next;
  }
  return current;
}

// add a Book to the end of the linked list
void Library::addBook(const Book book)
{
  // implement this function -done
  LibraryBook* addedBook = new LibraryBook();
  // Set up newly added book based on provided book
  addedBook->book = book;

  if (lastBook) {
    addedBook->prev = lastBook;
    lastBook->next = addedBook;
    lastBook = addedBook;

  } else { // Add to empty list
    firstBook = addedBook;
    lastBook = addedBook;
  }
  numBooks++; //increment count of books in list

}


// Move a book to the front of the linked list
void Library::moveToFront (LibraryBook* oneToMove)
{
  // implement this function -done?
  LibraryBook* oneBefore = oneToMove->prev;
  LibraryBook* oneAfter = oneToMove->next;

  if(numBooks == 0) {
    firstBook = oneToMove;
    lastBook = oneToMove;
    return;
  }


  if(! oneBefore) { // already at front
    return;
  } else if (! oneAfter) { //moving last entry
    oneBefore->next = nullptr;
    oneToMove->prev = nullptr;
    oneToMove->next = firstBook;
    lastBook = oneBefore;
    firstBook = oneToMove;

  } else { //moving an entry in the middle

    oneAfter->prev = oneToMove->prev;
    oneBefore->next = oneToMove->next;

    oneToMove->next = firstBook;
    oneToMove->prev = nullptr;
    firstBook = oneToMove;
  }
}

// print all Books
void Library::printAllBooks() const
{
  LibraryBook* current = firstBook;
  while(current) {
    current->book.printBook();

    current = current->next;
  }
}

// print all Books of a single Genre
void Library::printBooksOfOneGenre(const string genre) const
{

  LibraryBook* current = firstBook;
  while(current) {
    if (current->book.getGenre() == genre) {
      current->book.printBook();
    }

    current = current->next;
  }
}
