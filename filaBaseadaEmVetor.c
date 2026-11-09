#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define tamanhoPilha 100

//Estrutura da fila baseada em vetor
//Operações: iniciarFila, adicionar, remover e verificar se a fila está vazia

//Estrutura da pilha baseada em vetor
struct No {
    int topo;
    int final;
   char itens[tamanhoPilha];
};

typedef struct No no;

//Função para iniciar a fila
void iniciarFila(no *fila){
    fila->topo=0;
    fila->final=0;
    
}
//Função para verificar se a fila está vazia
bool isEmpty(no *fila){
    if(fila->topo==fila->final){
        return true;
    }
    else{
        return false;
    }
}   

//Função para adicionar um elemento na fila
void adicionar(char info, no *fila){
    fila->itens[fila->final+1]=info;
    fila->final++;
}

//Função para remover um elemento da fila e retornar o valor removido
char remover(no *fila){
    if (isEmpty(fila)){
        printf("Fila vazia, não é possível remover\n");
        return '\0';
    }
    else{
        char info=fila->itens[fila->topo];
        fila->topo++;
        return info;
    }
    
    
}
int main()
{
    
    
    no *fila   = malloc(sizeof(no));
    iniciarFila (fila);
    adicionar ('C', fila);
    adicionar ('R', fila);
    adicionar ('7', fila);
    printf("%c\n", remover(fila));
    printf("%c\n",remover(fila));
    printf("%c\n",remover(fila));
    return 0;
}
