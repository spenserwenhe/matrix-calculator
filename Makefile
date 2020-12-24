output: main.o matrix.o
	g++ main.o matrix.o -o main

main.o: main.cpp
	g++ -c main.cpp

matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp

clean:
	rm *.o main