#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#ifndef _PEOPLE_H
#define _PEOPLE_H

typedef struct Aluno{
    int matricula;
    char nome[31];
    int nota;
}aluno;

void start(list *l);
aluno * allocAluno();
void insertAluno(list * l);
int descobreTipo(char id);
int cmp(char id, node * n1, node *n2);
void alunoSearch(list *l);
int matriculacompare(int matricula, void * elem, char id);
void printAluno(char id, void *elem);
void printAllList(list *l);

#endif