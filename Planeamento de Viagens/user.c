#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#define cinq 50
#define cem 100
#define tele 10
#define huge 400



nodeptr cria_user(){
    nodeptr aux;
    aux=(nodeptr)malloc(sizeof(utilizador_node));

    if (aux!=NULL){
        aux->name=malloc(cinq*sizeof(char));
        aux->adress=malloc(cem*sizeof(char));
        aux->date=malloc(cinq*sizeof(char));
        aux->phone=malloc(tele*sizeof(char));
        aux->local=malloc(huge*sizeof(char));
        aux->pdi=malloc(huge*sizeof(char));
        aux->ptrlista = cria_nomes();
        aux->next=NULL;
    }
    return aux;
}


listanomesptr cria_nomes(){
    listanomesptr aux;
    aux=(listanomesptr)malloc(sizeof(listanomes_node));

    if (aux!=NULL){
        aux->nome = malloc(cinq*sizeof(char));
        aux->next = NULL;
    }

    return aux;
}


nodeptr insere(nodeptr fnl,char *nome,char *morada,char *data,char *telefone,char *local, char* pdi){
    nodeptr aux=fnl;
    listanomesptr p;
    int num,i;
    char *str = malloc(huge*sizeof(char));

    aux->name=nome;
    aux->adress=morada;
    aux->date=data;
    aux->phone=telefone;

    sscanf(local,"%d/%[^\n]",&num,str);
    p = aux->ptrlista;

    for(i=0;i<num;i++){

        if (i==0){
            p->nome = strtok(str,"/");
            p->next = cria_nomes();
            puts(p->nome);
        }

        else if (i==num){
            p->nome = strtok(NULL,"\n");
            p->next = cria_nomes();
        }

        else{
            p->nome = strtok(NULL,"/");
            p->next = cria_nomes();
        }
        p = p -> next;
    }

    aux->local=local;
    aux->pdi=pdi;

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


void preferedfile(nodeptr ptr,Local placesptr){
    nodeptr aux=ptr;
    Local placesaux=placesptr->abcnext;
    Pdi pdis;
    int i=0,num=0;
    char *str=malloc(huge*sizeof(char));


        sscanf(aux->local,"%d/%[^\n]",&num,str);

        for(i=0;i<num;i++){

            if (i==0)
                str=strtok(str,"/");

            else if (i==num)
                str=strtok(NULL,"\n");

            else
                str=strtok(NULL,"/");

            placesaux=placesptr->abcnext;

        while (placesaux!=NULL){

            if (strcmp(placesaux->local,str)==0){
                placesaux->prefered++;
                break;
            }

            placesaux=placesaux->abcnext;
        }

    }
    free(str);
    str=malloc(huge*sizeof(char));
    /* PONTOS DE INTERESSE */
    sscanf(aux->pdi,"%d/%[^\n]",&num,str);

    for(i=0;i<num;i++){

        if (i==0)
            str=strtok(str,"/");

        else if (i==num)
            str=strtok(NULL,"\n");

        else
            str=strtok(NULL,"/");

        placesaux=placesptr->abcnext;

        while (placesaux!=NULL){

            pdis=placesaux->pontos->abcnext;
            while (pdis!=NULL){
                if (strcmp(pdis->nome,str)==0){
                    pdis->prefered++;
                    break;
                }
                pdis=pdis->abcnext;
            }
            placesaux=placesaux->abcnext;
        }
    }
}


nodeptr openfile(char *file,nodeptr ptr){

    nodeptr aux=ptr;
    FILE *f=fopen(file,"r");
    char *nome,*adereco,*data,*telefone,*local,*pdi;
    char etc;


    while(fscanf(f, "%c\n", &etc) == 1){  /* SALTAR \N */

        fflush(stdin);
        nome=malloc(cinq*sizeof(char));
        adereco=malloc(cem*sizeof(char));
        data=malloc(cinq*sizeof(char));
        telefone=malloc(tele*sizeof(char));
        local=malloc(huge*sizeof(char));
        pdi=malloc(huge*sizeof(char));

        fgets(nome,cinq,f);
        nome=strtok(nome,"\n");

        fgets(adereco,cem,f);
        adereco=strtok(adereco,"\n");

        fgets(data,cinq,f);
        data=strtok(data,"\n");

        fgets(telefone,tele,f);
        telefone=strtok(telefone,"\n");

        fgets(local,huge,f);
        local=strtok(local,"\n");

        fgets(pdi,huge,f);
        pdi=strtok(pdi,"\n");

        aux=insere(aux,nome,adereco,data,telefone,local,pdi);
    }
    fclose(f);
    return aux;
}


int prefcountlocais(Local placesptr){
    Local localaux=placesptr->abcnext;
    int prefcount=0;
    while(localaux!=NULL){  /* DISCOVER THE NUMBER OS PREFERED LOCALS */
        if (localaux->prefered==1)
            prefcount++;
        localaux=localaux->abcnext;
    }
    return prefcount;
}


int prefcountpdis(Local placesptr){
    Local localaux=placesptr->abcnext;
    Pdi aux;
    int prefcount=0;
    while(localaux!=NULL){
        aux=localaux->pontos->abcnext;
        while (aux!=NULL){
            if (aux->prefered>=1)
                prefcount++;
            if (aux->prefered==2)
                prefcount++;
            aux=aux->abcnext;
        }
        localaux=localaux->abcnext;
    }
    return prefcount;
}


void inserefile(nodeptr ptr,Local placesptr){
    nodeptr aux=ptr;
    Local localaux=placesptr->abcnext;
    Pdi pdiaux;
    int i=0,count=0;
    char *endlocal=(char *)malloc(huge*sizeof(char));
    char *endpdi=(char *)malloc(huge*sizeof(char));
    strcpy(endlocal,"/");
    strcpy(endpdi,"/");

    while(localaux!=NULL){
        if (localaux->prefered==1){
            if (count==0){
                strcat(endlocal,localaux->local);
                count=1;
            }
            else{
                strcat(endlocal,"/");
                strcat(endlocal,localaux->local);
            }
        }
        localaux=localaux->abcnext;
    }

    count=0;
    localaux=placesptr->abcnext;

    while(localaux!=NULL){
        pdiaux=localaux->pontos->abcnext;

        while (pdiaux!=NULL){
            if (pdiaux->prefered==2){
                for(i=0;i<2;i++){
                    if (count==0){
                        strcat(endpdi,pdiaux->nome);
                        count=1;
                    }
                    else{
                        strcat(endpdi,"/");
                        strcat(endpdi,pdiaux->nome);
                    }
                }
            }
            if (pdiaux->prefered==1){
                 if (count==0){
                        strcat(endpdi,pdiaux->nome);
                        count=1;
                    }
                else{
                    strcat(endpdi,"/");
                    strcat(endpdi,pdiaux->nome);
                }
            }
            pdiaux=pdiaux->abcnext;
        }
        localaux=localaux->abcnext;
    }
    aux->local=endlocal;
    aux->pdi=endpdi;
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
