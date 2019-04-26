#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#define cinq 50
#define cem 100

nodeptr cria_user(){
    nodeptr aux;
    aux=(nodeptr)malloc(sizeof(utilizador_node));

    if (aux!=NULL){
        aux->name=malloc(cinq*sizeof(char));
        aux->adress=malloc(cem*sizeof(char));
        aux->date=malloc(cinq*sizeof(char));
        aux->phone=malloc(cinq*sizeof(char));
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

void print(nodeptr user){
    nodeptr pessoa = user;
    while (pessoa->next!=NULL){
        printf("%s ", pessoa->name);
        printf("%s ", pessoa->adress);
        printf("%s ", pessoa->date);
        printf("%s \n", pessoa->phone);
        pessoa=pessoa->next;
    }
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
        telefone=malloc(cinq*sizeof(char));

        fgets(nome,cinq,f);
        nome=strtok(nome,"\n");

        fgets(adereco,cem,f);
        adereco=strtok(adereco,"\n");

        fgets(data,cinq,f);
        data=strtok(data,"\n");

        fgets(telefone,cinq,f);
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
