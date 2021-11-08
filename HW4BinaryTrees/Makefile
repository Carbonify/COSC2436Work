CXX = g++
CXXFLAGS = -g -Wall -MMD
OBJECTS = BSTNode.o BSTree.o BSTUtils.o main.o
DEPENDS = ${OBJECTS:.o=.d}    # substitutes ".o" with ".d"
EXEC = binarytree

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}


-include ${DEPENDS}

clean:
	-rm *.o *.d binarytree

TAGS: binarytree
	unitags -eR *
