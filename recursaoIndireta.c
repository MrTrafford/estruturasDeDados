
#include <stdio.h>
#include <stdlib.h>
/*
Aqui temos um exemplo de recursão indireta. Afunção menu() pode chamar as funções
menuCadastroAluno e menuCadastroProfessor(), que por sua vez, podem chamar a 
função menu()

*/
void menuCadastroProfessor();
void menuCadastroAluno();
void menu(){
    int opc = 0;
    printf("1 - Cadastro de aluno\n"); 
    printf("2 - Cadastro de professor\n");
    scanf("%d",&opc);
    if (opc==1){
        menuCadastroAluno();
        //Chamada da função menuCadastroAluno()
    }
    else if(opc==2){
        menuCadastroProfessor();
        //Chamada da função menuCadastroProfessor()
    }
}
void menuCadastroProfessor(){
    char nome[20];
    char titulacao [20];
    printf("1 - Nome\n"); 
    scanf("%s",nome);
    printf("2 - Titulacao\n");
    scanf("%s",titulacao);
    printf("Cadastrado nome: %s titulação %s \n",nome,titulacao);
    //Chamada da função menu()
    menu();
}
void menuCadastroAluno(){
    char nome[20];
    char matricula [20];
    printf("1 - Cadastro de aluno\n"); 
    printf("2 - Cadastro de professor\n");
    printf("1 - Nome\n"); 
    scanf("%s",nome);
    printf("2 - Matrícula\n");
    scanf("%s",matricula);
    printf("Cadastrado nome: %s matrícula %s \n",nome,matricula);
    menu();
    //Chamada da função menu()
    
}
int main()
{
    
    menu();
    return 0;
    
}