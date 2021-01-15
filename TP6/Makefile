CC=gcc
CFLAGS= -Wall -ansi
LDFLAGS=
EXEC=main
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

run:
	./$(EXEC)

clean:
	rm -f *.o core
	rm -f $(EXEC)