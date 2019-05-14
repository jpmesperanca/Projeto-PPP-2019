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
    }
    return aux;
}

Local cria_local(){
    Local aux;
    aux=(Local)malloc(sizeof(local_node));

    if (aux!=NULL){
        aux->local=malloc(vinte5*sizeof(char));
        aux->pop=0;
        aux->pontos=NULL;
        aux->popnext=NULL;
        aux->abcnext=NULL;
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

        aux->local=sitio;
        aux->pop=pop;
        pdiptr=cria_pdi(aux);
        auxpdi=pdiptr;
        aux->pontos=auxpdi;

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
        aux->abcnext=cria_local();
        aux=aux->abcnext;


    }
    fclose(f);
    return ptr;
}
