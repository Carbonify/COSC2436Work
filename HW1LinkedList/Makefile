CPPFLAGS=-g -Wall

librarylist: main.o Library.o Book.o
	g++ $(CPPFLAGS) main.o Library.o Book.o -o librarylist


main.o: Book.h Library.h main.cpp
	g++ $(CPPFLAGS) -c main.cpp

Library.o: Library.h Library.cpp
	g++ $(CPPFLAGS) -c Library.cpp

Book.o: Book.h Book.cpp
	g++ $(CPPFLAGS) -c Book.cpp

TAGS:
	unitags -eR *
