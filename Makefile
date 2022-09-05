all: global

global: SolveQuadraticEquation.o main.o
	gcc SolveQuadraticEquation.o main.o -o a.out -lm
	./a.out

SolveQuadraticEquation.o: SolveQuadraticEquation.cpp
	gcc -c -Wall -o SolveQuadraticEquation.o SolveQuadraticEquation.cpp

main.o: main.cpp
	gcc -c -Wall -o main.o main.cpp