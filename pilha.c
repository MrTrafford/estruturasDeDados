#include <stdio.h>
#include <stdlib.h>

typedef struct No no;

struct No {
    char info;
    no *prox;
};

//Função para iniciar a pilha
no *iniciar() {
    return NULL;
}
bool isEmpty(no *pilha){
    if (pilha==NULL){
        return true;
    }
    else{
        return false;
    }
}

//Função para alocar memória para um novo nó
no * getNo(){
    no *novo = malloc(sizeof(no));
    return novo;
}

//função para adicionar um elemento na pilha
no *push(char info_, no *pilha) {

    no *novo = getNo();
    novo->info =info_;
    novo->prox = pilha;

    return novo;
}
char pop(no **pilha){
    if isEmpty(*pilha){
        printf("Não é possível remover da pilha");

    }
    else{
        char info =(*pilha)->info;
        (*pilha)=(*pilha)->prox;
        return info;
        free(*pilha);
    }
    
}
char top(no *pilha){
    if isEmpty(*pilha){
        printf("Não é possível remover da pilha");

    }
    else{
        char info =(*pilha)->info;
        (*pilha)=(*pilha)->prox;
        return info;
        free(*pilha);
    }
    return pilha->info;
}

int main() {

    no *pilha;

    pilha = iniciar();

    pilha = push('C', pilha);
    pilha = push('R', pilha);
    pilha = push('7', pilha);

    
    printf("%c\n",pop(&pilha));
    pilha = push('A', pilha);
    printf("%c\n",pop(&pilha));
    printf("%c\n",top(pilha));
    printf("%c\n",pop(&pilha));
    printf("%c\n",pop(&pilha));
    return 0;
}
