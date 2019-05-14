#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

typedef struct lnode*nodeptr;

typedef struct lnode{
    char *name;
    char *adress;
    char *date;
    char *phone;

    nodeptr next;
}utilizador_node;

nodeptr cria_user(void);

int print(nodeptr);

nodeptr insere(nodeptr ,char *,char *,char *,char *);

nodeptr openfile(char *,nodeptr);

void inserefile(char *,nodeptr);

int alterauser(nodeptr ,nodeptr);

int alteramorada(nodeptr ,nodeptr);

int alteradata(nodeptr ,nodeptr);

int alteraphone(nodeptr ,nodeptr);

#endif
