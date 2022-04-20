CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors $(DEBUG)
LFLAGS = -Wall $(DEBUG)

compile: lab06.out

lab06.out: lab06.cpp lab06.h
	$(CC) $(CFLAGS) -o lab06.out lab06.cpp

run: lab06.out
	./lab06.out

clean:
	rm lab06.out

