CC              := g++
PROJPATH        := -I./
LIBPATH         := -L/
OPTS            := -Wextra -std=c++14

all: parser

parser:
	$(CC) $(PROJPATH) $(OPTS) -o parser cppparser.cpp

clear:
	rm -f *.o parser
	rm -f parser