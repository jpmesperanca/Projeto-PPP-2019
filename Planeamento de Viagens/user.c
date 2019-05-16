#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#define cinq 50
#define cem 100
#define tele 10



nodeptr cria_user(){
    nodeptr aux;
    aux=(nodeptr)malloc(sizeof(utilizador_node));

    if (aux!=NULL){
        aux->name=malloc(cinq*sizeof(char));
        aux->adress=malloc(cem*sizeof(char));
        aux->date=malloc(cinq*sizeof(char));
        aux->phone=malloc(tele*sizeof(char));
        aux->localnext=NULL;
        aux->pdinext=NULL;
        aux->next=NULL;
    }
    return aux;
}


nodeptr insere(nodeptr fnl,char *nome,char *morada,char *data,char *telefone){
    nodeptr aux=fnl;
    aux->name=nome;
    aux->adress=morada;
    aux->date=data;
    aux->phone=telefone;
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

void preferedfile(char *file,nodeptr ptr,Local placesptr){
    FILE *f=fopen(file,"r");

    nodeptr aux=ptr;
    Local placesaux=placesptr;
    Pdi pdis;
    int i=0,num=0;
    char *tudo,*str;
    char etc;
    while (fscanf(f, "%c\n", &etc) == 1){

        fflush(stdin);
        tudo=malloc(cem*sizeof(char));
        str=malloc(cem*sizeof(char));

        fgets(str,cem,f);                  /* NOME */
        str=strtok(str,"\n");

        fgets(tudo,cem,f);                 /* ADERECO */
        fgets(tudo,cem,f);                  /* DATA */
        fgets(tudo,cem,f);                 /* PHONE */
        if (strcmp(str,aux->name)==0){
            /* LOCAIS */
            fgets(tudo,cem,f);                 /* LOCAIS*/
            sscanf(tudo,"%d/%[^\n]",&num,str);
            for(i=0;i<num;i++){
                if (i==0)
                    str=strtok(str,"/");
                else if (i==num)
                    str=strtok(NULL,"\n");
                else
                    str=strtok(NULL,"/");
                placesaux=placesptr;

                while (placesaux->abcnext!=NULL){

                    if (strcmp(placesaux->local,str)==0){
                        placesaux->prefered=1;

                        break;
                    }

                    placesaux=placesaux->abcnext;
                }
            }

            /* PONTOS DE INTERESSE */
            tudo=malloc(cem*sizeof(char));
            fgets(tudo,cem,f);                  /* PDIS */
            sscanf(tudo,"%d/%[^\n]",&num,str);
            for(i=0;i<num;i++){
                if (i==0)
                    str=strtok(str,"/");
                else if (i==num)
                    str=strtok(NULL,"\n");
                else
                    str=strtok(NULL,"/");
                placesaux=placesptr;
                while (placesaux->abcnext!=NULL){
                    pdis=placesaux->pontos;
                    while (pdis->abcnext==0){
                        if (strcmp(pdis->nome,str)==0){
                            pdis->prefered=1;
                            break;
                        }
                        pdis=pdis->abcnext;
                    }
                    placesaux=placesaux->abcnext;
                }
            }
        }
        else{
            fgets(tudo,cem,f);                 /* LOCAIS*/
            fgets(tudo,cem,f);                 /* PDIS*/
        }
    }
}


nodeptr openfile(char *file,nodeptr ptr){

    nodeptr aux=ptr;
    FILE *f=fopen(file,"r");
    char *nome,*adereco,*data,*telefone;
    char *trash;
    char etc;


    while(fscanf(f, "%c\n", &etc) == 1){  /* SALTAR \N */

        fflush(stdin);
        nome=malloc(cinq*sizeof(char));
        adereco=malloc(cem*sizeof(char));
        data=malloc(cinq*sizeof(char));
        telefone=malloc(tele*sizeof(char));
        trash=malloc(cem*sizeof(char));

        fgets(nome,cinq,f);
        nome=strtok(nome,"\n");

        fgets(adereco,cem,f);
        adereco=strtok(adereco,"\n");

        fgets(data,cinq,f);
        data=strtok(data,"\n");

        fgets(telefone,tele,f);
        telefone=strtok(telefone,"\n");

        fgets(trash,cem,f);
        fgets(trash,cem,f);

        aux=insere(aux,nome,adereco,data,telefone);
    }
    fclose(f);
    return aux;
}


void inserefile(char *file,nodeptr ptr){
    nodeptr aux=ptr;
    FILE *f=fopen(file,"a");
    fprintf(f,"\n\n");
    fprintf(f,"%s\n",aux->name);
    fprintf(f,"%s\n",aux->adress);
    fprintf(f,"%s\n",aux->date);
    fprintf(f,"%s",aux->phone);
    fclose(f);
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
