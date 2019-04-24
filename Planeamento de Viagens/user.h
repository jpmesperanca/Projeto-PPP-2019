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
void print(nodeptr);
nodeptr insere(nodeptr ,char *,char *,char *,char *);
void openfile(char *,nodeptr);

#endif
