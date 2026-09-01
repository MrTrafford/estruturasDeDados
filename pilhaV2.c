#include <stdio.h>
#include <stdlib.h>

typedef struct No no;

struct No {
    int n;
    no *prox;
};

no *iniciar() {
    return NULL;
}

void *push(int n, no **pilha) {

    no *novo = malloc(sizeof(no));
    no *aux = malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return pilha;
    }

    novo->n = n;
    aux=*pilha;
    novo->prox = aux;
    *pilha=novo;
}
int pop(no **pilha){
    int n =(*pilha)->n;
    (*pilha)=(*pilha)->prox;
    return n;
}

int main() {

    no *pilha;

    pilha = iniciar();

    push(5, &pilha);
    push(10, &pilha);
    

    
    printf("%d\n",pop(&pilha));
    push(17, &pilha);
    push(6, &pilha);
    printf("%d\n",pop(&pilha));
    printf("%d\n",pop(&pilha));
    return 0;
}