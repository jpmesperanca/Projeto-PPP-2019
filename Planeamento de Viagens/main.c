#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


nodeptr regist(nodeptr first){

    char *name= malloc(cinq*sizeof(char));
    char *adress= malloc(cem*sizeof(char));
    char *date= malloc(cinq*sizeof(char));
    char *phone= malloc(tele*sizeof(char));
    nodeptr aux;
    int num = 0;



    while (num == 0){
        aux=first;
        num = 1;
        printf("\n.......... Inscricao de Novo utilizador ..........\n.......... Escreva quit para regressar ...........\n\n");

        printf("Nome de Utilizador: ");
        fgets(name,cinq,stdin);
        fflush(stdin);
        name=strtok(name,"\n");

        if (strcmp(name,"quit")==0)
            return NULL;

        while(aux->next != NULL){
            if (strcmp(name,aux->name)==0){                               /* Ve se o nome de utilizador ja existe*/
                system("cls");
                printf("\n\t###### Utilizador em uso ######\n\n");
                num = 0;
            }
            aux=aux->next;
        }
    }

    strcpy(adress,"");
    while (strcmp(adress,"")==0){
        printf("Morada: ");
        fgets(adress,cem,stdin);
        fflush(stdin);
        adress=strtok(adress,"\n");
        puts(adress);
    }

    if (strcmp(adress,"quit")==0)
            return NULL;

    printf("Data de Nascimento: ");
    fgets(date,cinq,stdin);
    fflush(stdin);
    date=strtok(date,"\n");

    if (strcmp(date,"quit")==0)
            return NULL;

    printf("Telefone: ");
    fgets(phone,tele,stdin);
    fflush(stdin);
    phone=strtok(phone,"\n");

    if (strcmp(phone,"quit")==0)
            return NULL;

    while(aux->next != NULL){
            aux=aux->next;
    }

    insere(aux,name,adress,date,phone,"0/","0/");

    return aux;
}


nodeptr menulogin(nodeptr first, Local placesptr){

    int num=0;
    nodeptr userptr;

    while (num == 0){
        printf("\n.......................");
        printf("\n\t -Menu-");
        printf("\n1 - Login");
        printf("\n2 - Register");
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


int printadados(nodeptr userptr){
    printf("\n*************************\n");
    printf("Nome de Utilizador: %s\n",userptr->name);
    printf("Morada: %s\n",userptr->adress);
    printf("Data de Nascimento: %s\n",userptr->date);
    printf("Telefone: %s\n",userptr->phone);
    printf("*************************\n");
    return 2;
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
        fprintf(f,"%s\n",aux->date);
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
        return 5;
    }

    fflush(stdin);
    system("cls");

    switch (num){
            case 1:
                return 6; /*Altera user*/
            case 2:
                return 7; /*Altera morada*/
            case 3:
                return 8; /*Altera data*/
            case 4:
                return 9; /*Altera phone*/
            case 5:
                return 2; /* Vai para o perfil */

    }
    return 100;
}


int perfil(nodeptr userptr, nodeptr first){

    int num=0;

    printf("\n.........................");
    printf("\n\t -Perfil-\n");
    printf("\n1 - Mostrar dados");
    printf("\n2 - Alterar dados");
    printf("\n3 - Back");
    printf("\n.........................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 3)){   /* Caso o Utilizador nao Escolha uma das 4 opcoes */
        fflush(stdin);
        system("cls");
        return 2;
    }

    fflush(stdin);
    system("cls");

    switch (num){
            case 1:
                return 10; /* Mostrar os dados */
            case 2:
                return 5; /* Alterar Dados */
            case 3:
                return 1; /*Back to main menu*/
    }
    return 100;
}


Local localpos(Local placesptr,int num){
    int count=1;
    Local localaux=placesptr->abcnext;
    while (count!=num){
        count++;
        localaux=localaux->abcnext;
    }
    return localaux;
}


int addlocais(nodeptr userptr, Local placesptr){
    int num,i=1,prefcount=0;
    Local localaux=placesptr->abcnext;

    printf("\n..................................");
    printf("\n\t -Adicionar Locais-");
    printf("\n..................................");
    printf("\n Escolha os seus Locais favoritos");
    printf("\n..................................");

    while(localaux!=NULL){
        if (localaux->prefered==0)
            printf("\n%d - %s",i++,localaux->local);
        else if (localaux->prefered==1)
            printf("\n%d - %s *FAVORITO*",i++,localaux->local);
        localaux=localaux->abcnext;
    }
    printf("\n%d - Back",i++);
    printf("\n..................................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > i)){   /* Caso o Utilizador nao Escolha uma das opcoes */

        fflush(stdin);
        system("cls");
        return 31;
    }


    if (num==i-1){              /* BACK OPTION */

        fflush(stdin);
        system("cls");
        return 3;
    }

    prefcount=prefcountlocais(placesptr);

    localaux=localpos(placesptr,num);

    if(prefcount==3 && localaux->prefered==0){
        fflush(stdin);
        system("cls");
        printf("Remova 1 Local Preferido antes de escolher outro");
        return 31;
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
    return 31;
}


int addpdis(nodeptr userptr, Local placesptr){
    int num=0,i=1,count=1,prefcount=0,hot=0;
    Local localaux=placesptr->abcnext;
    Pdi shortener, pdiaux;
    printf("\n..................................");
    printf("\n\t -Adicionar PDI's-");
    printf("\n..................................");
    printf("\n  Escolha os seus PDI favoritos");
    printf("\n  Escolha um PDI favorito para o tornar HOT");
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
    printf("\n %2d - Back",i++);
    printf("\n..................................");
    printf("\nEscolha:");

        if (scanf("%d",&num) == 0 || (num < 1 || num > i)){   /* Caso o Utilizador nao Escolha uma das opcoes */

        fflush(stdin);
        system("cls");
        return 32;
    }

    if (num==i-1){              /* BACK OPTION */
        fflush(stdin);
        system("cls");
        return 3;
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

    fflush(stdin);
    system("cls");
    return 32;
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
    placesptr = reorganiza_pop(placesptr->abcnext);

    Local localaux = placesptr->popnext;
    Pdi pdiaux;

    while(localaux!=NULL){

    pdiaux=localaux->pontos->popnext;
    printf("%s:\n",localaux->local);

        while(pdiaux!=NULL){
            printf("%s,",pdiaux->nome);
            pdiaux = pdiaux->popnext;}

    printf("\n");
    localaux=localaux->popnext;
    }


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


int viagemcounterlocais(nodeptr userptr,char * str){
    int count=0;
    nodeptr aux=userptr;
    listanomesptr list;

    while (aux->next!=NULL){
        list=aux->ptrlocal;
        while(list->next!=NULL){
            if (strcmp(list->nome,str)==0){
                count++;
            }
            list=list->next;
        }
        aux=aux->next;
    }
    return count;
}


int viagemcounterpdi(nodeptr userptr,char * str,int num){
    int helper,count=0;
    nodeptr aux=userptr;
    listanomesptr list;

    while (aux->next!=NULL){
        list=aux->ptrpdi;
        helper=0;
        while(list->next!=NULL){
            if (strcmp(list->nome,str)==0){
                helper++;
            }
            if (helper==num){
                count++;
                break;
            }
            list=list->next;
        }
        aux=aux->next;
    }
    return count;
}


int viagem(nodeptr first,nodeptr user, Local placesptr){
    int count=prefcountlocais(placesptr);
    int localcount=0,pdicount=0;
    int percentagemlocais=0,percentagemhot=0,percentagempdi=0;
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
            printf("%d) %s\n",++localcount,localaux->local);
            percentagemlocais+=viagemcounterlocais(first,localaux->local);
            pdiaux=localaux->pontos->abcnext;
            while (pdiaux!=NULL){
                if (pdicount==3)break;

                if (pdiaux->prefered==2){
                    printf("\t%d) %s, %s\n",++pdicount,pdiaux->nome,localaux->local);
                    percentagemhot+=viagemcounterpdi(first,pdiaux->nome,2);
                    percentagempdi+=viagemcounterpdi(first,pdiaux->nome,1);
                    strcpy(helper1,pdiaux->nome);
                }
                pdiaux=pdiaux->abcnext;
            }
            pdiaux=localaux->pontos->popnext;

            while (pdiaux!=NULL){
                if (pdicount==3)break;

                if (pdiaux->prefered==1 && pdicount<3){
                    printf("\t%d) %s, %s\n",++pdicount,pdiaux->nome,localaux->local);
                    percentagemhot+=viagemcounterpdi(first,pdiaux->nome,2);
                    percentagempdi+=viagemcounterpdi(first,pdiaux->nome,1);
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
                    printf("\t%d) %s, %s\n",++pdicount,pdiaux->nome,localaux->local);
                    percentagemhot+=viagemcounterpdi(first,pdiaux->nome,2);
                    percentagempdi+=viagemcounterpdi(first,pdiaux->nome,1);
                }
                pdiaux=pdiaux->popnext;
            }
            pdicount=0;

        }
        localaux=localaux->abcnext;
    }
    printf("-%d-%d-%d-",percentagemlocais,percentagemhot,percentagempdi);



    return 100;
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

    Local placesptr=openlocal("locais.txt");

    nodeptr first=cria_user();
    nodeptr userptr;
    openfile("users.txt",first);

    do{
        userptr = menulogin(first,placesptr);
        system("cls");
    }while (userptr == NULL);

    printf("\n      -Logged in com sucesso-\n");
    printf("          Welcome, %s",userptr->name);

    while (num!=0){
        switch (num){
            case 1:
                num = mainmenu(userptr,first,placesptr);break;
                case 2:
                    num = perfil(userptr,first);break;
                    case 5:
                        num = menualtera(userptr,first);break;
                        case 6:
                            num = alterauser(userptr,first);break;
                        case 7:
                            num = alteramorada(userptr,first);break;
                        case 8:
                            num = alteradata(userptr,first);break;
                        case 9:
                            num = alteraphone(userptr,first);break;
                    case 10:
                        num=printadados(userptr);break;


                case 3:
                    num=preferencias(userptr,placesptr);break;
                    case 31:
                        num=addlocais(userptr,placesptr);break;
                    case 32:
                        num=addpdis(userptr,placesptr);break;
                case 4:
                    num = viagem(first,userptr,placesptr);break;
                case 100:
                    printf("\nerro -  a funcao chegou ao fim!\n");num=0;break;


        }
    }
    rewritelista(userptr, placesptr);
    logout(first,userptr,placesptr);
    filelocais("locais.txt",placesptr);
    return 0;
}
