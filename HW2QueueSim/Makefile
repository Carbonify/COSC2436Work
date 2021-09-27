CPPFLAGS=-g -Wall
OBJECTS=main.o client_type.o server_list_type.o server_type.o update_waiting_queue_type.o

queuesim: $(OBJECTS)
	g++ $(CPPFLAGS)  $(OBJECTS) -o $@

client_type.o: client_type.h  client_type.cpp
	g++ $(CPPFLAGS) -c client_type.cpp

main.o: client_type.h server_list_type.h waiting_client_queue_type.h main.cpp
	g++ $(CPPFLAGS) -c main.cpp

server_list_type.o: server_list_type.h server_list_type.cpp
	g++ $(CPPFLAGS) -c server_list_type.cpp

server_type.o: server_type.h client_type.h server_type.cpp
	g++ $(CPPFLAGS) -c server_type.cpp

update_waiting_queue_type.o: waiting_client_queue_type.h queue_type.h update_waiting_queue_type.cpp
	g++ $(CPPFLAGS) -c update_waiting_queue_type.cpp

TAGS:
	unitags -eR *

clean:
	rm *.o queuesim
