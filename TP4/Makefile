CC=gcc
CFLAGS=-Wall -ansi
OBJ=exo1.o stack.o
exe : $(OBJ)
	$(CC) -o exe $(OBJ) $(CFLAGS)

stack.o : stack.h
	$(CC) -c stack.c $(CFLAGS)

exo1.o : exo1.c stack.h
	$(CC) -c exo1.c $(CFLAGS)