#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#define cem 100
#define cinq 50

nodeptr login(nodeptr first){
    char *nome= malloc(cinq*sizeof(char));
    nodeptr aux=first;

    printf("\nNome de Utilizador: ");
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
    printf("\nNome de Utilizador Nao Encontrado...\n");
    aux = login(first);
    return aux;
}

nodeptr regist(nodeptr first){
    char *name= malloc(cinq*sizeof(char));
    char *adress= malloc(cem*sizeof(char));
    char *date= malloc(cinq*sizeof(char));
    char *phone= malloc(cinq*sizeof(char));
    nodeptr aux=first;


    printf("\n.......... Inscricao de Novo utilizador ..........\n\n");

    printf("Nome de Utilizador: ");
    fgets(name,cinq,stdin);
    fflush(stdin);
    name=strtok(name,"\n");

    while(aux->next != NULL){
        if (strcmp(name,aux->name)==0){                               /* Ve se o nome de utilizador ja existe*/
            system("cls");
            printf("\n\t  ###### Utilizador em uso ######\n\n");
            regist(first);
        }
        aux=aux->next;
    }

    printf("Morada: ");
    fgets(adress,cem,stdin);
    fflush(stdin);
    adress=strtok(adress,"\n");

    printf("Data de Nascimento: ");
    fgets(date,cinq,stdin);
    fflush(stdin);
    date=strtok(date,"\n");

    printf("Telefone: ");
    fgets(phone,cinq,stdin);
    fflush(stdin);
    phone=strtok(phone,"\n");

    while(aux->next != NULL){ aux=aux->next;}
    insere(aux,name,adress,date,phone);
    inserefile("users.txt",aux);

    return aux;
}

nodeptr menulogin(nodeptr first){

    int num=0;
    nodeptr userptr;

    openfile("users.txt",first);

    printf("\n.......................");
    printf("\n\t -Menu-");
    printf("\n1 - Login");
    printf("\n2 - Register");
    printf("\n.......................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 2)) {   /* Caso o Utilizador nao Escolha uma das 2 opcoes */
        fflush(stdin);
        system("cls");
        menulogin(first);
    }

    fflush(stdin);
    system("cls");

    switch (num){
            case 1:
                userptr=login(first);break;
            case 2:
                userptr=regist(first);break;
    }

    return userptr;
}

void mainmenu(nodeptr user, nodeptr first){

    int num=0;

    printf("\n..................................");
    printf("\n\t -Menu Principal-\n");
    printf("\n1 - Perfil");
    printf("\n2 - Preferencias");
    printf("\n3 - Gerar Viagem");
    printf("\n..................................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 3)) {   /* Caso o Utilizador nao Escolha uma das 2 opcoes */
        fflush(stdin);
        system("cls");
        menulogin(first);
    }

    fflush(stdin);
    system("cls");

    switch (num){
            case 1:
                perfil();break;
            case 2:
                printf("preferencias()");break;
            case 3:
                printf("viagem()");break;
    }
}

void menualtera(){
}

void perfil(nodeptr userptr, nodeptr first){

    int num=0;

    printf("\n.........................");
    printf("\n\t -Perfil-\n");
    printf("\n1 - Logout");
    printf("\n2 - Alterar dados");
    printf("\n3 - Back");
    printf("\n.........................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 3)) {   /* Caso o Utilizador nao Escolha uma das 2 opcoes */
        fflush(stdin);
        system("cls");
        menulogin(first);
    }

    fflush(stdin);
    system("cls");

    switch (num){
            case 1:
                userptr=menulogin(first);break; /*logout*/
            case 2:
                menualtera();break;                   /*alterar prefs*/
            case 3:
                mainmenu(userptr,first);break;             /*back*/
    }
}


int main()
{
    nodeptr first=cria_user();

    nodeptr userptr=menulogin(first);

    system("cls");
    printf("\n     -Logged in com sucesso-\n");
    mainmenu(userptr,first);

    return 0;
}

