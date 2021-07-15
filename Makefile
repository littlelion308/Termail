#MAKEFILE for "Termail" Email Client


Termail : backend.o main.o
	g++ -lcurl main.o backend.o -o Termail
main.o : main.cpp
	g++ -c main.cpp
backend.o : backend.h backend.cpp
	g++ -c -lcurl backend.cpp
clean:
	rm -f Termail main.o backend.o
run: Termail
	./Termail
