#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No no;

struct No
{
    char c;
    no *prox;
    no *final;
};
void delAfter(no **lista, char *c);
no *get(int index, no *lista);
no *getNo()
{
    no *novo = malloc(sizeof(no));

    if (novo == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }
    return novo;
}
bool isEmpty(no *lista)
{
    return lista == NULL;
}
 void delAfter(no **lista, char *info_){
    no *aux;
    if(isEmpty(*lista) || *lista==(*lista)->prox){
        printf("Remoção não permitida");
        
    }
    aux=(*lista)->prox;
    *info_=aux->c;
    (*lista)->prox=aux->prox;
    free(aux);
       
   
}

void insert(char c, no **lista)
{

    no *novo = getNo();
    novo->c = c;

    no *aux = *lista;
    if (isEmpty(*lista))
    {
        
        *lista=novo;
        (*lista)->prox=novo;

    }

    else
    {
        novo->prox=(*lista)->prox;
        (*lista)->prox=novo;
    }
    *lista=novo;
}

no *get(int index, no *lista)
{
    no *aux = lista;

    for (int i = 0; i < index; i++)
    {
        if (aux->prox == NULL)
        {
            return NULL;
        }
        aux = aux->prox;
    }
    return aux;
}
int size(no *lista){
    int size = 0;
    no *aux=lista;
    if(lista!=NULL){
        aux=lista;
        size=1;
    }
    
    while(aux->prox!=lista){
        aux=aux->prox;
        size=size+1;
    }
    return size;
}
/*void * josephus(int num , no **lista){
   int aux =num;
   no *listaAux=*lista;
   no *del;
   int tamanhoLista=size(listaAux);
   for (int i = 0;i<tamanhoLista;i++){
        del=delAfter(aux,&listaAux);
        aux=aux+num;
        printf("nó eliminado %c/\n: ",del->c);
   }
   printf("nó escolhido %c/\n: ",listaAux->c);
    
}*/
void concat(no **lista1, no **lista2){
    no *aux;
   if(isEmpty(*lista2)){
        
   }
   if(isEmpty(*lista1)){
        *lista1=*lista2;
   }
   aux=(*lista1)->prox;
   (*lista1)->prox=(*lista2)->prox;
   (*lista2)->prox=aux;
   *lista1=(*lista2);
    
   
}
void printList(no *lista)
{
    no *aux = lista;
    if (isEmpty(lista))
    {
        printf("Lista vazia!\n");
        return;
    }
    for (int i = 0; i < size(lista); i++)
    {
        printf("%c ", get(i, aux)->c);
        aux = aux->prox;
    }
}
int main()
{
    char alfabeto[26]="abcdefghijklmnopqrstuvxwyz";
    no *lista;
    no *lista2;
    for (int i = 0; i < 5;  i++)
    {
       insert(alfabeto[i], &lista);
    }
    for (int i = 6; i < 10;  i++)
    {
       insert(alfabeto[i], &lista2);
    }
    //elAfter(0,&lista);
    char info_;
    printf ("\ntamanho da lista: %d",size(lista));
    printList(lista);
    
    -
    
  
}