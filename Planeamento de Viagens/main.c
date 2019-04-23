#include <stdio.h>
#include <stdlib.h>

void login(){printf("login");}
void regist(){printf("regist");}


void menu(){
    int num=0;
    printf(".......................");
    printf("\n\t -Menu-");
    printf("\n1 - Login");
    printf("\n2 - Register");
    printf("\n.......................");
    printf("\nEscolha: ");
    if (scanf("%d",&num) == 0 || (num < 1 || num > 2)) {
        fflush(stdin);
        menu();
    }
    switch (num){
            case 1:
                printf("login()");break;
            case 2:
                printf("regist()");break;
    }
}

int main()
{
    menu();
    return 0;
}

