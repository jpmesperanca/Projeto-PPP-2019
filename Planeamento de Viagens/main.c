
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <locale.h>
#include "user.h"
#include "locais.h"
#define cem 100
#define cinq 50
#define tele 10

nodeptr login(nodeptr first,Local placesptr){

    char *nome= malloc(cinq*sizeof(char));
    nodeptr aux;


    while (1){
        aux = first;

        printf("\n...................... Login .....................\n.......... Escreva quit para regressar ...........\n\n");
        printf("Nome de Utilizador: ");
        fgets(nome,cinq,stdin);
        fflush(stdin);
        if(strcmp(nome,"\n")==0){
            system("cls");
        }
        else{

            nome=strtok(nome,"\n");
            if (strcmp(nome,"quit")==0)
                return NULL;


            while(aux->next != NULL){
                if (strcmp(nome,aux->name)==0){
                    preferedfile(aux,placesptr);
                    return aux;
                }
                aux=aux->next;
            }
            system("cls");
            printf("\n\tNome de Utilizador Nao Encontrado...\n");
        }
    }
}


void printreset(char *name,char *adress){
    fflush(stdin);
    system("cls");
    printf("\n\t  //////// Data Invalida ///////\n");
    printf("\n.......... Inscricao de Novo utilizador ..........\n.......... Escreva quit para regressar ...........\n\n");
    printf("Nome de Utilizador: %s",name);
    printf("\nMorada: %s\n",adress);
}


nodeptr regist(nodeptr first){

    char *name= malloc(cinq*sizeof(char));
    char *adress= malloc(cem*sizeof(char));
    char *phone= malloc(tele*sizeof(char));
    nodeptr aux;
    int num = 0;
    char *dia=malloc(tele*sizeof(char));
    char *mes=malloc(tele*sizeof(char));
    char *ano=malloc(tele*sizeof(char));
    int day,month,year;
    int bisexto=4;
    int i=0;



    while (num == 0){

        aux=first;
        num = 1;
        printf("\n.......... Inscricao de Novo utilizador ..........\n.......... Escreva quit para regressar ...........\n\n");

        printf("Nome de Utilizador: ");

        fgets(name,cinq,stdin);
        fflush(stdin);

        if (strcmp(name,"\n")==0){
            system("cls");
            printf("\n\t  //////// Utilizador invalido ///////\n");
            num = 0;
        }
        else{
            name=strtok(name,"\n");
            if (strcmp(name,"quit")==0)
                return NULL;

            while(aux->next != NULL){
                if (strcmp(name,aux->name)==0){                               /* Ve se o nome de utilizador ja existe*/
                    system("cls");
                    printf("\n\t  ###### Utilizador em uso ######\n\n");
                    num = 0;
                }
                aux=aux->next;
            }
        }
    }
    num=0;

    while (num==0){
        printf("Morada: ");

        num=1;
        fgets(adress,cem,stdin);
        fflush(stdin);
        if (strcmp(adress,"\n")==0){
            system("cls");
            printf("\n\t  //////// Morada Invalida ///////\n");
            printf("\n.......... Inscricao de Novo utilizador ..........\n.......... Escreva quit para regressar ...........\n\n");
            printf("Nome de Utilizador: %\n",name);
            num = 0;
        }
        else{
            adress=strtok(adress,"\n");
            if (strcmp(adress,"quit")==0)
                    return NULL;
        }
    }

    num=0;
    while (num==0){
        num=1;
        printf("Data de Nascimento: ");
        printf("\n\t Dia: ");
        fgets(dia, 4, stdin);
        if (strcmp(dia,"\n")==0){
            printreset(name,adress);
            num = 0;
            continue;
        }
        else{
            dia=strtok(dia,"\n");
            for(i=0;i<strlen(dia);i++){
                if (*(dia+i)<'0' || *(dia+i)>'~0'){
                    printreset(name,adress);
                    num=0;

                }
            }
            if (num==0)continue;
            day=atoi(dia);
            if ((day < 1 || day > 31)) {   /* Caso o Utilizador nao EscolhaEscolha uma das 2 opcoes */
                printreset(name,adress);
                num = 0;
                continue;
            }
        }

        fflush(stdin);
        printf("\t Mes: ");
        fgets(mes, 4, stdin);
        if (strcmp(mes,"\n")==0){
            printreset(name,adress);
            num = 0;
            continue;

        }
        else{
            mes=strtok(mes,"\n");
            for(i=0;i<strlen(mes);i++){
                if (*(mes+i)<'0' || *(mes+i)>'9'){
                    printreset(name,adress);
                    num=0;
                    continue;
                }
            }
            if (num==0)continue;
            month=atoi(mes);
            if ((month < 1 || month > 12) || (month==4 && day>30) || (month==6 && day>30) || (month==8 && day>30)|| (month==11 && day>30)|| (month==2 && day>29)) {    /* Caso o Utilizador nao EscolhaEscolha uma das 2 opcoes */
                printreset(name,adress);
                num = 0;
                continue;
            }
        }

        fflush(stdin);
        printf("\t Ano: ");
        fflush(stdin);
        fgets(ano, 6, stdin);
        if (strcmp(ano,"\n")==0){
            printreset(name,adress);
            num = 0;
            continue;
        }
        else{
            ano=strtok(ano,"\n");
            for(i=0;i<strlen(ano);i++){
                if (*(mes+i)<'0' || *(mes+i)>'9'){
                    printreset(name,adress);
                    num=0;
                    continue;
                }
            }
            if (num==0)continue;
            year=atoi(ano);
            if ((year < 1888 || year > 2010) || ((year%bisexto)!=0 && day==29 && month==2)) {   /* Caso o Utilizador nao EscolhaEscolha uma das 2 opcoes */
                printreset(name,adress);
                num = 0;
                continue;
            }
        }

    }

    num=0;
    while (num==0){

        printf("Telefone: ");

        num=1;
        fgets(phone,tele,stdin);
        fflush(stdin);
        if (strcmp(phone,"\n")==0){
            system("cls");
            printf("\n\t  //////// Telefone Invalido ///////\n");
            printf("\n.......... Inscricao de Novo utilizador ..........\n.......... Escreva quit para regressar ...........\n\n");
            printf("Nome de Utilizador: %s",name);
            printf("\nMorada: %s",adress);
            printf("\nData de Nascimento: %d/%d/%d\n",dia,mes,ano);
            num = 0;
        }
        else{
            phone=strtok(phone,"\n");
            if (strcmp(phone,"quit")==0)
                    return NULL;
            for (i=0;i<9;i++){

                if (*(phone+i)<'0' || *(phone+i)>'9' || strlen(phone)!=9){
                    system("cls");
                    printf("\n\t  //////// Telefone Invalido ///////\n");
                    printf("\n.......... Inscricao de Novo utilizador ..........\n.......... Escreva quit para regressar ...........\n\n");
                    printf("Nome de Utilizador: %s",name);
                    printf("\nMorada: %s",adress);
                    printf("\nData de Nascimento: %d/%d/%d\n",dia,mes,ano);
                    num=0;

                }
            }
        }
    }
    while(aux->next != NULL){
            aux=aux->next;
    }

    insere(aux,name,adress,day,month,year,phone,"0/","0/");

    return aux;
}


nodeptr menulogin(nodeptr first, Local placesptr){

    int num=0;
    nodeptr userptr;

    while (num == 0){
        printf("\n.......................");
        printf("\n\t -Menu-");
        printf("\n1 - Login");
        printf("\n2 - Registar");
        printf("\n.......................\n");
        printf("\nEscolha: ");

        if (scanf("%d",&num) == 0 || (num < 1 || num > 2)) {   /* Caso o Utilizador nao EscolhaEscolha uma das 2 opcoes */
            fflush(stdin);
            system("cls");
            num = 0;
        }
    }

    fflush(stdin);
    system("cls");

    switch (num){

            case 1:
                userptr=login(first,placesptr);break;
            case 2:
                userptr=regist(first);break;
    }

    return userptr;
}


void printadados(nodeptr userptr){
    printf("\n*******************************\n");
    printf("Nome de Utilizador: %s\n",userptr->name);
    printf("Morada: %s\n",userptr->adress);
    printf("Data de Nascimento: %d/%d/%d\n",userptr->day,userptr->month,userptr->year);
    printf("Telefone: %s\n",userptr->phone);
    printf("*******************************\n");
}


void logout(nodeptr first,nodeptr user,Local placesptr){
    nodeptr aux=first;
    listanomesptr list;
    int counter=0;
    FILE *f=fopen("users.txt","w");

    while (aux->next!=NULL){
        if (counter==0){
            fprintf(f,"\n");
            counter++;
        }
        else{
            fprintf(f,"\n\n");
        }
        fprintf(f,"%s\n",aux->name);
        fprintf(f,"%s\n",aux->adress);
        fprintf(f,"%d/%d/%d\n",aux->day,aux->month,aux->year);
        fprintf(f,"%s\n",aux->phone);


        list=aux->ptrlocal;
        fprintf(f,"%d",countlist(list));

        while (list->next!=NULL){
            fprintf(f,"/%s",list->nome);
            list=list->next;
        }

        list=aux->ptrpdi;
        fprintf(f,"\n%d",countlist(list));
        while (list->next!=NULL){
            if (list->hot==1)
                fprintf(f,"/%s",list->nome);
            fprintf(f,"/%s",list->nome);
            list=list->next;
        }
    aux=aux->next;
    }
    fclose(f);
    printf("\n     -Logged out com sucesso-\n");
}


int menualtera(nodeptr userptr,nodeptr first){

    int num=0;
    printadados(userptr);
    printf("\n.........................");
    printf("\n     -Alterar Dados-\n");
    printf("\n1 - Utilizador");
    printf("\n2 - Morada");
    printf("\n3 - Data de Nascimento");
    printf("\n4 - Telefone");
    printf("\n5 - Back");
    printf("\n.........................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 5)){  /* Caso o Utilizador nao Escolha uma das opcoes */
        fflush(stdin);
        system("cls");
        return 21;
    }

    fflush(stdin);
    system("cls");

    switch (num){
            case 1:
                return 21; /*Altera user*/
            case 2:
                return 22; /*Altera morada*/
            case 3:
                return 23; /*Altera data*/
            case 4:
                return 24; /*Altera phone*/
            case 5:
                return 1; /* Vai para o perfil */

    }
    return 100;
}


int perfil(nodeptr userptr, nodeptr first){

    int num=0;
    printadados(userptr);
    printf("\n.........................");
    printf("\n\t -Perfil-\n");
    printf("\n1 - Alterar dados");
    printf("\n2 - Back");
    printf("\n.........................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 2)){   /* Caso o Utilizador nao Escolha uma das 4 opcoes */
        fflush(stdin);
        system("cls");
        return 2;
    }

    fflush(stdin);
    system("cls");

    switch (num){
            case 1:
                return 22; /* Mostrar os dados */
            case 2:
                return 21; /* Alterar Dados */
            case 3:
                return 1; /*Back to main menu*/
    }
    return 100;
}


Local localpos(Local placesptr,int num,int check){
    int count=1;
    if (check==0){
        Local localaux=placesptr->abcnext;
        while (count!=num){
            count++;
            localaux=localaux->abcnext;
        }
        return localaux;
    }
    else{
        Local localaux=placesptr->popnext;
        while (count!=num){
            count++;
            localaux=localaux->popnext;
        }
        return localaux;
    }
}


int addlocaisabc(nodeptr userptr, Local placesptr){
    int num,i=1,prefcount=0;
    Local localaux=placesptr->abcnext;

    printf("\n..................................");
    printf("\n\t -Locais Alfabeticamente-");
    printf("\n..................................");
    printf("\n Escolha os seus Locais favoritos");
    printf("\n..................................");

    while(localaux!=NULL){
        if (localaux->prefered==0)
            printf("\n%2d - %s",i++,localaux->local);
        else if (localaux->prefered==1)
            printf("\n%2d - %s *FAVORITO*",i++,localaux->local);
        localaux=localaux->abcnext;
    }
    printf("\n\n  0 - Back");
    printf("\n..................................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 0 || num > i-1)){   /* Caso o Utilizador nao Escolha uma das opcoes */

        fflush(stdin);
        system("cls");
        return 312;
    }


    if (num==0){              /* BACK OPTION */

        fflush(stdin);
        system("cls");
        return 31;
    }

    prefcount=prefcountlocais(placesptr);

    localaux=localpos(placesptr,num,0);

    if(prefcount==3 && localaux->prefered==0){
        fflush(stdin);
        system("cls");
        printf("Remova 1 Local Preferido antes de escolher outro");
        return 312;
    }

    if (localaux->prefered==1){         /* WAS IT ALREADY SELECTED? */
            localaux->prefered=0;
            localaux->pop--;
            prefcount--;
    }
    else{
    localaux->prefered++;               /* FINAL DECISION */
    localaux->pop++;
    prefcount++;
    }

    reorganiza_pop(placesptr,localaux);
    fflush(stdin);
    system("cls");
    return 312;
}


int addlocaispop(nodeptr userptr, Local placesptr){
    int num,i=1,prefcount=0;
    Local localaux=placesptr->popnext;

    printf("\n..................................");
    printf("\n\t -Locais Popularidade-");
    printf("\n..................................");
    printf("\n Escolha os seus Locais favoritos");
    printf("\n..................................");

    while(localaux!=NULL){
        if (localaux->prefered==0)
            printf("\n%2d - %s",i++,localaux->local);
        else if (localaux->prefered==1)
            printf("\n%2d - %s *FAVORITO*",i++,localaux->local);
        localaux=localaux->popnext;
    }
    printf("\n\n  0 - Back");
    printf("\n..................................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 0 || num > i-1)){   /* Caso o Utilizador nao Escolha uma das opcoes */

        fflush(stdin);
        system("cls");
        return 311;
    }


    if (num==0){              /* BACK OPTION */

        fflush(stdin);
        system("cls");
        return 31;
    }

    prefcount=prefcountlocais(placesptr);

    localaux=localpos(placesptr,num,1);

    if(prefcount==3 && localaux->prefered==0){
        fflush(stdin);
        system("cls");
        printf("Remova 1 Local Preferido antes de escolher outro");
        return 311;
    }

    if (localaux->prefered==1){         /* WAS IT ALREADY SELECTED? */
            localaux->prefered=0;
            localaux->pop--;
            prefcount--;
    }
    else{
    localaux->prefered++;               /* FINAL DECISION */
    localaux->pop++;
    prefcount++;
    }

    fflush(stdin);
    system("cls");
    return 311;
}


int pop_or_abc(nodeptr userptr, Local placesptr, int check){
    int num;
    printf("\n....................................");
    if (check==1)
        printf("\n\t     -Locais-");
    else
        printf("\n\t-Pontos de Interesse-");
    printf("\n....................................");
    printf("\nOrdenar por:");
    printf("\n\n1 - Popularidade");
    printf("\n2 - Alfabeticamente");
    printf("\n3 - Back");
    printf("\n....................................");
    printf("\nEscolha:");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 3)){   /* Caso o Utilizador nao Escolha uma das opcoes */

        fflush(stdin);
        system("cls");
        return 31;
    }
    fflush(stdin);
    system("cls");
    switch (num){
            case 1:
                if (check==1)
                    return 311;              /*Vai para o Locais */
                else
                    return 321;
            case 2:
                if (check==1)
                    return 312;              /*Vai para pdi */
                else
                    return 322;
            case 3:
                return 3;              /*vai para Back */

    }
    return 100;
}


int addpdisabc(nodeptr userptr, Local placesptr){
    int num=0,i=1,count=1,prefcount=0,hot=0;
    Local localaux=placesptr->abcnext;
    Pdi shortener, pdiaux;
    printf("\n..................................");
    printf("\n\t -Adicionar PDI's-");
    printf("\n..................................");
    printf("\n  Escolha os seus PDI favoritos");
    printf("\n  Escolha um PDI favorito para o\n  tornar HOT");
    printf("\n..................................");

    while(localaux!=NULL){
        pdiaux=localaux->pontos->abcnext;
        printf("\n %s:",localaux->local);
        while(pdiaux!=NULL){
            if (pdiaux->prefered==0)
                printf("\n\t%2d - %s",i++,pdiaux->nome,localaux->local);
            else if (pdiaux->prefered==1)
                printf("\n\t%2d - %s  *FAVORITO*",i++,pdiaux->nome,localaux->local);
            else if (pdiaux->prefered==2)
                printf("\n\t%2d - %s  *HOT*",i++,pdiaux->nome,localaux->local);
            pdiaux=pdiaux->abcnext;
        }
        printf("\n");
        localaux=localaux->abcnext;
    }
    printf("\n\n 0 - Back");
    printf("\n..................................");
    printf("\nEscolha:");

    if (scanf("%d",&num) == 0 || (num < 0 || num > i-1)){   /* Caso o Utilizador nao Escolha uma das opcoes */

        fflush(stdin);
        system("cls");
        return 322;
    }

    if (num==0){              /* BACK OPTION */
        fflush(stdin);
        system("cls");
        return 32;
    }

    localaux=placesptr->abcnext;
    while(localaux!=NULL){     /* DISCOVER THE NUMBER OS PREFERED LOCALS */
        pdiaux=localaux->pontos->abcnext;
        while(pdiaux!=NULL){
            if (pdiaux->prefered>=1){
                prefcount++;
                if (pdiaux->prefered==2)
                    hot=1;
            }
            if (count==num)
                shortener=pdiaux;
            pdiaux=pdiaux->abcnext;
            count++;
        }
        localaux=localaux->abcnext;
    }

    pdiaux=shortener;
    if (pdiaux->prefered==2){         /* WAS IT ALREADY SELECTED? */
        pdiaux->prefered=0;
        pdiaux->pop--;
        prefcount--;
    }
    else if (pdiaux->prefered==1 && hot==1){
        pdiaux->prefered=0;
        pdiaux->pop--;
        prefcount--;
    }
    else if (pdiaux->prefered==1 && hot==0){
        pdiaux->prefered=2;
    }
    else{
        if (pdiaux->prefered==0)
            prefcount++;
        pdiaux->prefered++;
        pdiaux->pop++;

    }

    reorganiza_pop_p(placesptr,pdiaux);
    fflush(stdin);
    system("cls");
    return 322;
}


int addpdispop(nodeptr userptr, Local placesptr){
    int num=0,i=1,count=1,prefcount=0,hot=0;
    Local localaux=placesptr->popnext;
    Pdi shortener, pdiaux;
    printf("\n..................................");
    printf("\n\t -Adicionar PDI's-");
    printf("\n..................................");
    printf("\n  Escolha os seus PDI favoritos");
    printf("\n  Escolha um PDI favorito para o\n  tornar HOT");
    printf("\n..................................");

    while(localaux!=NULL){
        pdiaux=localaux->pontos->popnext;
        printf("\n %s:",localaux->local);
        while(pdiaux!=NULL){
            if (pdiaux->prefered==0)
                printf("\n\t%2d - %s",i++,pdiaux->nome,localaux->local);
            else if (pdiaux->prefered==1)
                printf("\n\t%2d - %s  *FAVORITO*",i++,pdiaux->nome,localaux->local);
            else if (pdiaux->prefered==2)
                printf("\n\t%2d - %s  *HOT*",i++,pdiaux->nome,localaux->local);
            pdiaux=pdiaux->popnext;
        }
        printf("\n");
        localaux=localaux->popnext;
    }
    printf("\n\n  0 - Back");
    printf("\n..................................");
    printf("\nEscolha:");

    if (scanf("%d",&num) == 0 || (num < 0 || num > i-1)){   /* Caso o Utilizador nao Escolha uma das opcoes */

        fflush(stdin);
        system("cls");
        return 321;
    }

    if (num==0){              /* BACK OPTION */
        fflush(stdin);
        system("cls");
        return 32;
    }

    localaux=placesptr->popnext;
    while(localaux!=NULL){     /* DISCOVER THE NUMBER OS PREFERED LOCALS */
        pdiaux=localaux->pontos->popnext;
        while(pdiaux!=NULL){
            if (pdiaux->prefered>=1){
                prefcount++;
                if (pdiaux->prefered==2)
                    hot=1;
            }
            if (count==num)
                shortener=pdiaux;
            pdiaux=pdiaux->popnext;
            count++;
        }
        localaux=localaux->popnext;
    }

    pdiaux=shortener;
    if (pdiaux->prefered==2){         /* WAS IT ALREADY SELECTED? */
        pdiaux->prefered=0;
        pdiaux->pop--;
        prefcount--;
    }
    else if (pdiaux->prefered==1 && hot==1){
        pdiaux->prefered=0;
        pdiaux->pop--;
        prefcount--;
    }
    else if (pdiaux->prefered==1 && hot==0){
        pdiaux->prefered=2;
    }
    else{
        if (pdiaux->prefered==0)
            prefcount++;
        pdiaux->prefered++;
        pdiaux->pop++;

    }

    fflush(stdin);
    system("cls");
    return 321;
}


int preferencias(nodeptr user, Local placesptr){
    int num=0;

    printf("\n..................................");
    printf("\n\t -Preferencias-\n");
    printf("\n1 - Locais");
    printf("\n2 - Pontos De Interesse");
    printf("\n3 - Back");
    printf("\n..................................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 5)){   /* Caso o Utilizador nao Escolha uma das opcoes */
        fflush(stdin);
        system("cls");
        printf("%d",num);
        return 3;
    }
    fflush(stdin);
    system("cls");
    rewritelista(user,placesptr);

    switch (num){
            case 1:
                return 31;              /*Vai para o Locais */
            case 2:
                return 32;              /*Vai para pdi */
            case 3:
                return 1;              /*vai para Back */

    }
    return 100;
}


void tripcheckreset(nodeptr userptr){
    nodeptr aux=userptr;

    while(aux->next!=NULL){
        aux->tripcheck=0;
        aux=aux->next;
    }
}


int viagemcounterlocais(nodeptr userptr,char * str){
    int count=0;
    nodeptr aux=userptr;
    listanomesptr list;

    while (aux->next!=NULL){
        list=aux->ptrlocal;
        if (aux->tripcheck==0){
            while(list->next!=NULL){
                if (strcmp(list->nome,str)==0){
                    count++;
                    aux->tripcheck=1;
                    break;
                }
                list=list->next;
            }
        }
        aux=aux->next;
    }
    return count;
}


int viagemcounterhot(nodeptr userptr,char * str){
    int count=0;
    nodeptr aux=userptr;
    listanomesptr list;

    while (aux->next!=NULL){
        list=aux->ptrpdi;
        if (aux->tripcheck==0){
            while(list->next!=NULL){
                if (strcmp(list->nome,str)==0 && list->hot==1){
                    count++;
                    aux->tripcheck=1;
                    break;
                }
                list=list->next;
            }
        }
        aux=aux->next;
    }
    return count;
}


double contarpessoas(nodeptr first){
    double count=0.0;
    nodeptr aux=first;

    while (aux->next!=NULL){
        count++;
        aux=aux->next;
    }
    return count;
}


double contarpdis(Local placesptr){
    Local localaux=placesptr->abcnext;
    Pdi aux;
    double count=0.0;
    while(localaux!=NULL){
        aux=localaux->pontos->abcnext;
        while (aux!=NULL){
            count+=aux->pop;
            aux=aux->abcnext;
        }
        localaux=localaux->abcnext;
    }
    return count;
}


int viagem(nodeptr first,nodeptr user, Local placesptr){
    int count=prefcountlocais(placesptr);
    int localcount=0,pdicount=0,num;
    int percentagemlocais=0,percentagemhot=0,percentagempdi=0;
    double totalusers=contarpessoas(first);
    double totalpdi=contarpdis(placesptr);
    char *helper1=malloc(cinq*sizeof(char));
    char *helper2=malloc(cinq*sizeof(char));
    Local localaux=placesptr->abcnext;
    Pdi pdiaux;
    strcpy(helper1," ");
    strcpy(helper2," ");

    if (count<3){
        fflush(stdin);
        system("cls");
        printf("Nao tem 3 Locais Preferidos (%d)",count);
        return 1;
    }


    while (localcount!=count){

        if (localaux->prefered==1){
            localcount++;
            percentagemlocais+=viagemcounterlocais(first,localaux->local);
        }
        localaux=localaux->abcnext;
    }
    tripcheckreset(first);
    localcount=0;
    localaux=placesptr->abcnext;


    /* VIAGEM */

    while (localcount!=count){
        if (localaux->prefered==1){
            printf("%d) %s\n",++localcount,localaux->local);
            pdiaux=localaux->pontos->abcnext;
            while (pdiaux!=NULL){
                if (pdicount==3)
                    break;
                if (pdiaux->prefered==2){
                    printf("\t%d) %s, %s, %s\n",++pdicount,pdiaux->nome,pdiaux->descricao,pdiaux->horario);
                    percentagemhot+=viagemcounterhot(first,pdiaux->nome);
                    percentagempdi+=pdiaux->pop;
                    strcpy(helper1,pdiaux->nome);
                }
                pdiaux=pdiaux->abcnext;
            }
            pdiaux=localaux->pontos->popnext;

            while (pdiaux!=NULL){
                if (pdicount==3)break;

                if (pdiaux->prefered==1 && pdicount<3){
                    printf("\t%d) %s, %s, %s\n",++pdicount,pdiaux->nome,pdiaux->descricao,pdiaux->horario);
                    percentagemhot+=viagemcounterhot(first,pdiaux->nome);
                    percentagempdi+=pdiaux->pop;
                    if (pdicount==1)
                        strcpy(helper1,pdiaux->nome);
                    else if (pdicount==2)
                        strcpy(helper2,pdiaux->nome);
                }
                pdiaux=pdiaux->popnext;
            }

            pdiaux=localaux->pontos->popnext;
            while (pdiaux!=NULL){
                if (pdicount==3)break;
                if (pdicount<3 && strcmp(pdiaux->nome,helper1)!=0 && strcmp(pdiaux->nome,helper2)!=0){
                    printf("\t%d) %s, %s, %s\n",++pdicount,pdiaux->nome,pdiaux->descricao,pdiaux->horario);
                    percentagemhot+=viagemcounterhot(first,pdiaux->nome);
                    percentagempdi+=pdiaux->pop;
                }
                pdiaux=pdiaux->popnext;
            }
            pdicount=0;
        }
        localaux=localaux->abcnext;
        free(helper1);
        free(helper2);
    }

    tripcheckreset(first);
    printf("\n\n\tPercentagens Relacionadas com a Viagem\n\n");
    printf("->%.1f %% dos utilizadores têm pelo menos 1 local favorito entre os incluídos na sua viagem\n",100*(double)percentagemlocais/totalusers);
    printf("->%.1f %% dos utilizadores têm um dos pontos da viagem como Hot\n",100*(double)percentagemhot/totalusers);
    printf("->%.1f %% de popularidade dos PDI escolhidos \n",100*(double)percentagempdi/totalpdi);

    printf("\nDeseja Sair?\n");
    printf("\n1)Sim (Logout)");
    printf("\n2)Nao (Main Menu)");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 2)){   /* Caso o Utilizador nao Escolha uma das 2 opcoes */
        fflush(stdin);
        system("cls");
        printf("%d",num);
        return 4;
    }

    if (num==2){
        fflush(stdin);
        system("cls");
        return 1;
    }

    return 0;
}


int mainmenu(nodeptr user, nodeptr first,Local placesptr){

    int num=0;

    printf("\n..................................");
    printf("\n\t -Menu Principal-\n");
    printf("\n1 - Perfil");
    printf("\n2 - Preferencias");
    printf("\n3 - Gerar Viagem");
    printf("\n4 - Logout");
    printf("\n..................................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 4)){   /* Caso o Utilizador nao Escolha uma das opcoes */

        fflush(stdin);
        system("cls");
        printf("%d",num);
        return 1;
    }

    fflush(stdin);
    system("cls");

    switch (num){
            case 1:
                return 2;            /*Vai para o perfil*/
            case 2:
                return 3;              /*vai para as preferencias*/
            case 3:
                return 4;              /* vai para a viagem */
            case 4:
                return 0;               /* Logout */
    }
    return 100;
}


int main(){
    int num = 1;
    Local placesptr;
    nodeptr first,userptr;
    setlocale(LC_ALL,"Portuguese");
    placesptr = openlocal("locais.txt");

    first=cria_user();

    openfile("users.txt",first);

    do{
        userptr = menulogin(first,placesptr);
        system("cls");
    }while (userptr == NULL);

    printf("\n      -Logged in com sucesso-\n");
    printf("         Bem vindo, %s",userptr->name);
    while (num!=0){
        switch (num){
            case 1:
                num = mainmenu(userptr,first,placesptr);break;
                case 2:
                    num = menualtera(userptr,first);break;
                    case 21:
                        num = alterauser(userptr,first);break;
                    case 22:
                        num = alteramorada(userptr,first);break;
                    case 23:
                        num = alteradata(userptr,first);break;
                    case 24:
                        num = alteraphone(userptr,first);break;


                case 3:
                    num=preferencias(userptr,placesptr);break;
                    case 31:
                        num=pop_or_abc(userptr,placesptr,1);break;

                       case 311:
                            num=addlocaispop(userptr,placesptr);break;
                       case 312:
                            num=addlocaisabc(userptr,placesptr);break;
                    case 32:
                        num=pop_or_abc(userptr,placesptr,2);break;

                        case 321:
                            num=addpdispop(userptr,placesptr);break;
                        case 322:
                            num=addpdisabc(userptr,placesptr);break;
                case 4:
                    num = viagem(first,userptr,placesptr);break;
                case 100:
                    printf("\nBugsplat -- a funcao chegou ao fim!\n");num=0;break;


        }
    }
    rewritelista(userptr, placesptr);
    logout(first,userptr,placesptr);
    filelocais("locais.txt",placesptr);
    freeusers(first);
    freelistalocais(placesptr);

    return 0;
}
