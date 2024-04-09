CC=g++
CFLAGS=-std=c++14 -c -Wall

all:person colors

person:person.o
	$(CC) person.o -o person

colors:colors.o
	$(CC) colors.o -o colors


person.o: person.cc
	$(CC) $(CFLAGS) person.cc

colors.o: colors.cc
	$(CC) $(CFLAGS) colors.cc


clean:
	rm -rf colors person *.o