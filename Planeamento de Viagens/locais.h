#ifndef LOCAIS_H_INCLUDED
#define LOCAIS_H_INCLUDED

typedef struct localnode*local;
typedef struct pdinode*pdi;

typedef struct localnode{
    char *local;
    pdi pontos;
    local popnext;
    local abcnext;
}local_node;

typedef struct node{
    char *nome;
    int prefered;
    local sitio;
    pdi next;
}pdi_node;

void openlocal(char *);

#endif
