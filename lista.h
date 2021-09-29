#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _LISTA_H
#define _LISTA_H

typedef struct Node{
    struct Node * prox;
    void * elemen;
    char id;
}node;

typedef struct List{
    node *first;
    node *last;
}list;

list * listInitialized();
node * nodeInitialized();
void push(char id,list * l, void * elem, int(*comp)(char, node *, node *));
void listSearch(list * l, int age, int(*cmpAge)(int age, void *elem, char id), void(*print)(char id, void *elem));
void pop(list *l, node * n);
void freeList(list *l);
void freeNode(node * n);
void printList(list *l, void(*print)(char id, void *elem));

#endif