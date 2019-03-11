# Makefile for HW3starter

CFLAGS = -g -Wall

all: HW3A

HW3A: HW3A.o tests.o production.o mystring.o
	gcc $(CFLAGS) HW3A.o tests.o production.o mystring.o -o HW3A

HW3A.o: HW3A.c production.h tests.h
	gcc $(CFLAGS) -c HW3A.c

tests.o: tests.c production.h tests.h mystring.h
	gcc $(CFLAGS) -c tests.c

production.o: production.c production.h mystring.h
	gcc $(CFLAGS) -c production.c

mystring.o: mystring.c mystring.h
	gcc $(CFLAGS) -c mystring.c

clean:
	rm -r -f *.o HW3A html latex

docs:
	doxygen
