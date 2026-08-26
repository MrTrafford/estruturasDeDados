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

no *push(int n, no *pilha) {

    no *novo = malloc(sizeof(no));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return pilha;
    }

    novo->n = n;
    novo->prox = pilha;

    return novo;
}
int peek(no **pilha){
    int n =(*pilha)->n;
    (*pilha)=(*pilha)->prox;
    return n;
}

int main() {

    no *pilha;

    pilha = iniciar();

    pilha = push(5, pilha);
    pilha = push(10, pilha);
    

    
    printf("%d\n",peek(&pilha));
    pilha = push(6, pilha);
    printf("%d\n",peek(&pilha));
    printf("%d\n",peek(&pilha));
    return 0;
}