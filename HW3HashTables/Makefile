CXX = g++
CXXFLAGS = -g -Wall -MMD
OBJECTS = main.o HashTable.o
DEPENDS = ${OBJECTS:.o=.d}    # substitutes ".o" with ".d"
EXEC = hashtable

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}


-include ${DEPENDS}

clean:
	-rm *.o *.d hashtable release

TAGS: hashtable
	unitags -eR *
