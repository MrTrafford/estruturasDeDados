#include <stdio.h>
#include <stdlib.h>

typedef struct No no;

struct No {
    int n;
    no *prox;
};
no *getNo(){
    no *novo = malloc(sizeof(no));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }
    return novo;
}
bool isEmpty(no *lista){
    if(lista==NULL){
        return true;
    }
    else{
        return false;
    }
}
void insertAfter(no ** lista, int n){
    no *novo=getNo();
   
    if(isEmpty(*lista)){
        printf("Lista vazia, não é possível inserir após\n");
    }
    novo->n=n;
    novo->prox=(*lista)->prox;
    (*lista)->prox=novo;

}
void deleteAfter(no **lista, int *n){
    no *aux;
    if(isEmpty(*lista) || isEmpty((*lista)->prox)){
        printf("Lista vazia, não é possível deletar após\n");
    }
    aux=(*lista)->prox;
    *n=aux->n;
    (*lista)->prox=aux->prox;
    free(aux);
    
}

void add (int n, no **lista){
    no *novo= getNo();
    novo->n=n;
    no *aux=*lista;
    novo->prox=aux;
    *lista=novo;
}
no * get(int index,no *lista){
    no *aux=lista;
    for (int i =0; i<index;i++){
        if(aux->prox==NULL){
            return NULL;
        }
        aux=aux->prox;
    }
    return aux;
}

int main(){
    no *lista;
    add(0,&lista);
    printf ("%d\n",get(0,lista)->n);
    for (int i=1;i<100;i++){
        //add(i,&lista);
        insertAfter(&lista,i);
        
    }
    for (int i=0;i<100;i++){
        printf ("%d\n",get(i,lista)->n);
    }
    deleteAfter(&lista,90);
    for (int i=0;i<100;i++){
        printf ("%d\n",get(i,lista)->n);
    }
}