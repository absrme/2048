CC=g++ #compilateur utilisé
CXXGLAGS= -pedantic -std=c++17 -lncurses #options de compilation CXX pour cpp
EXEC=2048 #nom des exécutables

all: $(EXEC) #regroupe exécutables à produire

2048 : 2048.o main.o
	$(CC) 2048.o main.o -o 2048 -lsfml-graphics -lsfml-window -lsfml-system

2048.o : 2048.cpp
	$(CC) -c 2048.cpp -o 2048.o $(CXXGLAGS)

main.o: main.cpp 2048.hpp
	$(CC) -c main.cpp -o main.o $(CXXGLAGS)

clean:
	rm -rf *.o

