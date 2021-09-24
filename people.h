#include "lista.h"
#ifndef _PEOPLE_H
#define _PEOPLE_H

typedef struct People{
    char name[50];
    int age;
    float height;
    float feet;
}people;

void peopleInitialized();
void peopleInsert(people * p, list * l);
void peopleData(list * l);
int cmp(char id, node * n1, node *n2);
void peopleSearch(list *l);
int compareAges(int age, void * elem, char id);
void printPeople(char id, void *elem);

#endif;