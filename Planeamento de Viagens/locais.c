#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "locais.h"
#define VINTECINCO 25
#define CINQ 50
#define CEM 100

Pdi cria_pdi(){
    Pdi aux;
    aux = (Pdi)malloc(sizeof(pdi_node));

    if (aux!=NULL){
        aux->nome=malloc(VINTECINCO*sizeof(char));
        aux->descricao=malloc(VINTECINCO*sizeof(char));
        aux->horario=malloc(VINTECINCO*sizeof(char));
        aux->pop=0;
        aux->prefered=0;
        aux->popnext=NULL;
        aux->abcnext=NULL;
    }
    return aux;
}

Local insere_local(Local first, char* sitio, Pdi pontosptr, int popularidade,int numero,int prefered){

    Local novo = cria_local();
    Local aux = first;
    Local aux2 = first;

    while((aux->abcnext!=NULL)&&(strcmp(aux->abcnext->local, sitio)<0))
        aux = aux->abcnext;

    novo->abcnext = aux->abcnext;
    aux->abcnext = novo;

    novo->prefered = prefered;
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

void freelistapdis(Pdi ptr){

    Pdi aux = ptr->abcnext;

        while(ptr != NULL){

            free(ptr->nome);
            free(ptr->descricao);
            free(ptr->horario);
            aux = ptr->abcnext;
            free(ptr);
            ptr = aux;
        }
}

void freelocais(Local ptr){

    Local aux = ptr->abcnext;

        while(ptr != NULL){

            free(ptr->local);
            aux = ptr->abcnext;
            free(ptr);
            ptr = aux;
        }
}

void freelistalocais(Local ptr){

    Local aux2 = ptr;
    Local aux= ptr->abcnext;
    ptr=ptr->abcnext;


    while (aux != NULL){

        freelistapdis(aux->pontos);
        aux = aux->abcnext;
    }

    freelocais(aux2);
}

void reorganiza_pop(Local inicial, Local alterado){

    Local ant = inicial;
    Local antabc = inicial;
    Pdi novopdi;
    char* localnovo = malloc(CINQ*sizeof(char));
    int popnova, numeronovo,npdis;

    while(strcmp(antabc->abcnext->local, alterado->local)!= 0)
        antabc = antabc->abcnext;

    while(strcmp(ant->popnext->local, alterado->local)!= 0)
        ant = ant->popnext;

    ant->popnext = alterado->popnext;
    antabc->abcnext = alterado->abcnext;

    popnova = alterado->pop;
    numeronovo = alterado->prefered;
    npdis = alterado->pdinum;
    strcpy(localnovo, alterado->local);
    novopdi = alterado->pontos;

    free(alterado);
    insere_local(inicial,localnovo,novopdi,popnova,npdis,numeronovo);

}

void reorganiza_pop_p(Local inicial, Pdi alterado){

    Pdi ant,antabc;
    Local aux = inicial->abcnext;
    char* nomenovo = malloc(CINQ*sizeof(char));
    char* horarionovo = malloc(CINQ*sizeof(char));
    char* descricaonova = malloc(CINQ*sizeof(char));
    int popnova, numeronovo;
    int helper = 0;

    while(helper==0){
        antabc = aux->pontos;
        while(antabc->abcnext != NULL){
            if (strcmp(antabc->abcnext->nome, alterado->nome) == 0){
                helper = 1;
                break;
            }

            antabc = antabc->abcnext;
        }
        if (helper == 1)
            break;
        aux = aux->abcnext;
    }

    helper = 0;
    aux = inicial->popnext;

    while(helper==0){
        ant = aux->pontos;
        while(ant->popnext != NULL){
            if (strcmp(ant->popnext->nome, alterado->nome) == 0){
                helper = 1;
                break;
            }
            ant = ant->popnext;
        }
        if (helper == 1)
            break;
        aux = aux->popnext;
    }

    ant->popnext = alterado->popnext;
    antabc->abcnext = alterado->abcnext;

    popnova = alterado->pop;
    numeronovo = alterado->prefered;
    strcpy(nomenovo, alterado->nome);
    strcpy(horarionovo,alterado->horario);
    strcpy(descricaonova,alterado->descricao);

    free(alterado);

    insere_pdi(aux,nomenovo,descricaonova,horarionovo,popnova,numeronovo);
}

void insere_pdi(Local inicial, char* place, char* descricao, char* horario, int popularidade, int prefered){

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
    novo->prefered = prefered;

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
        aux->local=malloc(VINTECINCO*sizeof(char));
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
    Local aux=ptr;
    Pdi pdiptr;
    FILE *f=fopen(file,"r");
    char *info,*place,*descricao,*horario,*tudo,*sitio,etc;
    int numero,i;
    int pop;

    while(fscanf(f, "%c\n", &etc) == 1){   /* SALTAR \N */

        tudo = malloc(VINTECINCO*sizeof(char));
        sitio = malloc(VINTECINCO*sizeof(char));

        fgets(tudo, VINTECINCO, f);
        sscanf(tudo, "%d %[^,], %d", &numero, sitio,&pop);

        pdiptr=cria_pdi();

        aux = insere_local(ptr, sitio, pdiptr, pop,numero,0);

        for (i=0; i<numero; i++){

            info=malloc(CEM*sizeof(char));
            place=malloc(VINTECINCO*sizeof(char));
            descricao=malloc(VINTECINCO*sizeof(char));
            horario=malloc(VINTECINCO*sizeof(char));

            fgets(info,CEM,f);
            sscanf(info, "%[^,], %[^,], %[^,], %d",place,descricao,horario,&pop);

            insere_pdi(aux,place,descricao,horario,pop,0);
        }
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
