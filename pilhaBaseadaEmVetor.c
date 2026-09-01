=
#include <stdio.h>
#include <stdlib.h>
#define tamanhoPilha 100
struct No {
    int topo;
   int itens[tamanhoPilha];
};
typedef struct No no;
void iniciarPilha(no *pilha){
    pilha->topo=0;
    pilha->itens[0];
}
void adicionar(int e, no *pilha){
    pilha->itens[pilha->topo+1]=e;
    pilha->topo++;
}
int recuperar(no *pilha){
    int numero=pilha->itens[pilha->topo];
    pilha->topo--;
    return numero;
    
}
int main()
{
    
    
    no *pilha = malloc(sizeof(no));
    iniciarPilha (pilha);
    adicionar (2, pilha);
    adicionar (7, pilha);
    adicionar (9, pilha);
    printf("%d\n",recuperar(pilha));
    printf("%d\n",recuperar(pilha));
    return 0;
}
