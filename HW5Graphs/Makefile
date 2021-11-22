CXX = g++
CXXFLAGS = -g -Wall -MMD
OBJECTS = main.o
DEPENDS = ${OBJECTS:.o=.d}    # substitutes ".o" with ".d"
EXEC = graph

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}


-include ${DEPENDS}

clean:
	-rm *.o *.d graph

TAGS: graph
	unitags -eR *
