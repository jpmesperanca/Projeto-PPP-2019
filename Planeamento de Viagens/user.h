#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include "locais.h"
typedef struct lnode*nodeptr;

typedef struct lnode{
    char *name;
    char *adress;
    char *date;
    char *phone;
    Local localnext;
    Pdi pdinext;
    nodeptr next;
}utilizador_node;

nodeptr cria_user(void);

int print(nodeptr);

nodeptr insere(nodeptr ,char *,char *,char *,char *);

void preferedfile(char *,nodeptr ,Local );

nodeptr openfile(char *,nodeptr);

void inserefile(char *,nodeptr);

int alterauser(nodeptr ,nodeptr);

int alteramorada(nodeptr ,nodeptr);

int alteradata(nodeptr ,nodeptr);

int alteraphone(nodeptr ,nodeptr);

#endif
