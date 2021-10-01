#include "aluno.h"

aluno * allocAluno(){
    aluno * p=(aluno *)malloc(sizeof(aluno));
    p->matricula=0;
    p->nota=0;
    strcpy(p->nome, "\0");
    return p;
}

void start(list *l){
    char res='s';
    while(res!='s'){
        alunoInsert(l);
        printf("Deseja Inserir mais um aluno?Digite 's' para sim e 'n' para nao: ");
        scanf("%c", &res);
    }
}

void insertAluno(list * l){
    aluno * p = alunoInitialized();
    printf("\nDigite a altura da pessoa: ");
    scanf("%d", &p->matricula);
    printf("Digite o nome do aluno: ");
    scanf(" %31[^\n]", &p->nome);
    printf("\nDigite a nota do aluno: ");
    scanf("%d", &p->nota);
    push('A',l, p, cmp);
}

int descobreTipo(char id){
    if(id=='A' || id=='a'){
        return 1;
    }
    else{
        return 0;
    }
}

int cmp(char id, node * n1, node *n2){
    if(descobreTipo(id)){
        if(n2!=NULL){
            aluno *p1=n1->elemen;
            aluno *p2=n2->elemen;
            if(p1->matricula>p2->matricula){
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

void alunoSearch(list *l){
    int age;
    printf("\nQual a idade da pessoa que voce quer procurar? ");
    scanf("%d", &age);
    listSearch(l, age, matriculaCompare, printAluno);
}

int matriculaCompare(int matricula, void * elem, char id){
    if(descobreTipo(id)){
        aluno *p=elem;
        if(p->matricula==matricula){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        printf("\nDigite outras sentenças aqui!");
        return 0;
    }
}

void printAluno(char id, void *elem){
    if(descobreTipo(id)){
        aluno *p = elem;
        printf("\nMatricula: %d", p->matricula);
        printf("\nNome: %s", p->nome);
        printf("\nNota: %d", p->nota);
        printf("\n");

    }
    else{
        printf("\nDigite mais sentenças! ");
    }
}

void printAllList(list *l){
    if(l->first==NULL){
        printf("Lista vazia!\n");
    }
    else{
        printList(l, printAluno);
    }
}