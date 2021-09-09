#include "Library.h"
#include <iostream>

Library::Library() : firstBook(nullptr), lastBook(nullptr), numBooks(0)
{
}

//Copy constructor
Library::Library(const Library& other) : firstBook(nullptr), lastBook(nullptr), numBooks(0)
{
  //  implement this function
  LibraryBook* current = other.getFirstBook();

  while(current) {

    Book nextBook = Book(current->book);
    addBook(nextBook);

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
  // implement this function -done
  LibraryBook* current = firstBook;
  for(int i = 0; i < pos; i++) {
    if (current->next) {
      current = current->next;
    } else {
      cout << "Book at position " << pos << " not available." << endl;
      return nullptr;
    }
  }
  return current;
}

// add a Book to the end of the linked list
void Library::addBook(const Book book)
{
  // implement this function -done
  LibraryBook* addedBook = new LibraryBook();
  // Set up newly added book based on provided book
  addedBook->book = Book(book.getTitle(), book.getAuthor(), book.getPublisher(), book.getGenre(), book.getYear());

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
  do {
    current->book.printBook();

    current = current->next;
  } while(current);
}

// print all Books of a single Genre
void Library::printBooksOfOneGenre(const string genre) const
{

  if (! firstBook) { //empty list
    return;
  }

  LibraryBook* current = firstBook;
  do {
    if (current->book.getGenre() == genre) {
      current->book.printBook();
    }

    current = current->next;
  } while(current->next);
}
