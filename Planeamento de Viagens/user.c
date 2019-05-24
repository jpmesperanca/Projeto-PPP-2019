#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#define cinq 50
#define cem 100
#define tele 11
#define huge 400
#define FIVE 5



nodeptr cria_user(){
    nodeptr aux;
    aux=(nodeptr)malloc(sizeof(utilizador_node));

    if (aux!=NULL){
        aux->name=malloc(cinq*sizeof(char));
        aux->adress=malloc(cem*sizeof(char));
        aux->day=0;
        aux->month=0;
        aux->year=0;
        aux->phone=malloc(tele*sizeof(char));
        aux->local=malloc(huge*sizeof(char));
        aux->pdi=malloc(huge*sizeof(char));
        aux->tripcheck=0;
        aux->ptrlocal = cria_nomes();
        aux->ptrpdi= cria_nomes();
        aux->next=NULL;
    }
    return aux;
}


listanomesptr cria_nomes(){
    listanomesptr aux;
    aux=(listanomesptr)malloc(sizeof(listanomes_node));

    if (aux!=NULL){
        aux->nome = malloc(cinq*sizeof(char));
        aux->hot=0;
        aux->next = NULL;
    }

    return aux;
}


int check(){

}


nodeptr insere(nodeptr fnl,char *nome,char *morada,int day,int month,int year,char *telefone,char *local, char* pdi){
    nodeptr aux=fnl;
    listanomesptr prefaux,helper;
    int num,i;
    char *str = malloc(huge*sizeof(char));

    aux->name=nome;
    aux->adress=morada;
    aux->day=day;
    aux->month=month;
    aux->year=year;
    aux->phone=telefone;

    sscanf(local,"%d/%[^\n]",&num,str);
    prefaux = aux->ptrlocal;

    for(i=0;i<num;i++){

        if (i==0){
            prefaux->nome = strtok(str,"/");
            prefaux->next = cria_nomes();
        }

        else if (i==num){
            prefaux->nome = strtok(NULL,"\n");
            prefaux->next = cria_nomes();
        }

        else{
            prefaux->nome = strtok(NULL,"/");
            prefaux->next = cria_nomes();
        }
        prefaux = prefaux -> next;
    }


    aux->local=local;
    aux->pdi=pdi;

    str = malloc(huge*sizeof(char));
    sscanf(pdi,"%d/%[^\n]",&num,str);
    prefaux = aux->ptrpdi;

    for(i=0;i<num;i++){

        if (i==0){
            prefaux->nome = strtok(str,"/");
        }

        else if (i==num){
            prefaux->nome = strtok(NULL,"\n");
        }

        else{
            prefaux->nome = strtok(NULL,"/");
        }
        helper=aux->ptrpdi;
        while (helper->next!=NULL){
            if (strcasecmp(prefaux->nome,helper->nome)==0){
                helper->hot=1;
                break;
            }
            helper=helper->next;
        }
        if (helper->hot==0){
            prefaux->next = cria_nomes();
            prefaux = prefaux -> next;
        }
        else
            free(prefaux->nome);
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
    printf("%d/%d/%d\n", pessoa->day,pessoa->month,pessoa->year);
    printf("%s \n", pessoa->phone);
    return 2;
}


void preferedfile(nodeptr ptr,Local placesptr){
    nodeptr aux=ptr;
    Local placesaux;
    listanomesptr str=aux->ptrlocal;
    Pdi pdis;
    while (str->next!=NULL){
        placesaux=placesptr->abcnext;
        while (placesaux!=NULL){
            if (strcmp(placesaux->local,str->nome)==0){
                placesaux->prefered++;
                break;
            }
            placesaux=placesaux->abcnext;
        }
        str=str->next;
    }
    str=aux->ptrpdi;
    while (str->next!=NULL){
        placesaux=placesptr->abcnext;
        while (placesaux!=NULL){
            pdis=placesaux->pontos->abcnext;
            while (pdis!=NULL){
                if (strcmp(pdis->nome,str->nome)==0){
                    pdis->prefered++;
                    break;
                }
                pdis=pdis->abcnext;
            }
        placesaux=placesaux->abcnext;
        }
        str=str->next;
    }
}


nodeptr openfile(char *file,nodeptr ptr){

    nodeptr aux=ptr;
    FILE *f=fopen(file,"r");
    char *nome,*adereco,*data,*telefone,*local,*pdi;
    char *day,*month,*year;
    int dia, mes, ano;
    char etc;


    while(fscanf(f, "%c\n", &etc) == 1){  /* SALTAR \N */

        fflush(stdin);
        nome=malloc(cinq*sizeof(char));
        adereco=malloc(cem*sizeof(char));
        data=malloc(cinq*sizeof(char));
        day=malloc(FIVE*sizeof(char));
        month=malloc(FIVE*sizeof(char));
        year=malloc(FIVE*sizeof(char));
        telefone=malloc(tele*sizeof(char));
        local=malloc(huge*sizeof(char));
        pdi=malloc(huge*sizeof(char));

        fgets(nome,cinq,f);
        nome=strtok(nome,"\n");

        fgets(adereco,cem,f);
        adereco=strtok(adereco,"\n");

        fgets(data,cinq,f);
        data=strtok(data,"\n");
        day=strtok(data,"/");
        month=strtok(NULL,"/");
        year=strtok(NULL,"\n");

        dia=atoi(day);
        mes=atoi(month);
        ano=atoi(year);

        fgets(telefone,tele,f);
        telefone=strtok(telefone,"\n");

        fgets(local,huge,f);
        local=strtok(local,"\n");

        fgets(pdi,huge,f);
        pdi=strtok(pdi,"\n");

        aux=insere(aux,nome,adereco,dia,mes,ano,telefone,local,pdi);
    }
    fclose(f);
    return aux;
}

void freenomes(listanomesptr ptr){

        listanomesptr aux = ptr->next;

        while(ptr->next != NULL){

            aux = ptr;
            ptr = ptr->next;
            free(aux);
        }
}

void printlistalocais(listanomesptr ptr){

    listanomesptr aux = ptr;

    while (aux->next != NULL){

        printf("%s\n", aux->nome);
        aux = aux->next;
    }
}

int countlist(listanomesptr ptr){
    listanomesptr aux=ptr;
    int count=0;
    while (aux->next!=NULL){
        if (aux->hot==1)
            count++;
        count++;
        aux=aux->next;
    }
    return count;
}


void rewritelista(nodeptr userptr, Local placesptr){

    Local placesaux = placesptr->abcnext;
    Pdi pdiaux;
    listanomesptr local;
    listanomesptr pdi;

    freenomes(userptr->ptrlocal);
    freenomes(userptr->ptrpdi);

    userptr->ptrlocal = cria_nomes();
    userptr->ptrpdi = cria_nomes();

    local = userptr->ptrlocal;
    pdi = userptr->ptrpdi;

    while(placesaux!=NULL){

        if (placesaux->prefered==1){

            local->next = cria_nomes();
            local->nome = placesaux->local;
            local=local->next;
        }

        pdiaux=placesaux->pontos->abcnext;

        while(pdiaux!=NULL){

            if (pdiaux->prefered==2){
                pdi->next =cria_nomes();
                pdi->nome=pdiaux->nome;
                pdi->hot=1;
                pdi=pdi->next;
            }
            if (pdiaux->prefered==1){
                pdi->next = cria_nomes();
                pdi->nome = pdiaux->nome;
                pdi = pdi->next;
            }
            pdiaux=pdiaux->abcnext;
        }
    placesaux=placesaux->abcnext;
    }
}


int prefcountlocais(Local placesptr){
    Local localaux=placesptr->abcnext;
    int prefcount=0;
    while(localaux!=NULL){
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

    printf("\n.......... Escreva quit para regressar ...........\n\n");
    printf("\nNome de Utilizador: ");
    fgets(input,cinq,stdin);
    fflush(stdin);
    system("cls");
    if(strcmp(input,"\n")==0){
       system("cls");
       return 6;
    }
    else{
        input=strtok(input,"\n");
        if (strcmp(input,"quit")==0)
            return 2;

        while(aux->next!=NULL){
            if (strcmp(input,aux->name)==0){                              /* Ve se o nome de utilizador ja existe*/
                system("cls");
                printf("\n\t  ###### Utilizador em uso ######\n");
                return 6;
            }
            aux=aux->next;
        }
}

userptr->name=input;
return 5;
}


int alteramorada(nodeptr userptr,nodeptr first){
    char *input=malloc(cem*sizeof(char));
    printf("\n.......... Escreva quit para regressar ...........\n\n");
    printf("\nMorada: ");
    fgets(input,cem,stdin);
    fflush(stdin);
    system("cls");
    if(strcmp(input,"\n")==0){
       system("cls");
       return 7;
    }
    else{
       input=strtok(input,"\n");
        if (strcmp(input,"quit")==0)
            return 2;
        else{
            userptr->adress=input;
            return 5;
        }
    }

}


int alteradata(nodeptr userptr,nodeptr first){
    int dia,mes,ano;
    int bisexto=4;
    printf("Data de Nascimento: ");
    printf("\n\t Dia: ");
    if (scanf("%d",&dia) == 0 || (dia < 1 || dia > 31)) {   /* Caso o Utilizador nao EscolhaEscolha uma das 2 opcoes */
        fflush(stdin);
        system("cls");
        printf("\n\t  //////// Data Invalida ///////\n");
        return 8;
    }
    fflush(stdin);

    printf("\t Mes: ");
    if (scanf("%d",&mes) == 0 || (mes < 1 || mes > 12) || (mes==4 && dia>30) || (mes==6 && dia>30) || (mes==8 && dia>30)|| (mes==11 && dia>30)|| (mes==2 && dia>29)) {   /* Caso o Utilizador nao EscolhaEscolha uma das 2 opcoes */
        fflush(stdin);
        system("cls");
        printf("\n\t  //////// Data Invalida ///////\n");
        return 8;
    }
    fflush(stdin);

    printf("\t Ano: ");
    if (scanf("%d",&ano) == 0 || (ano < 1888 || ano > 2010) || ((ano%bisexto)!=0 && dia==29 && mes==2)) {   /* Caso o Utilizador nao EscolhaEscolha uma das 2 opcoes */
        fflush(stdin);
        system("cls");
        printf("\n\t  //////// Data Invalida ///////\n");
        return 8;
    }
    fflush(stdin);
    return 5;
}


int alteraphone(nodeptr userptr,nodeptr first){
    char *phone=malloc(tele*sizeof(char));
    int i=0;

    printf("\n.......... Escreva quit para regressar ...........\n\n");
    printf("Telefone: ");
    fgets(phone,tele,stdin);
    fflush(stdin);
    if (strcmp(phone,"\n")==0){
        system("cls");
        printf("\n\t  //////// Telefone Invalido ///////\n");
    }
    else{
        phone=strtok(phone,"\n");
        if (strcmp(phone,"quit")==0)
                return NULL;
        for (i=0;i<9;i++){

            if (*phone+i<'0' || *phone+i>'9' || strlen(phone)<9){
                system("cls");
                printf("\n\t  //////// Telefone Invalido ///////\n");
            }
        }
    }
}
