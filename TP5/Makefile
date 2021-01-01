CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=main.o

run :  clean main
	./main

user : clean main
	./main -u

main : $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS)

main.o : main.c 
	$(CC) -c main.c $(CFLAGS)

clean :
	rm -f *.o
	rm -f main
	rm -f *~
