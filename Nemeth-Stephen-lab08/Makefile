CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors $(DEBUG)
LFLAGS = -Wall -pedantic-errors $(DEBUG)

compile: lab08.out

lab08.out: lab08.o Fraction.o
	$(CC) $(LFLAGS) -o lab08.out lab08.o  Fraction.o

lab08.o: lab08.cpp
	$(CC) $(CFLAGS) -c lab08.cpp

Fraction.o: Fraction.cpp Fraction.h
	$(CC) $(CFLAGS) -c Fraction.cpp

run: lab08.out
	./lab08.out

clean:
	rm *.o
	rm lab08.out

