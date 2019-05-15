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

Local ordena_abc(Local locaisptr, int n){

   /* int pass;
    Local head,prox,aux;

    for (pass=0; pass<n; pass++){

        head = locaisptr;
        prox = locaisptr->abcnext;

        while (prox->abcnext != NULL){
            if ( strcmp(head->local,prox->local) > 0 ){

                aux = prox->abcnext;
                prox->abcnext = head;
                head = head->abcnext;
                head->abcnext = aux;

            }
            else{
                head = head->abcnext;
                prox = prox->abcnext;}

        }
    }
    */


    Local localaux = head;
        int i = 0;
        while(localaux->abcnext!=NULL){
            if (localaux->prefered==0)
                printf("\n%d - %s",i++,localaux->local);
            else if (localaux->prefered==1)
                printf("\n%d - %s *Choosen*",i++,localaux->local);
            localaux=localaux->abcnext;}

    return head;
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

    ptr = ordena_abc(ptr,4);

    return ptr;
}
