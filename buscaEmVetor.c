#include <stdio.h>


int busca(int a[],int tamanho,int n){
    for(int i = 0; i <tamanho;i++){
        if (a[i]==n){
            return i;
        }
    }
    return -1;
}
int main()
{   
    #define tamanho 100
    int numeros[tamanho];
    printf("Hello World");
    for (int i = 0; i<100;i++){
        numeros[i]=i+101;
    }
    int indice = busca(numeros,tamanho,200);
    printf("%d\n",indice);

    return 0;
}