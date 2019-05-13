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
        aux->pontos=NULL;
        aux->popnext=NULL;
        aux->abcnext=NULL;
    }
    return aux;
}



Local openlocal(char *file,Local ptr){
    Local aux=ptr;
    char *tudo,*sitio,etc;
    char *info,*place,*descricao,*horario;
    int numero,i;
    Pdi pdiptr, auxpdi;
    FILE *f=fopen(file,"r");


    while(fscanf(f, "%c\n", &etc) == 1){   /* SALTAR \N */

        tudo = malloc(vinte5*sizeof(char));
        sitio = malloc(vinte5*sizeof(char));

        fgets(tudo, vinte5, f);
        sscanf(tudo, "%d %s", &numero, sitio);
        sitio=strtok(sitio,"\n");

        aux->local=sitio;
        pdiptr=cria_pdi(aux);
        auxpdi=pdiptr;
        aux->pontos=auxpdi;

        printf("%s\n",sitio);

        for (i=0; i<numero; i++){
            info=malloc(cem*sizeof(char));
            place=malloc(vinte5*sizeof(char));
            descricao=malloc(vinte5*sizeof(char));
            horario=malloc(vinte5*sizeof(char));
            fgets(info,cem,f);
            sscanf(info, "%[^','], %[^','], %[^',']",place,descricao,horario);
            horario=strtok(horario,"\n");
            printf("-%s-%s-%s-\n\n",place,descricao,horario);

            auxpdi->nome=place;
            pdiptr->descricao=descricao;
            pdiptr->horario=horario;

            auxpdi->abcnext=cria_pdi(aux);
            auxpdi=auxpdi->abcnext;
        }
        aux->abcnext=cria_local();
        aux=aux->abcnext;


    }
    fclose(f);
    return ptr;
}
