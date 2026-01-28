CC = gcc
CXX = g++

CFLAGS = -Wall -g
CXXFLAGS = -Wall -g

all: hello hello_cpp

hello: hello.c
	 $(CC) $(CFLAGS) hello.c -o hello

hello_cpp: hello.cpp
	$(CXX) $(CXXFLAGS) hello.cpp -o hello_cpp

clean:
		rm -f hello hello_cpp
