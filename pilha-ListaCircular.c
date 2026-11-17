#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Implementação de uma pilha utilizando lista circular

//Define um apelido para a pilha
typedef struct No no;

//Estrutura que define a nossa pilha
struct No {
    char info;
    no *prox;
    no *final;
};

//Função para iniciar a pilha
no *iniciar() {
    return NULL;
    
}

//Função para criar um nó
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
      
        
        
    }
    *pilha=novo;
    
    
    

    
}

//Função para remção na pilha
int pop(no **pilha){
    char info_;
    no *aux;
    if (isEmpty(*pilha)){
        printf("Underflow na pilha");
        exit (1);
    }
    else if(*pilha==(*pilha)->prox){
        *pilha=NULL;
    }
    else{
        aux=*pilha;
        info_=aux->info;
        *pilha=(*pilha)->prox;
    }
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
   
   
}
