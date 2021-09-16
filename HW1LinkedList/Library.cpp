#include "Library.h"
#include <iostream>

Library::Library() : firstBook(nullptr), lastBook(nullptr), numBooks(0)
{
}


Library::~Library() {
  LibraryBook* current = lastBook;
  while(current) {
    delete current->next;
    //iterating backwards through the list so we can delete without losing access to anything
    current = current->prev;
  }
  delete current;
}

Library::Library(const Library& other) : firstBook(nullptr), lastBook(nullptr), numBooks(0)
{
    LibraryBook* current = other.getFirstBook();

  while(current) {
    addBook(current->book); //addBook handles node creation and pointer linking
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
  if (pos > numBooks || pos < 0) { //must provide valid position
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

  LibraryBook* addedBook = new LibraryBook();
  // Set up newly added node based on provided book
  addedBook->book = book;

  if (lastBook) { //Add to list with entries existing
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
  // pointers for clarity purposes, avoids having to double-dereference
  LibraryBook* oneBefore = oneToMove->prev;
  LibraryBook* oneAfter = oneToMove->next;

  if(numBooks == 0) { //empty list
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

//Remove a book from the list
void Library::removeBook(LibraryBook* entry) {
  LibraryBook* oneBefore = entry->prev;
  LibraryBook* oneAfter = entry->next;

  if (numBooks < 2) { // single item in list, or empty
    firstBook = nullptr;
    lastBook = nullptr;
    delete entry; //if empty list, this just deletes nullptr
    numBooks = 0;
    return;
  }

  if(!oneBefore) { //removing head
    firstBook = oneAfter;
    oneAfter->prev = nullptr;
    delete entry;
  } else if (!oneAfter) { //deleting tail
    lastBook = oneBefore;
    oneBefore->next = nullptr;
    delete entry;
  } else { //deleting middle entry
    oneBefore->next = oneAfter;
    oneAfter->prev = oneBefore;
    delete entry;
  }
  numBooks--;
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
