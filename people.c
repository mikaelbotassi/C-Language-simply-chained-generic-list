#include "people.h"

people * peopleInitialized(){
    people * p=(people *)malloc(sizeof(people));
    p->age=0;
    p->feet=0.0;
    p->height=0.0;
    strcpy(p->name, "\0");
    return p;
}

void start(list *l){
    int res=1;
    while(res!=0){
        peopleInsert(l);
        printf("Deseja Inserir mais uma pessoa?Digite '1' para sim e '0' para não: ");
        scanf("%d", &res);
    }
}

void peopleInsert(list * l){
    people * p = peopleInitialized();
    printf("Digite o nome da pessoa: ");
    scanf(" %50[^\n]", &p->name);
    printf("\nDigite a idade da pessoa: ");
    scanf("%d", &p->age);
    printf("\nDigite o peso da pessoa: ");
    scanf("%f", &p->feet);
    printf("\nDigite a altura da pessoa: ");
    scanf("%f", &p->height);
    push('P',l, p, cmp);
}

int cmp(char id, void * n1, void *n2){
    if(id=='P' || id=='p'){
        if(n2!=NULL){
            people *p1=n1;
            people *p2=n2;
            if(p1->age>p2->age){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    else{
        printf("Insira outras verificações dos tipos de varáveis possíveis! ");
        return -1;
    }
}

void peopleSearch(list *l){
    int age;
    printf("\nQual a idade da pessoa que você quer procurar? ");
    scanf("%d", &age);
    listSearch(l, age, compareAges, printPeople);
}

int compareAges(int age, void * elem, char id){
    if(id=='P' || id=='p'){
        people *p=elem;
        if(p->age==age){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        printf("\nDigite outras sentenças aqui!");
        return -1;
    }
}

void printPeople(char id, void *elem){
    if(id == 'P' || id=='p'){
        people *p = elem;
        printf("\nNome: %s", p->name);
        printf("\nIdade: %d", p->age);
        printf("\nPeso: %f", p->feet);
        printf("\nAltura: %f", p->height);
        printf("\n");

    }
    else{
        printf("\nDigite mais sentenças! ");
    }
}

void printAllList(list *l){
    printList(l, printPeople);
}