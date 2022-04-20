compile: main.out

main.out: main.o Test.o
	g++ -g -o main.out main.o
main.o: main.cpp Test.h
	g++ -c main.cpp
Test.o: Test.cpp Test.h
	g++ -c Test.cpp
run:
	./main.out
clean:
	rm *.o
	rm *.out
