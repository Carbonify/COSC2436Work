all:
	g++ main.cpp Book.cpp Library.cpp -Wall -o librarylist

tags:
	unitags -eR *
