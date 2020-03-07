# Makefile for substituiting the high level standard library
#
# type 
# make main OR make main1 or make all (para compilar os dois)
#
# define the compiler as a variable
CC = cc -Wall

all : main main1

soio.o: soio.c soio.h
	$(CC) -c soio.c -o soio.o

main.o: main.c soio.h
	$(CC) -c main.c

main1.o: main1.c soio.h
	$(CC) -c main1.c

main: main.o soio.o soio.h
	$(CC) -o main main.o soio.o

main1: main1.o soio.o soio.h
	$(CC) -o main1 main1.o soio.o

#para remover todos os ficheiros executaveis e temporarios : type
#make clean

clean :
	rm -f *.o *~ main main1

