
#include <stdio.h>
#include <stdlib.h>
#define tamanhoPilha 100

//Estrutura da pilha baseada em vetor
//Operações: iniciarPilha, adicionar, remover e verificar se a pilha está vazia

//Estrutura da pilha baseada em vetor
struct No {
    int topo;
   char itens[tamanhoPilha];
};

typedef struct No no;

//Função para iniciar a pilha
void iniciarPilha(no *pilha){
    pilha->topo=0;
    pilha->itens[0]='\0';
}

//Função para adicionar um elemento na pilha
void adicionar(char info, no *pilha){
    pilha->itens[pilha->topo+1]=info;
    pilha->topo++;
}

//Função para remover um elemento da pilha e retornar o valor removido
char remover(no *pilha){
    char info=pilha->itens[pilha->topo];
    pilha->topo--;
    return info;
    
}
int main()
{
    
    
    no *pilha = malloc(sizeof(no));
    iniciarPilha (pilha);
    adicionar ('C', pilha);
    adicionar ('R', pilha);
    adicionar ('7', pilha);
    printf("%c\n", remover(pilha));
    printf("%c\n",remover(pilha));
    printf("%c\n",remover(pilha));
    return 0;
}
