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
  firstBook = other.getFirstBook();
  lastBook = other.getLastBook();
  LibraryBook* current = other.getFirstBook();

  while(current->next) {
    addBook(current->book);
  }

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
void Library::moveToFront (LibraryBook *entry)
{
  // implement this function -done?
  if(firstBook) {
    firstBook->prev = entry;
    entry->next = firstBook->next;
    firstBook = entry;

  } else {
    firstBook = entry;
    lastBook = entry;
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
