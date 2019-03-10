CC = g++
CPP_FLAGS = -std=c++11 -Wall -pedantic -ansi -Iinclude

all: ls1ex1

ls1ex1: ls1ex1.o
	$(CC) -o  ls1ex1 ls1ex1.o $(CPP_FLAGS)

ls1ex1.o:
	$(CC) -o ls1ex1.o ls1ex1.cpp -c $(CPP_FLAGS)

clean:
	rm -rf *.o ls1ex1 
