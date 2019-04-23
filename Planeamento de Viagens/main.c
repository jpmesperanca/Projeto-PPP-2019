#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#define cem 100
#define cinq 50


void login(){
    char *nome= malloc(cinq*sizeof(char));
    printf("Nome de Utilizador: ");
    fgets(nome,cinq,stdin);
    fflush(stdin);
    while(aux->next != NULL){           /* FALTA PUXAR O AUXILIAR DOS FICHEIROS*/
        if (nome!=aux->name){
            system("cls");
            printf("Nome de Utilizador Não Encontrado...\n");
            login();
        }
        mainmenu();                     /* FASE 2 */
    }

}

void regist(){
    char *name= malloc(cinq*sizeof(char));
    char *adress= malloc(cem*sizeof(char));
    char *date= malloc(cinq*sizeof(char));
    char *phone= malloc(cinq*sizeof(char));

    printf("Nome de Utilizador: ");
    fgets(name,cinq,stdin);
    fflush(stdin);

    printf("Morada: ");
    fgets(adress,cem,stdin);
    fflush(stdin);

    printf("Data de Nascimento: ");
    fgets(date,cinq,stdin);
    fflush(stdin);

    printf("Telefone: ");
    fgets(phone,cinq,stdin);
    fflush(stdin);
                                             /* IF CLAUSE PARA ACEITAR O NOME DE UTILIZADOR */
    insere(user,name,adress,date,phone);     /* PRECISA DE NOME QUE SAI DO FICHEIRO DOS USERS */
}


void menulogin(){
    int num=0;

    printf(".......................");
    printf("\n\t -Menu-");
    printf("\n1 - Login");
    printf("\n2 - Register");
    printf("\n.......................");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 2)) {   /* Caso o Utilizador nao Escolha uma das 2 opcoes */
        fflush(stdin);
        system("cls");
        menulogin();
    }

    switch (num){
            case 1:
                printf("login()");break;
            case 2:
                printf("regist()");break;
    }
}

int main()
{
    /*
    nodeptr wow=cria_user();
    nodeptr user=wow;
    nodeptr ini=wow;
    user=insere(user,"Puta","Wow","Pimbas","Yeet");
    user=insere(user,"Puta1","Wow1","Pimbas1","Yeet1");
    user=insere(user,"Puta2","Wow1","Pimbas1","Yeet1");
    print(ini);
    */
    return 0;
}

