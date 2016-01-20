CC              := g++
PROJPATH        := -I./
LIBPATH         := -L/
OPTS            := -Wextra -std=c++14

all: link

link: cppparser.o graph.o
	$(CC) $(PROJPATH) $(OPTS) cppparser.o graph.o -o parser

cppparser.o:cppparser.cpp
	$(CC) $(PROJPATH) $(OPTS) -c cppparser.cpp

graph.o:graph.cpp
	$(CC) $(PROJPATH) $(OPTS) -c graph.cpp

clear:
	rm -f *.o parser
	rm -f parser
