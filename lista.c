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
/*
O push recebe o tipo de dado que irá armazenar no ID, o elemento e um ponteiro de função da biblioteca pessoa cujo nome é "cmp"
*/
void push(char id,list *l, void *elem, int(*comp)(char, node *, node *)){
    node *newNode=nodeInitialized();
    newNode->elemen=elem;
    newNode->id=id;
    if(l->first==NULL){
        newNode->prox=NULL;
        l->first=newNode;
        l->last=newNode;
    }
    else{
    /*Estes são os ponteiros para percorrer a
    lista, o current(atual) começa do primeiro elemento da lista e o anterior começa do
    NULL e vão percorrendo a lista*/
        node *current=l->first;
        node * prev = NULL;

        while(comp(id, newNode, current)){
            prev=current;
            current=prev->prox;
        }
        if(prev==NULL){//Se previous igual a NULL significa que o elemento é o primeiro da lista
            newNode->prox=l->first;
            l->first=newNode;
        }
        else{
            if(current==NULL){//Se current igual a NULL signifca que o elemento será o último da lista
                l->last->prox=newNode;
                l->last=newNode;
                l->last->prox=NULL;
            }
            else{//Se não for nenhum dos casos acima, signifca que vai inserir no meio da lista
                prev->prox=newNode;
                newNode->prox=current;
            }
        }
    }
}
/*
Percorre a lista procurando elemento que possui a altura igual o elemento atual da busca,
a comparação é feita através da função CompareAge(Procure na biblioteca people)
*/
void listSearch(list * l, int age, int(*cmpAge)(int age, void *elem, char id), void(*print)(char id, void *elem)){
    node *aux = l->first;
    char resp;
    if(aux==NULL){
        printf("\nLista Vazia!\n");
    }
    else{
        while(aux!=NULL){
            if(cmpAge(age, aux->elemen, aux->id)){
                print(aux->id, aux->elemen);
                printf("Deseja excluir o elemento?Digite 's' para sim e 'n' para nao: ");
                scanf(" %c", &resp);
                if(resp=='s'){
                    pop(l, aux);
                    break;
                }
                else{
                    break;
                }
            }
            else{
                aux=aux->prox;
            }
    }
    }

}
/*
    Função que tira um determinado elemento da lista, usa o mesmo metódo de percorrer a lista que o push.
*/
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
        if(current==l->first){ //Se for o primeiro elemento da lista
            l->first=current->prox;
            free(current);
        }
        else{
            if(current==l->last){ //Se for o último elemento da lista
                prev->prox=NULL;
                l->last=prev;
                free(current);
            }
            else{ //Se for um elemento do meio da lista
                prev->prox=current->prox;
                free(current);
            }
        }
    }
}

void freeList(list *l){
    while(l->first!=NULL){
        node * aux=l->first;
        pop(l,aux);
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