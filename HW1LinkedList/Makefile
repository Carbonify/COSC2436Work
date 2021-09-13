CPPFLAGS=-g -Wall

librarylist: main.o Library.o Book.o TAGS
	g++ $(CPPFLAGS) main.o Library.o Book.o -o librarylist

main.o: Book.h Library.h
	g++ $(CPPFLAGS) -c main.cpp

Library.o: Library.h
	g++ $(CPPFLAGS) -c Library.cpp

Book.o: Book.h
	g++ $(CPPFLAGS) -c Book.cpp


TAGS:
	unitags -eR *
