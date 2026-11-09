#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct No no;

struct No {
    char info;
    no *inicio;
    no *fim;
    no *prox;
};
bool isEmpty(no *lista);
no *getNo(){
    no *novo = malloc(sizeof(no));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }
    return novo;
}
void inicializaFila(no **fila){
    *fila=getNo();
    (*fila)->inicio=NULL;
    (*fila)->fim=NULL;
}

//Adicionar elemento no final da fila
void insert(no **fila, char info_){
    no *novo=getNo();
    novo->info=info_;
    novo->prox=NULL;
    if(isEmpty((*fila)->fim)){
        (*fila)->inicio=novo;
    }
    else{
        (*fila)->fim->prox=novo;
    }
    (*fila)->fim=novo;
}

//Retorna o elemento do inicio da fila sem remover
char peek(no *fila){
    if(isEmpty(fila->inicio)){
        printf("Fila vazia, não é possível acessar o elemento do inicio\n");
        return -1;
    }
    return fila->inicio->info;
}

//Remover elemento do inicio da fila e retorna o valor removido
char remover(no **fila){
    if(isEmpty((*fila)->inicio)){
        printf("Fila vazia, não é possível remover\n");
        return -1;
    }
    no *aux=(*fila)->inicio;
    char info_=aux->info;
    (*fila)->inicio=aux->prox;
    if(isEmpty((*fila)->inicio)){
        (*fila)->fim=NULL;
    }
    free(aux);
    return info_;
}
bool isEmpty(no *lista){
    if(lista==NULL){
        return true;
    }
    else{
        return false;
    }
}



int main(){
   no *fila;
   inicializaFila(&fila);
   insert(&fila, 'C');
    insert(&fila, 'R');
    insert(&fila, '7');
    printf("Elemento do inicio da fila: %c\n", peek(fila));
    printf("Removendo: %c\n", remover(&fila));
    printf("Removendo: %c\n", remover(&fila));
    printf("Removendo: %c\n", remover(&fila));
}