/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define tamanhoFila 100

//Define a estrutura que representa a fila
struct No{
    //Indice da primeira posição da fila
    int topo;
    
    //Indice da final posição da fila
    int final;
    
    int itens[tamanhoFila];
};

// Apelido no para a estrutura
typedef struct No no;

//FunçãO responsável por adicionar um elemento
void pqInsert(int e, no *fila){
    //colocar o elemento na posição final da fila
    fila->itens[fila->final]= e;
    
    //atualiza o indice final da fila
    fila->final=fila->final+1;
}

//FunçãO responsável por recuperar e remover um elemento
int pqMinDelete(no *fila){
    int menorNumero = fila->itens[fila->topo];
    //variável que armazena o menor número
    int indiceMenorNumero = fila->topo;
    //variável que armazena o índice do menor número na fila
    
    //Procurar o menor elemento e o índice do menor elemento
    for(int i = fila->topo+1; i<fila->final; i=i+1){
        if (fila->itens[i]<menorNumero){
            menorNumero = fila->itens[i];
            indiceMenorNumero= i;
        }
    }
    //Remove o menor elemento deslocando os próximos uma posição para a esquerda
    for (int j = indiceMenorNumero;j<fila->final;j=j+1){
        fila->itens[j]=fila->itens[j+1];
    }
    // Diminui o índice final da fila
    fila->final=fila->final-1;
    
    //Retorno o elemento
    return menorNumero;
    
    
}
int main()
{
   //alocar dinamicamente memória para armazenar a fila
   no *fila =malloc(sizeof(no));
   
   pqInsert(7,fila);
   pqInsert(16,fila);
   pqInsert(80,fila);
   pqInsert(5,fila);
   pqInsert(20,fila);
   pqInsert(11,fila);
   
   printf("%d\n",pqMinDelete(fila));
   printf("%d\n",pqMinDelete(fila));
   printf("%d\n",pqMinDelete(fila));
   printf("%d\n",pqMinDelete(fila));
   printf("%d\n",pqMinDelete(fila));
   printf("%d\n",pqMinDelete(fila));
   
}
