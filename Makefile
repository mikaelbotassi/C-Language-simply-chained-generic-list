CC = gcc
flags = -c -Wall
CFLAGS = -lm
ARQUIVOS = *.o
OBJS = lista.o people.o main.o
EXE = main
MAIN = main.c

all: lista.o people.o main.o
	$(CC) $(OBJS) -o $(EXE)

main.o: main.c
	$(CC) $(flags) $(MAIN) $(CFLAGS)

lista.o: lista.c
	$(CC) $(flags) lista.c $(CFLAGS)

people.o: people.c
	$(CC) $(flags) people.c $(CFLAGS)

run:
	./main

listar:
	ls $(ARQUIVOS)

clean:
	rm -f *.o
	rm -f $(EXE)