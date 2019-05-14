#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#define cinq 50
#define cem 100
#define tele 9



nodeptr cria_user(){
    nodeptr aux;
    aux=(nodeptr)malloc(sizeof(utilizador_node));

    if (aux!=NULL){
        aux->name=malloc(cinq*sizeof(char));
        aux->adress=malloc(cem*sizeof(char));
        aux->date=malloc(cinq*sizeof(char));
        aux->phone=malloc(tele*sizeof(char));
        aux->next=NULL;
    }
    return aux;
}


nodeptr insere(nodeptr fnl,char *nome,char *morada,char *data,char *telefone){
    nodeptr aux=fnl;
    aux->name=nome;
    aux->adress=morada;
    aux->date=data;
    aux->phone=telefone;
    aux->next=cria_user();
    return aux->next;
}


int print(nodeptr user){
    nodeptr pessoa = user;
    printf("%s\n", pessoa->name);
    printf("%s\n", pessoa->adress);
    printf("%s\n", pessoa->date);
    printf("%s \n", pessoa->phone);
    return 2;
}


nodeptr openfile(char *file,nodeptr ptr){

    nodeptr aux=ptr;
    FILE *f=fopen(file,"r");
    char *nome,*adereco,*data,*telefone;
    char etc;


    while(fscanf(f, "%c\n", &etc) == 1){  /* SALTAR \N */

        fflush(stdin);
        nome=malloc(cinq*sizeof(char));
        adereco=malloc(cem*sizeof(char));
        data=malloc(cinq*sizeof(char));
        telefone=malloc(tele*sizeof(char));

        fgets(nome,cinq,f);
        nome=strtok(nome,"\n");

        fgets(adereco,cem,f);
        adereco=strtok(adereco,"\n");

        fgets(data,cinq,f);
        data=strtok(data,"\n");

        fgets(telefone,tele,f);
        telefone=strtok(telefone,"\n");

        aux=insere(aux,nome,adereco,data,telefone);
    }
    fclose(f);
    return aux;
}


void inserefile(char *file,nodeptr ptr){
    nodeptr aux=ptr;
    FILE *f=fopen(file,"a");
    fprintf(f,"\n\n");
    fprintf(f,"%s\n",aux->name);
    fprintf(f,"%s\n",aux->adress);
    fprintf(f,"%s\n",aux->date);
    fprintf(f,"%s",aux->phone);
    fclose(f);
}


int alterauser(nodeptr userptr,nodeptr first){
    nodeptr aux=first;
    char *input=malloc(cinq*sizeof(char));
    printf("\nNome de Utilizador: ");
    fgets(input,cinq,stdin);
    fflush(stdin);
    system("cls");
    input=strtok(input,"\n");

    while(aux->next!=NULL){
        if (strcmp(input,aux->name)==0){                              /* Ve se o nome de utilizador ja existe*/
            system("cls");
            printf("\n\t  ###### Utilizador em uso ######\n");
            return 6;
        }
        aux=aux->next;
        }

    userptr->name=input;
    return 5;
}


int alteramorada(nodeptr userptr,nodeptr first){
    printf("\nMorada: ");
    fgets(userptr->adress,cem,stdin);
    fflush(stdin);
    system("cls");
    userptr->adress=strtok(userptr->adress,"\n");
    return 5;
}


int alteradata(nodeptr userptr,nodeptr first){
    printf("\nData de Nascimento: ");
    fgets(userptr->date,cinq,stdin);
    fflush(stdin);
    system("cls");
    userptr->date=strtok(userptr->date,"\n");
    return 5;
}


int alteraphone(nodeptr userptr,nodeptr first){
    printf("\nNumero de Telefone: ");
    fgets(userptr->phone,tele,stdin);
    fflush(stdin);
    system("cls");
    userptr->phone=strtok(userptr->phone,"\n");
    return 5;
}
