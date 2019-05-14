#ifndef LOCAIS_H_INCLUDED
#define LOCAIS_H_INCLUDED
#include "locais.h"

typedef struct localnode*Local;
typedef struct pdinode*Pdi;

typedef struct localnode{
    char *local;
    int pop;
    int prefered;
    Pdi pontos;
    Local popnext;
    Local abcnext;
    Local usernext;
}local_node;

typedef struct pdinode{
    char *nome;
    char *descricao;
    char *horario;
    int pop;
    int prefered;
    Local sitio;
    Pdi popnext;
    Pdi abcnext;
    Pdi usernext;
}pdi_node;

Local cria_local();

Local openlocal(char *);

#endif
