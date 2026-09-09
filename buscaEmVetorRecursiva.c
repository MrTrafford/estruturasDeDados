#include <stdio.h>


int busca(int a[],int i, int n){
    if(a[i]==n){
        return i;
    }
    else{
        return busca(a,i+1,n);
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
    int i =0;
    int indice = busca(numeros,i,200);
    printf("%d\n",indice);

    return 0;
}