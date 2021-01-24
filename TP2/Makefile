CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=$1

all: $(EXEC)

$(EXEC): $(EXEC).o
		$(CC) -o $@ $^ $(LDFLAGS)

$(EXEC).o: $(EXEC).c
		$(CC) -o $@ -c $^ $(CFLAGS)

clean:
		rm -rf *.o

mrproper: clean
		rm -rf $(EXEC)