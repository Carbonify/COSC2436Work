CXX = g++
CXXFLAGS = -g -Wall -MMD
RELEASEFLAGS = -O3 -Wall
OBJECTS = client_type.o main.o server_list_type.o server_type.o update_waiting_queue_type.o
DEPENDS = ${OBJECTS:.o=.d}    # substitutes ".o" with ".d"
EXEC = queuesim                  # executable name

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

release: ${OBJECTS}
	g++ ${RELEASEFLAGS} ${OBJECTS} -o release


-include ${DEPENDS}

clean:
	-rm *.o *.d queuesim release
