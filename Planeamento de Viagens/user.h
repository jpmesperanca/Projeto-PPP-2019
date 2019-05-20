#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include "locais.h"

typedef struct lnode*nodeptr;
typedef struct nomesnode*listanomesptr;

typedef struct nomesnode{

    char* nome;
    listanomesptr next;

}listanomes_node;

typedef struct lnode{
    char *name;
    char *adress;
    char *date;
    char *phone;
    char *local;
    char *pdi;
    listanomesptr ptrlista;
    nodeptr next;
}utilizador_node;

nodeptr cria_user(void);

listanomesptr cria_nomes();

int print(nodeptr);

nodeptr insere(nodeptr ,char *,char *,char *,char *,char *, char *);

void preferedfile(nodeptr ,Local );

nodeptr openfile(char *,nodeptr);

void inserefile(nodeptr, Local);

int alterauser(nodeptr ,nodeptr);

int alteramorada(nodeptr ,nodeptr);

int alteradata(nodeptr ,nodeptr);

int alteraphone(nodeptr ,nodeptr);

#endif
