#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include "locais.h"

typedef struct lnode*nodeptr;
typedef struct nomesnode*listanomesptr;

typedef struct nomesnode{

    char* nome;
    int hot;
    listanomesptr next;

}listanomes_node;

typedef struct lnode{
    char *name;
    char *adress;
    int day;
    int month;
    int year;
    char *phone;
    char *local;
    char *pdi;
    int tripcheck;
    listanomesptr ptrlocal;
    listanomesptr ptrpdi;
    nodeptr next;
}utilizador_node;

nodeptr cria_user(void);

listanomesptr cria_nomes();

int print(nodeptr);

nodeptr insere(nodeptr ,char *,char *,int, int ,int ,char *,char *, char *);

void preferedfile(nodeptr ,Local );

nodeptr openfile(char *,nodeptr);

void inserefile(nodeptr, Local);

int alterauser(nodeptr ,nodeptr);

int alteramorada(nodeptr ,nodeptr);

int alteradata(nodeptr ,nodeptr);

int alteraphone(nodeptr ,nodeptr);

int prefcountlocais(Local);

int prefcountpdis(Local);

void rewritelista(nodeptr,Local);

int countlist(listanomesptr );

#endif
