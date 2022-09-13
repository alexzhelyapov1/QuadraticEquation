all: test

test: clean SolveQuadraticEquation.o test.o main.o
	g++ SolveQuadraticEquation.o main.o test.o -o a.out -lm
	./a.out

clean:
	touch 1.o
	touch a.out
	rm *.o
	rm a.out

global: clean SolveQuadraticEquation.o main.o
	g++ SolveQuadraticEquation.o main.o -o a.out -lm
	./a.out

SolveQuadraticEquation.o: ./lib/SolveQuadraticEquation.cpp
	g++ -c -Wall -o SolveQuadraticEquation.o ./lib/SolveQuadraticEquation.cpp

main.o: main.cpp
	g++ -c -Wall -o main.o main.cpp

test.o: ./tests/test.cpp
	g++ -c -Wall -o test.o ./tests/test.cpp