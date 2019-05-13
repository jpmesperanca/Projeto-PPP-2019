#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locais.h"
#define vinte5 25

void openlocal(char *file){

    FILE *f=fopen(file,"r");
    int check=0;
    char *local,*pdi;
    char etc;


    while(fscanf(f, "%c\n", &etc) == 1){  /* SALTAR \N */
        fflush(stdin);
        if (etc==' ')
            check=0;
        local=malloc(vinte5*sizeof(char));
        pdi=malloc(vinte5*sizeof(char));
        if (check==0){
            fgets(local,vinte5,f);
            local=strtok(local,"\n");
            printf("\n%s\n",local);
            check=1;
        }
        if (check==1){
            fgets(pdi,vinte5,f);
            pdi=strtok(pdi,"\n");
            printf("%s\n",pdi);
        }

    }
    fclose(f);
}
