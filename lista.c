#include "people.h"

//Função para Iniciar a lista e atribuir um NULL pra o primeiro e ultimo nó;
list * listInitialized(){
    list *l= (list *)malloc(sizeof(list));
    l->first=NULL;
    l->last=NULL;
    return l;
}

node * nodeInitialized(){
    node *n= (node *)malloc(sizeof(node));
    n->elemen=NULL;
    n->prox=NULL;
    n->id="\0";
}

void chainElement(node * current, node * prev, node *newNode, int(*comp)(char, node *, node *)){
    while(comp(newNode->id, newNode, current)==0){
        prev=current;
        current=prev->prox;
    }
    prev->prox=newNode;
    newNode->prox=current;
}

void push(char id,list *l, void *elem, int(*comp)(char, node *, node *)){
    node *newNode=nodeInitialized();
    newNode->elemen=elem;
    newNode->id=id;
    if(l->first==NULL){
        l->first=newNode;
        l->last=newNode;
    }
    else{
        node *current=l->first;
        node * prev = NULL;

        chainElement(current, prev, newNode, comp);
    }
}

void listSearch(list * l, int age, int(*cmpAge)(int age, void *elem, char id), void(*print)(char id, void *elem)){
    node *aux = l->first;
    if(aux!=NULL){
        printf("\nLista Vazia!");
    }
    else{
        while(aux!=NULL){
            if(cmpAge(age, aux->elemen, aux->id)==1){
                print(aux->id, aux->elemen);
                printf("Deseja excluir o elemento? ");
                pop(l, aux);
            }
            else{
                aux=aux->prox;
            }
    }
    }

}

void pop(list *l, node *n){
    if(l->first==NULL){
        printf("\nLista Vazia!\n");

    }
    else{
        node *current = l->first;
        node *prev = NULL;
        while(current!=n){
            prev=current;
            current=prev->prox;
        }
        node *aux = current;
        prev->prox=current->prox;
        free(aux);
    }
}

void freeList(list *l){
    freeNode(l->first);

}

void freeNode(node * n){
    if(n==NULL){
        printf("\nLista vazia! ");
    }
    else{
        node * aux = n->prox;
        n->prox=NULL;
        free(n);
        freeNode(aux);
    }


}