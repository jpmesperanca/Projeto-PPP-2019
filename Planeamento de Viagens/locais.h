#ifndef LOCAIS_H_INCLUDED
#define LOCAIS_H_INCLUDED
#include "locais.h"

typedef struct localnode*Local;
typedef struct pdinode*Pdi;

typedef struct localnode{
    char *local;
    int pop;
    int prefered;
    int pdinum;
    Pdi pontos;
    Local popnext;
    Local abcnext;
}local_node;

typedef struct pdinode{
    char *nome;
    char *descricao;
    char *horario;
    int pop;
    int prefered;
    Pdi popnext;
    Pdi abcnext;
}pdi_node;

Local cria_local();

Local openlocal(char *);

void filelocais(char *file,Local placesptr);

void reorganiza_pop(Local,Local);

void reorganiza_pop_p(Local,Pdi);

void insere_pdi(Local, char*, char*, char*, int, int);

#endif
