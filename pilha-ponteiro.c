#include <stdio.h>
#include <stdlib.h>

typedef struct No no;
struct No{
    char info;
    no *prox;
};





/*Funções básicas da pilha
1   -   Inserção na pilha (push)
2   -   Recuperação  da informação do topo da pilha sem remoção (top)
3   -   Recuperação  da informação do topo da pilha com remoção (pop)


Funções auxiliares

4   -   Função de alocação de memória de um novo nó (getNo)
5   -   Função para verificar se a pilha está vazia (isEmpty)
6   -   FUnção para iniciar a pilha (iniciar)

*/

// Função para iniciar a pilha
no *iniciar(){
    return NULL;
}

//Função para alocar um novo nó na pilha 

no *getNo(){
    no *novo = malloc(sizeof(no));
    return novo;
}

//Função para adicionar um elemento na pilha
no *push (char info_ , no **pilha){
    no *novo = getNo();
    novo->info=info_;
    novo ->prox =*pilha;
    *pilha =novo;
    

}

//Função para verificar se a pilha está vazia (isEmpty)
bool isEmpty(no *pilha){
    if(pilha==NULL){
        printf("Underflow");
        return true;
    }
    else{
        return false;
    }
}

//Retorna o valor do elemento do topo da pilha sem remover
char top(no *pilha){
    char info_;
    info_= pilha->info;
    return info_;
}

//Retorna o valor do elemento do topo da pilha e remove o elemento
char pop(no **pilha){
    char info_;
    no *aux;
    if(isEmpty(*pilha)){
        return '\0';
    }
    else{
        aux= *pilha;
        info_=(*pilha)->info;
        *pilha= (*pilha)->prox;
        free (aux);
        return info_;   
    }
    
    
}

//Função para adicionar um elemento na pilha
/*no *push (char info_ , no *pilha){
    no *novo = getNo();
    novo->info=info_;
    novo ->prox =pilha;
    pilha =novo;
    return pilha;
    

}*/

int main() {

    no *pilha;
    pilha=iniciar();
    push('A',&pilha);
    
    push('B',&pilha);
   
    push('C',&pilha);
    printf("%c\n",top(pilha));
    printf("%c\n",pop(&pilha));
    printf("%c\n",pop(&pilha));
    printf("%c\n",pop(&pilha));
    printf("%c\n",pop(&pilha));
    
    

    
    
   

}
