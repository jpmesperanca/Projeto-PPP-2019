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

Pdi cria_pdi(){
    Pdi aux;
    aux = (Pdi)malloc(sizeof(pdi_node));

    if (aux!=NULL){
        aux->nome=malloc(vinte5*sizeof(char));
        aux->descricao=malloc(vinte5*sizeof(char));
        aux->horario=malloc(vinte5*sizeof(char));
        aux->pop=0;
        aux->prefered=0;
        aux->popnext=NULL;
        aux->abcnext=NULL;
    }
    return aux;
}

Local insere_local(Local first, char* sitio, Pdi pontosptr, int popularidade,int numero){

    Local novo = cria_local();
    Local aux = first;
    Local aux2 = first;

    while((aux->abcnext!=NULL)&&(strcmp(aux->abcnext->local, sitio)<0))
        aux = aux->abcnext;

    novo->abcnext = aux->abcnext;
    aux->abcnext = novo;
    novo->pontos = pontosptr;
    novo->pop = popularidade;
    novo->local = sitio;
    novo->pdinum = numero;

    while((aux2->popnext!=NULL)&&(popularidade<=aux2->popnext->pop))
        aux2 = aux2->popnext;

    novo->popnext= aux2->popnext;
    aux2->popnext = novo;

    return aux->abcnext;
}

void insere_pdi(Local inicial, char* place, char* descricao, char* horario, int popularidade){

    Pdi first = inicial->pontos;
    Pdi novo = cria_pdi();
    Pdi aux = first;
    Pdi aux2 = first;

    while((aux->abcnext!=NULL)&&(strcmp(aux->abcnext->nome, place)<0))
        aux = aux->abcnext;

    novo->nome = place;
    novo->descricao = descricao;
    novo->horario = horario;
    novo->pop = popularidade;

    novo->abcnext = aux->abcnext;
    aux->abcnext = novo;

    while((aux2->popnext!=NULL)&&(popularidade<=aux2->popnext->pop))
        aux2 = aux2->popnext;

    novo->popnext= aux2->popnext;
    aux2->popnext = novo;

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
    }
    return aux;
}

Local openlocal(char *file){

    Local ptr=cria_local();
    Local localaux;
    Local aux=ptr;
    Pdi pdiptr;
    FILE *f=fopen(file,"r");
    char *info,*place,*descricao,*horario,*tudo,*sitio,etc;
    int numero,i;
    int pop;

    while(fscanf(f, "%c\n", &etc) == 1){   /* SALTAR \N */

        tudo = malloc(vinte5*sizeof(char));
        sitio = malloc(vinte5*sizeof(char));

        fgets(tudo, vinte5, f);
        sscanf(tudo, "%d %[^,], %d", &numero, sitio,&pop);

        pdiptr=cria_pdi();

        aux = insere_local(ptr, sitio, pdiptr, pop,numero);

        for (i=0; i<numero; i++){

            info=malloc(cem*sizeof(char));
            place=malloc(vinte5*sizeof(char));
            descricao=malloc(vinte5*sizeof(char));
            horario=malloc(vinte5*sizeof(char));

            fgets(info,cem,f);
            sscanf(info, "%[^,], %[^,], %[^,], %d",place,descricao,horario,&pop);

            insere_pdi(aux,place,descricao,horario,pop);
        }

        if (aux!=NULL)
            aux=aux->abcnext;

    }

    fclose(f);
    return ptr;
}


void filelocais(char *file,Local placesptr){
    int counter=0;
    Local aux=placesptr->popnext;
    Pdi pdi;
    FILE *f=fopen(file,"w");

    while (aux!=NULL){
        if (counter==0){
            fprintf(f,"\n");
            counter++;
        }
        else{
            fprintf(f,"\n\n");
        }
        fprintf(f,"%d %s, %d\n",aux->pdinum,aux->local,aux->pop);
        pdi=aux->pontos->popnext;
        while (pdi!=NULL){
            if (pdi->popnext==NULL)
                fprintf(f,"%s, %s, %s, %d",pdi->nome,pdi->descricao,pdi->horario,pdi->pop);
            else
                fprintf(f,"%s, %s, %s, %d\n",pdi->nome,pdi->descricao,pdi->horario,pdi->pop);
            pdi=pdi->popnext;
        }
        aux=aux->popnext;
    }
}
