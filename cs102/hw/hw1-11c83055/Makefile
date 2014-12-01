CC = g++
CFLAGS = -g -Wall
LDFLAGS =


all : game.o database.o cli.o main.o
	@echo "Video game database"
	@echo "Compiling and linking"
	$(CC) $(CFLAGS) game.o database.o cli.o main.o -o main

game.o : game.h game.cpp
	$(CC) $(CFLAGS) -c game.cpp

cli.o : cli.h cli.cpp
	$(CC) $(CFLAGS) -c cli.cpp

database.o : database.h database.cpp
	$(CC) $(CFLAGS) -c database.cpp

main.o : game.o database.o cli.o main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f main *.o *~
	clear
	
again:
	rm -f main *.o *~
	clear
	make
