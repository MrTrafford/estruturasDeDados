#include <stdio.h>
#include <stdlib.h>

/*Podemos perceber que a estrutura da fila é muito semelhante à estrutura da pilha, com a diferença de que a fila possui dois 
identificadores: um para o início (topo) e outro para o final (final) da fila. A função "adicionar" adiciona elementos no final da fila, 
enquanto a função "recuperar" remove elementos do início da fila, seguindo a lógica FIFO (First In, First Out).
*/
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
void adicionar(int e, no *fila){

    // Coloca o elemento na posição seguinte ao final atual
    fila->itens[fila->final + 1] = e;

    // Atualiza a posição final da fila
    fila->final++;
}


// Função responsável por retirar um elemento da fila
int recuperar(no *fila){

    // Guarda o elemento que está no início da fila
    int numero = fila->itens[fila->topo];

    // Avança o início da fila para o próximo elemento
    fila->topo++;

    // Retorna o elemento que foi retirado
    return numero;
}


int main()
{
    // Aloca dinamicamente memória para armazenar a fila
    no *fila = malloc(sizeof(no));

    // Inicializa a fila
    iniciarFila(fila);

    // Adiciona o número 2 na fila
    adicionar(2, fila);

    // Adiciona o número 7 na fila
    adicionar(7, fila);

    // Recupera e imprime o primeiro elemento da fila
    printf("%d\n", recuperar(fila));

    // Recupera e imprime o próximo elemento da fila
    printf("%d\n", recuperar(fila));

    // Adiciona o número 9 na fila
    adicionar(9, fila);

    // Recupera e imprime o próximo elemento da fila
    printf("%d\n", recuperar(fila));

    // Tenta recuperar mais um elemento da fila
    printf("%d\n", recuperar(fila));

    return 0;
}