#include <stdio.h>
#include <stdlib.h>

void login(){printf("login");}
void regist(){printf("regist");}


void menu(){
    char num='0';
    printf(".......................");
    printf("\n\t -Menu-");
    printf("\n1 - Login");
    printf("\n2 - Register");
    printf("\n.......................");
    printf("\nEscolha: ");
    scanf("%c",&num);   /* SCANF IS A PAIN IN THE ASS - THANK YOU */
    switch (num){
        case '1':
            login();break;
        case '2':
            regist();break;
        default:
            menu();break;
    }
}

int main()
{
    menu();
    return 0;
}

