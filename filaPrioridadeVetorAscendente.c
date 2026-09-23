#include <stdio.h>
#include <stdlib.h>


// Define o tamanho máximo da fila
#define tamanhoFila 100


// Define a estrutura que representa a fila
struct No {

    // Indica a posição do primeiro elemento da fila
    int topo;

    // Indica a posição onde está o último elemento da fila
    int final;

    // Vetor que armazena os elementos da fila
    int itens[tamanhoFila];
};


// Cria o apelido "no" para a estrutura
typedef struct No no;


// Função responsável por inicializar a fila
void iniciarFila(no *fila){

    // A fila começa na posição 0
    fila->topo = 0;

    // O final da fila também começa na posição 0
    fila->final = 0;

    // Inicializa a primeira posição do vetor com 0
    fila->itens[0] = 0;
}


// Função responsável por adicionar um elemento na fila
void pqInsert(int e, no *fila){

    // Coloca o elemento na posição seguinte ao final atual
    fila->itens[fila->final + 1] = e;

    // Atualiza a posição final da fila
    fila->final++;
}


// Função responsável por retirar um elemento da fila
int pqMindelete(no *fila){
  
    int numeroMenor = fila->itens[fila->topo];
    int indiceMenor = fila->topo;

    // Procura o menor elemento
    for (int i = fila->topo + 1; i <= fila->final; i++) {
        if (fila->itens[i] < numeroMenor) {
            numeroMenor = fila->itens[i];
            indiceMenor = i;
        }
    }
    // Remove o menor elemento deslocando os próximos
    // uma posição para a esquerda
    for (int j = indiceMenor; j < fila->final; j++) {
        fila->itens[j] = fila->itens[j + 1];
    }

    // Diminui o final da fila
    fila->final--;

    // Retorna o menor elemento
    return numeroMenor;
}


int main()
{
    // Aloca dinamicamente memória para armazenar a fila
    no *fila = malloc(sizeof(no));

    // Inicializa a fila
    iniciarFila(fila);

    // Adiciona o número 8 na fila
    pqInsert(8, fila);

    // Adiciona o número 3 na fila
    pqInsert(3, fila);
    pqInsert(3, fila);
    // Recupera e imprime o primeiro elemento da fila
    printf("%d\n", pqMindelete(fila));

    // Recupera e imprime o próximo elemento da fila
    printf("%d\n", pqMindelete(fila));

    // Adiciona o número 15 na fila
    pqInsert(15, fila);
    
    // Recupera e imprime o próximo elemento da fila
    printf("%d\n", pqMindelete(fila));

    // Tenta recuperar mais um elemento da fila
    printf("%d\n", pqMindelete(fila));
    // Tenta recuperar mais um elemento da fila
    printf("%d\n", pqMindelete(fila));

    return 0;
}