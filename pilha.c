#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Implementação de uma pilha utilizando lista circular

typedef struct No no;

struct No {
    char info;
    no *prox;
    no *final;
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

//Função para verificiar se a pilha está vazia
bool isEmpty(no *pilha) {
    if (pilha == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Função para inserção na pilha
void push(char info_, no **pilha) {
    no *novo = getNo();
    
    
    if (novo == NULL) {
        return;
    }

    novo->info = info_;

    if (isEmpty(*pilha)){
        novo->prox= novo;
        novo->final=novo;
       
    }
    else{
       novo->prox = (*pilha);
       
       novo->final = (*pilha)->final;
      (*pilha)->final->prox=novo;
        
        
    }
    *pilha=novo;
    
    
    

    
}

//Função para remção na pilha





int pop(no **pilha){
    char info_;
    no *aux;
    aux=*pilha;
    info_=aux->info;
    if (isEmpty(*pilha)){
        printf("Underflow na pilha");
        exit (1);
    }
    else if(*pilha==(*pilha)->prox){
        *pilha=NULL;
    }
    else{
        
        (*pilha)->final->prox=(*pilha)->prox;
        *pilha=(*pilha)->prox;
        free(aux);
    }
    return info_;
}

int main() {
    no *pilha;
    pilha = iniciar();
    push('A', &pilha);
    push('B', &pilha);
    push('C', &pilha);
    
   
    printf("Eliminado %c\n", pop(&pilha));
   
    printf("Eliminado %c\n", pop(&pilha));
    
    
    
   
   
}
