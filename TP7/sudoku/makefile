CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=
OBJ=sudoku.o main.o in_out.o affichage.o

sudoku: $(OBJ)
	$(CC) -o sudoku $(OBJ) $(CFLAGS) $(shell pkg-config --libs-only-l MLV)

main.o: main.c sudoku.h in_out.h affichage.h
	$(CC) -c main.c $(CFLAGS)

affichage.o : affichage.c affichage.h sudoku.h
	$(CC) -c affichage.c $(CFLAGS)

sudoku.o: sudoku.c sudoku.h
	$(CC) -c sudoku.c $(CFLAGS)

in_out.o: in_out.c in_out.h
	$(CC) -c in_out.c $(CFLAGS)

clean: 
	rm -f *.o
	rm -f *~
	rm -f sudoku
