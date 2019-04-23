#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#define cem 100
#define cinq 50



void login(){
    char *name=(char *)malloc(cinq*sizeof(char));
    printf("Nome de Utilizador: ");
    fgets(name,cinq,stdin);
}

void regist(){
    char *name,*adress,*date,*phone;

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


}


void menulogin(){
    int num=0;

    printf(".......................");
    printf("\n\t -Menu-");
    printf("\n1 - Login");
    printf("\n2 - Register");
    printf("\n.......................");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 2)) {   /* Caso o Utilizador nao Escolha uma das opcoes */
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
    nodeptr wow=cria_user();
    nodeptr user=wow;
    nodeptr ini=wow;
    user=insere(user,"Puta","Wow","Pimbas","Yeet");
    user=insere(user,"Puta1","Wow1","Pimbas1","Yeet1");
    user=insere(user,"Puta2","Wow1","Pimbas1","Yeet1");
    print(ini);

    return 0;
}

