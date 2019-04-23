#include <stdio.h>
#include <stdlib.h>
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
        printf("%s ", pessoa->phone);
        pessoa=pessoa->next;
    }
}

