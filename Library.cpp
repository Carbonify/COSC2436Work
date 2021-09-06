#include "Library.h"
#include <iostream>

Library::Library()
{
  numBooks = 0;
  firstBook = nullptr;
  lastBook = nullptr;
}

//Copy constructor
Library::Library(Library& other)
{
  //  implement this function
  //firstBook = other.getFirstBook();
  //lastBook = other.getLastBook();
  LibraryBook* current = other.getFirstBook();

  while(current) {

    Book nextBook = Book(current->book);
    cout << "Next book to add: ";
    nextBook.printBook();
    cout << endl;
    addBook(nextBook);
    //cout<< "book added." << endl;

    current = current->next;
  }

  printAllBooks();

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
void Library::moveToFront (LibraryBook *oneToMove)
{
  // implement this function -done?
  LibraryBook* oneBefore = oneToMove->prev;
  LibraryBook* oneAfter = oneToMove->next;


  if(firstBook) {
    if(oneToMove == firstBook) return; //do nothing if already first

    oneAfter->prev = oneToMove->prev;
    oneBefore->next = oneToMove->next;
    oneToMove->next = firstBook;
    oneToMove->prev = nullptr;
    firstBook = oneToMove;

  } else {
    firstBook = oneToMove;
    lastBook = oneToMove;
  }
}

// print all Books
void Library::printAllBooks() const
{
  // implement this function -done
  LibraryBook* current = firstBook;
  do {
    current->book.printBook();

    current = current->next;
  } while(current);
}

// print all Books of a single Genre
void Library::printBooksOfOneGenre(const string genre)
{
  // implement this function
  LibraryBook* current = firstBook;
  do {
    if (current->book.getGenre() == genre) {
      current->book.printBook();
    }

    current = current->next;
  } while(current->next);
}
