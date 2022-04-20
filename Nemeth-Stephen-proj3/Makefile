CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors -c $(DEBUG)
LFLAGS = -Wall -pedantic-errors $(DEBUG)

compile: proj3.out

proj3.out: proj3.o Board.o Player.o HumanPlayer.o SimpleComputerPlayer.o
	$(CC) $(LFLAGS) -o proj3.out proj3.o Board.o Player.o HumanPlayer.o SimpleComputerPlayer.o

proj3.o: proj3.cpp Board.o Player.o HumanPlayer.o SimpleComputerPlayer.o
	$(CC) $(CFLAGS) proj3.cpp	

Board.o: Board.cpp Board.h
	$(CC) $(CFLAGS) Board.cpp

Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) Player.cpp

HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h
	$(CC) $(CFLAGS) HumanPlayer.cpp

SimpleComputerPlayer.o: SimpleComputerPlayer.cpp SimpleComputerPlayer.h
	$(CC) $(CFLAGS) SimpleComputerPlayer.cpp

run: proj3.out
	./proj3.out -h -h

clean:
	rm *.o
	rm *.out