#ifndef LOCAIS_H_INCLUDED
#define LOCAIS_H_INCLUDED

typedef struct localnode*Local;
typedef struct pdinode*Pdi;

typedef struct localnode{
    char *local;
    int pop;
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
    Local sitio;
    Pdi popnext;
    Pdi abcnext;
}pdi_node;

Local openlocal(char *);

#endif
