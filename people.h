#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#ifndef _PEOPLE_H
#define _PEOPLE_H

typedef struct People{
    char name[50];
    int age;
    float height;
    float feet;
}people;

void start(list *l);
people * peopleInitialized();
void peopleInsert(list * l);
int cmp(char id, node * n1, node *n2);
void peopleSearch(list *l);
int compareAges(int age, void * elem, char id);
void printPeople(char id, void *elem);
void printAllList(list *l);

#endif