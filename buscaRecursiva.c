#include <stdio.h>
int busca(int elemento,int low, int high, int vetor[]){
    if (low >high){
        return -1;
    }
    int meio = (low + high)/2;
    if(vetor[meio]==elemento){
        return meio;
    }
    if(vetor[meio]>elemento){
        return busca(elemento,low,meio-1, vetor);
    }
    else{
        return busca(elemento,meio+1,high, vetor);
    }
    
}
int main()
{
    
    printf("Hello World");
    int vetor[10] = {0,1,1,2,3,5,8,13,21,34};
    int indice = busca(13,0,9,vetor);
    printf("\n%d",indice);
    return 0;
}
