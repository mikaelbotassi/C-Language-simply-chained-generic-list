CC=gcc
CFLAGS=-lm
FLAGS=-c -Wall -Wextra -Werror
OBJ=main.o lista.o people.o

all: $(OBJ)
	$(CC) $(OBJ) -o main $(CFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c $(CFLAGS)

lista.o: lista.c
	$(CC) $(FLAGS) lista.c $(CFLAGS)

people.o: people.c
	$(CC) $(FLAGS) people.c $(CFLAGS)

run:
	./main

clean:
	rm -f *.o main