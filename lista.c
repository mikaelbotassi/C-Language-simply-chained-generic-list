#include "lista.h"

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
    n->id='\0';
    return n;
}

void push(char id,list *l, void *elem, int(*comp)(char, void *, void *)){
    node *newNode=nodeInitialized();
    newNode->elemen=elem;
    newNode->id=id;
    if(l->first==NULL){
        l->first=newNode;
        l->last=newNode;
        newNode->prox=NULL;
    }
    else{
        printf("Estive aqui!");
        node *current=l->first;
        node * prev = NULL;

        while(comp(id, newNode->elemen, current->elemen)){
            prev=current;
            current=prev->prox;
        }
        if(prev==NULL){//Se previous igual a NULL significa que o elemento é o primeiro da lista
            newNode->prox=l->first;
            l->first=newNode;
        }
        else{
            if(current==NULL){
                l->last->prox=newNode;
                l->last=newNode;
                l->last->prox=NULL;
            }
            else{
                prev->prox=newNode;
                newNode->prox=current;
            }
        }
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
        if(current==l->first){
            l->first=current->prox;
            free(current);
        }
        else{
            if(current==l->last){
                prev->prox=NULL;
                l->last=prev;
                free(current);
            }
            else{
                prev->prox=current->prox;
                free(current);
            }
        }
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

void printList(list *l, void(*print)(char id, void *elem)){
    node *aux=l->first;
    if(aux==NULL){
        printf("Lista Vazia! ");
    }
    else{   
        while(aux!=NULL){
            print(aux->id, aux->elemen);
            aux=aux->prox;
        }
    }
}