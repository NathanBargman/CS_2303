all: HW3B

# Set CFLAGS to allow Debug and issue all warnings.
CFLAGS = -g -Wall

HW3B: HW3B.o mystruct.o tests.o production.o
	gcc $(CFLAGS) HW3B.o mystruct.o tests.o production.o -o HW3B

HW3B.o: HW3B.c mystruct.h tests.h production.h
	gcc $(CFLAGS) -c HW3B.c

tests.o: tests.c mystruct.h tests.h production.h
	gcc $(CFLAGS) -c tests.c
	
production.o: production.c mystruct.h
	gcc $(CFLAGS) -c production.c	

mystruct.o: mystruct.c mystruct.h
	gcc $(CFLAGS) -c mystruct.c

clean:
	rm -f *.o HW3B
	rm -f -r html latex

docs:
	doxygen
