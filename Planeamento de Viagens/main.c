#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#define cem 100
#define cinq 50
#define tele 9

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
    char *phone= malloc(tele*sizeof(char));
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
    fgets(phone,tele,stdin);
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

void logout(nodeptr first){
    nodeptr aux=first;
    int counter=1;
    FILE *f=fopen("users.txt","w");
    while (aux->next!=NULL){
        if (counter==1){
            fprintf(f,"\n");
            fprintf(f,"%s\n",aux->name);
            fprintf(f,"%s\n",aux->adress);
            fprintf(f,"%s\n",aux->date);
            fprintf(f,"%s",aux->phone);
        }
        else{
            fprintf(f,"\n\n");
            fprintf(f,"%s\n",aux->name);
            fprintf(f,"%s\n",aux->adress);
            fprintf(f,"%s\n",aux->date);
            fprintf(f,"%s",aux->phone);
        }
        counter=0;
        aux=aux->next;
    }
    fclose(f);
    printf("\n     -Logged out com sucesso-\n");
}

void menualtera(nodeptr userptr,nodeptr first){

    int num=0;

    printf("\n.........................");
    printf("\n     -Alterar Dados-\n");
    printf("\n1 - Utilizador");
    printf("\n2 - Morada");
    printf("\n3 - Data de Nascimento");
    printf("\n4 - Telefone");
    printf("\n5 - Bach");
    printf("\n.........................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 5)) {   /* Caso o Utilizador nao Escolha uma das 5 opcoes */
        fflush(stdin);
        system("cls");
        menulogin(first);
    }
    fflush(stdin);
    system("cls");

    switch (num){
            case 1:
                alterauser(userptr,first);break;
            case 2:
                alteramorada(userptr,first);break;
            case 3:
                alteradata(userptr,first);break;
            case 4:
                alteraphone(userptr,first);break;
            case 5:
                perfil(userptr,first);break;

    }
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

    if (scanf("%d",&num) == 0 || (num < 1 || num > 3)) {   /* Caso o Utilizador nao Escolha uma das 3 opcoes */
        fflush(stdin);
        system("cls");
        menulogin(first);
    }

    fflush(stdin);
    system("cls");


    switch (num){
            case 1:
                logout(first);break;       /*logout*/
            case 2:
                menualtera(userptr,first);break;                     /*alterar prefs*/
            case 3:
                mainmenu(userptr,first);break;          /*back*/
    }
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

    if (scanf("%d",&num) == 0 || (num < 1 || num > 3)) {   /* Caso o Utilizador nao Escolha uma das 3 opcoes */
        fflush(stdin);
        system("cls");
        menulogin(first);
    }

    fflush(stdin);
    system("cls");

    switch (num){
            case 1:
                perfil(user,first);break;
            case 2:
                printf("preferencias()");break;
            case 3:
                printf("viagem()");break;
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

