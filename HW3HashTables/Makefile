CXX = g++
CXXFLAGS = -g -Wall -MMD
RELEASEFLAGS = -O3 -Wall
OBJECTS =
DEPENDS = ${OBJECTS:.o=.d}    # substitutes ".o" with ".d"
EXEC = hashtable

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

release: ${OBJECTS}
	g++ ${RELEASEFLAGS} ${OBJECTS} -o release


-include ${DEPENDS}

clean:
	-rm *.o *.d hashtable release

TAGS: hashtable
	unitags -eR *
