CXX = g++
CXXFLAGS = -g -Wall -MMD
OBJECTS = BSTNode.cpp BSTree.cpp BSTUtils.cpp main.cpp
DEPENDS = ${OBJECTS:.o=.d}    # substitutes ".o" with ".d"
EXEC = binarytree

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}


-include ${DEPENDS}

clean:
	-rm *.o *.d binarytree

TAGS: hashtable
	unitags -eR *
