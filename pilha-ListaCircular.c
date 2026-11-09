#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Implementação de uma pilha utilizando lista circular

typedef struct No no;

struct No {
    char info;
    no *prox;
};

no *iniciar() {
    return NULL;
}
no * getNo(){
    no *novo = malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }
    return novo;
}
bool isEmpty(no *pilha) {
    if (pilha == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void push(char info_, no **pilha) {
    no *novo = getNo();
    no *aux = *pilha;
    
    if (novo == NULL) {
        return;
    }

    novo->info = info_;

    if (isEmpty(aux)){
        novo->prox= novo;
    }
    else{
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    *pilha=novo;
    
    

    
}
int pop(no **pilha){
    char info_;
    no *aux;
    if (isEmpty(*pilha)){
        printf("Underflow na pilha");
        exit (1);
    }
    aux=(*pilha)->prox;
    info_=aux->info;
    if(aux==(*pilha)){
        *pilha=NULL;
    }
    else{
        (*pilha)->prox=aux->prox;
    }
    free(aux);
    return info_;
}

int main() {
    no *pilha;
    pilha = iniciar();
    push('A', &pilha);
    push('B', &pilha);
    push('c', &pilha);
    push('d', &pilha);
    push('e', &pilha);
    printf("%c\n",pop(&pilha));
    printf("%c\n",pop(&pilha));
    printf("%c\n",pop(&pilha));
    printf("%c\n",pop(&pilha));
    printf("%c\n",pop(&pilha));
    printf("%c\n",pop(&pilha));
   
}
