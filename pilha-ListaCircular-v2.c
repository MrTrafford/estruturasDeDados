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
        *pilha=novo;
       
    }
    else{
       novo->prox = (*pilha)->prox;
       
      
        
        
    }
    (*pilha)->prox=novo;
    
    
    

    
}

//Função para remção na pilha





char pop(no **pilha){
    char info_;
    no *aux;
    if (isEmpty(*pilha)){
        printf("Underflow na pilha");
        exit (1);
    }
    aux = (*pilha)->prox;
    info_=aux->info;
    if(aux==*pilha){
        
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
    push('C', &pilha);
    printf("%c\n",pop(&pilha));
    printf("%c\n",pop(&pilha));
    printf("%c\n",pop(&pilha));
    
   
   
}
