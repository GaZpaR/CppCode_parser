CC              := g++
PROJPATH        := -I./
LIBPATH         := -L/
OPTS            := -Wextra -std=c++14

all: link

link: cppparser.o tree.o
	$(CC) $(PROJPATH) $(OPTS) cppparser.o tree.o -o parser

cppparser.o:cppparser.cpp
	$(CC) $(PROJPATH) $(OPTS) -c cppparser.cpp

tree.o:tree.cpp
	$(CC) $(PROJPATH) $(OPTS) -c tree.cpp

clear:
	rm -f *.o parser
	rm -f parser
