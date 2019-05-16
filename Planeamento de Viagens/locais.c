#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locais.h"
#define vinte5 25
#define cem 100

/*char *local;
    pdi pontos;
    local popnext;
    local abcnext;

    char *nome;
    int prefered;
    local sitio;
    pdi next;
*/

Pdi cria_pdi(Local loc){
    Pdi aux;
    Local aux2 = loc;
    aux = (Pdi)malloc(sizeof(pdi_node));

    if (aux!=NULL){
        aux->nome=malloc(vinte5*sizeof(char));
        aux->descricao=malloc(vinte5*sizeof(char));
        aux->horario=malloc(vinte5*sizeof(char));
        aux->pop=0;
        aux->prefered=0;
        aux->sitio=aux2;
        aux->popnext=NULL;
        aux->abcnext=NULL;
        aux->usernext=NULL;
    }
    return aux;
}

/*
Local procura_local(Local first, char *novo){

    Local aux = first;

    while (aux->abcnext != NULL){
        if ( strcmp(novo,aux->local) > 0)
            aux = aux->abcnext;
        else
            break;
    }
    return aux;
}

void insere_local(Local first, char* sitio, int pop, Pdi pdiptr){

    Local anterior,temp,novo;

    anterior = procura_local(first, sitio);

    if (anterior->abcnext == NULL){
        novo = cria_local();
        novo->local = strdup(sitio);
        anterior->pontos = pdiptr;
        novo->abcnext = anterior->abcnext;
        anterior->abcnext = novo;
    }

    else{
        novo = (Local)malloc(sizeof(local_node));
        novo->local = strdup(sitio);
        novo->pontos = pdiptr;
        novo->abcnext = anterior;
        anterior =novo;
    }
}

void procura_lista (Local first, char *sitio, Local ant, Local actual){
    Local aux = first;
    while ( aux->abcnext != NULL && strcmp(aux->abcnext->local,sitio) < 0)
        aux = (aux)->abcnext;
    if (aux->abcnext != NULL && aux->abcnext->local != sitio)
        aux->abcnext= NULL;
}
void insere_local(Local first, char*sitio){
    Local no;
    Local ant, inutil;
    no = (Local) malloc (sizeof (local_node));
    if (no != NULL) {
        no->local = sitio;
        procura_lista (first, sitio, ant, inutil);
        no->abcnext = ant->abcnext;
        ant->abcnext = no;
    }
}
*/

Local insere_local(Local first, char* sitio){

    Local novo = cria_local();
    Local aux = first;

    if(novo==NULL)
        return NULL;

    while((aux->abcnext!=NULL)&&(strcmp(aux->abcnext->local, sitio)<0))
        aux = aux->abcnext;

    novo->local= malloc(strlen(sitio)+1);
    strcpy(novo->local, sitio);
    novo->abcnext= aux->abcnext;
    aux->abcnext = novo;


    Local localaux = first;
    int i=0;

    while(localaux->abcnext!=NULL){
        if (localaux->prefered==0)
            printf("\n%d - %s",i++,localaux->local);
        else if (localaux->prefered==1)
            printf("\n%d - %s *Choosen*",i++,localaux->local);
        localaux=localaux->abcnext;}

}

Local cria_local(){
    Local aux;
    aux=(Local)malloc(sizeof(local_node));

    if (aux!=NULL){
        aux->local=malloc(vinte5*sizeof(char));
        aux->pop=0;
        aux->prefered=0;
        aux->pontos=NULL;
        aux->popnext=NULL;
        aux->abcnext=NULL;
        aux->usernext=NULL;
    }
    return aux;
}

Local openlocal(char *file){
    Local ptr=cria_local();
    Local aux=ptr;
    char *tudo,*sitio,etc;
    char *info,*place,*descricao,*horario;
    int numero,i;
    int pop=0;
    Pdi pdiptr, auxpdi;
    FILE *f=fopen(file,"r");


    while(fscanf(f, "%c\n", &etc) == 1){   /* SALTAR \N */

        tudo = malloc(vinte5*sizeof(char));
        sitio = malloc(vinte5*sizeof(char));
        pop=0;

        fgets(tudo, vinte5, f);
        sscanf(tudo, "%d %[^,], %d", &numero, sitio,&pop);

        pdiptr=cria_pdi(aux);
        auxpdi=pdiptr;
        insere_local(ptr, sitio);

        for (i=0; i<numero; i++){
            info=malloc(cem*sizeof(char));
            place=malloc(vinte5*sizeof(char));
            descricao=malloc(vinte5*sizeof(char));
            horario=malloc(vinte5*sizeof(char));
            pop=0;

            fgets(info,cem,f);
            sscanf(info, "%[^,], %[^,], %[^,], %d",place,descricao,horario,&pop);

            auxpdi->nome=place;
            auxpdi->descricao=descricao;
            auxpdi->horario=horario;
            auxpdi->pop=pop;

            auxpdi->abcnext=cria_pdi(aux);
            auxpdi=auxpdi->abcnext;
        }
        aux=aux->abcnext;
    }
    fclose(f);
    printf("\n Jesus Cristler");

    Local localaux = ptr;
    i=0;

    while(localaux->abcnext!=NULL){
        if (localaux->prefered==0)
            printf("\n%d - %s",i++,localaux->local);
        else if (localaux->prefered==1)
            printf("\n%d - %s *Choosen*",i++,localaux->local);
        localaux=localaux->abcnext;}

    return ptr;
}
