CC=g++ -g
CFLGAS=-Wall -Werror -Wextra -Wno-unsed
BOOST_INCL=/usr/local/include
BOOST_LIB=/usr/local/lib

LDFLAGS=-L$(BOOST_LIB) -lboost_system -lpthread -lboost_thread

APP_NAME=client_server

OBJ=../obj
INCLUDE=../include
INCL=-I$(BOOST_INCL) -I$(INCLUDE)

OBJECTS= \
	$(OBJ)/IxI.o

all: vertex

$(OBJ)/%.o: %.cpp $(INCLUDE)/%.hpp
	$(CC) -c $(CFLAGS) $(INCL) $< -o $@

vertex: $(OBJECTS) vertex.cpp
	$(CC) $(CFLGAS) $(OBJECTS) $(INCL) $(LDFLAGS) vertex.cpp -o vertex

clean:
	rm -f $(OBJECTS) $(INCLUDE)/build_version.h ../obj/*.o client_server

build_version:
	rm -f $(INCLUDE)/build_version.h;echo "#define __APP_VERSION__  \"$(APP_NAME) - Revision `    svn info | grep Revision | sed     's/..* //'`\"  "  > $(INCLUDE)/build_version.h 
	
