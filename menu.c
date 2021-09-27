#include <stdlib.h>
#include <stdio.h>

void imprimi_menu(){
        system("cls");
        system("color 0d");
        printf("----------------------\n");
        printf("---------Menu!!-------\n");
        printf("----------------------\n");
        printf("(1)     Opcao 01      \n");
        printf("(2)     Opcao 02      \n");
        printf("(3)     Opcao 03      \n");
        printf("(4)     Opcao 04      \n");
        printf("(5)     Opcao 05      \n");
        printf("(6)     Opcao 06      \n");
        printf("(0) Sair do programa\n\n");
}

void voltar_menu(int* menu){
    voltar_menu:
    printf("---------------------------------------\n");
    printf("Voltar para o menu?? (S) sim   (N) nao \n");
    char voltar;
    scanf(" %c", &voltar);
    switch(voltar){
        case 'S':
        case 's':
            break;
        case 'N':
        case 'n':
            printf("Saindo do programa...\n\n");
            *menu = 0;
            break;
        default:
            printf("Codigo invalido.\n\n");
            goto voltar_menu;
    }
}

void imprimi_fim(){
    printf("----------------------\n");
    printf("    Ate a proxima!    \n");
    printf("----------------------\n");

}

void opcao_00(){
    printf("Saindo do programa...\n\n");
}

void opcao_01(){
    printf("Testando Opcao 01\n")
}

void opcao_02(){
    printf("Testando Opcao 02\n")
}

void opcao_03(){
    printf("Testando Opcao 03\n")
}

void opcao_04(){
    printf("Testando Opcao 04\n")
}

void opcao_05(){
    printf("Testando Opcao 05\n")
}

void opcao_06(){
    printf("Testando Opcao 06\n")
}


int main(){

    int menu;

    do{

        imprimi_menu();

        escolher_opcao:
        printf("----------------------\n");
        printf("  Qual opcao deseja?  \n");
        printf("----------------------\n");
        scanf("%d", &menu);
        system("cls");
        
        switch(menu){
            case 0:
                opcao_00();
                break;
            case 1:
                system("color 01");
                opcao_01();
                voltar_menu(&menu);
                break;
            case 2:
                system("color 02");
                opcao_02();
                voltar_menu(&menu);
                break;
            case 3:
                system("color 03");
                opcao_03();
                voltar_menu(&menu);
                break;
            case 4:
                system("color 04");
                opcao_04();
                voltar_menu(&menu);
                break;
            case 5:
                system("color 05");
                opcao_05();
                voltar_menu(&menu);
                break;
            case 6:
                system("color 06");
                opcao_06();
                voltar_menu(&menu);
                break;
            default:
                printf("Digite uma opcao valida!\n");
                goto escolher_opcao;
        }

    }while(menu);
        imprimi_fim();
        
}
