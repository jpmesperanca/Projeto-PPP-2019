#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#define cem 100
#define cinq 50




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

    nodeptr wow=cria_user();
    openfile("users.txt",wow);

    return 0;
}

