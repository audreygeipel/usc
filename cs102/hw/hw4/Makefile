CC = g++
CFLAGS = -g -Wall
LDFLAGS =


all : table.o world.o main.o
	@echo ""
	@echo "Compiling and linking"
	$(CC) $(CFLAGS) table.o world.o main.o -o main

table.o : table.h table.cpp 
	$(CC) $(CFLAGS) -c table.h table.cpp

world.o : world.h world.cpp
	$(CC) $(CFLAGS) -c world.cpp

main.o : world.o main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f main *.o *~
	clear

again:
	rm -f main *.o *~
	clear
	make

