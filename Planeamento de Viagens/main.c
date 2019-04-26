#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#define cem 100
#define cinq 50

nodeptr login(nodeptr first){
    char *nome= malloc(cinq*sizeof(char));
    int check=0;
    nodeptr aux=first;

    printf("Nome de Utilizador: ");
    fgets(nome,cinq,stdin);
    fflush(stdin);
    nome=strtok(nome,"\n");
    while(aux->next != NULL){
        if (strcmp(nome,aux->name)==0){
            return aux;

        }
        aux=aux->next;
    }
    system("cls");
    printf("Nome de Utilizador Nao Encontrado...\n");
    aux=login(first);
    return aux;
}


nodeptr menulogin(nodeptr first){
    int num=0;
    nodeptr userptr;

    openfile("users.txt",first);
    print(first);

    printf(".......................");
    printf("\n\t -Menu-");
    printf("\n1 - Login");
    printf("\n2 - Register");
    printf("\n.......................");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 2)) {   /* Caso o Utilizador nao Escolha uma das 2 opcoes */
        fflush(stdin);
        system("cls");
        menulogin(first);
    }
    fflush(stdin);
    switch (num){
            case 1:
                userptr=login(first);break;
            case 2:
                printf("userptr=regist(first)");break;
    }
    return userptr;
}

int main()
{
    nodeptr first=cria_user();
    nodeptr userptr=menulogin(first);
    printf("\nResultou! %s",userptr->name);
    return 0;
}

