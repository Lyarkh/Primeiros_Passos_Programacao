#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

//variáveis globais
char palavra_secreta[TAMANHO_PALAVRA];
char chutes[26];
int chutes_dados = 0;

void adiciona_palavra() {
    char codigo;

    printf("Voce deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &codigo);

    if(codigo == 'S' || codigo == 's'){
        char nova_palavra[TAMANHO_PALAVRA];

        printf("Digite a nova palavra, em letras maiusculas: ");
        scanf("%s", nova_palavra);

        FILE* f;

        f = fopen("palavras.txt", "r+");
        if(f == 0) {
            printf("Banco de dados de palavras nao disponvel\n\n");
            exit(1);
        }

        int quantidade;
        fscanf(f, "%d", &quantidade);
        quantidade++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", quantidade);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", nova_palavra);

        fclose(f);

    }else{
        printf("Encerrando programa...");
    }

}

void abertura(){
    printf("*************************\n");
    printf("******Jogo da forca******\n");
    printf("*************************\n\n");
}
void chuta(){
    char chute;
    scanf(" %c", &chute);

    chutes[chutes_dados] = chute;
    (chutes_dados)++;
}
 
 int ja_chutou(char letra){
    int achou = 0;

    for(int j = 0;j < chutes_dados; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
 }

void escolha_palavra(){
    FILE* f;

    f = fopen("palavras.txt", "r");
    if (f == 0){
        printf("O banco de dados não está disponivel.\n\n");
        exit(1);
    }
    int quantidade_de_palavras;
    fscanf(f, "%d", &quantidade_de_palavras);

    srand(time(0));
    int numero_random = rand() % quantidade_de_palavras;

    for(int i = 0; i <= numero_random; i++){
        fscanf(f, "%s", palavra_secreta);

    }
    fclose(f);

}
void desenha_forca(){
    printf("\n");
    for(int i = 0; i < strlen(palavra_secreta); i++){

        int achou = ja_chutou(palavra_secreta[i]);
        
            
        if(achou){
            printf("%c ", palavra_secreta[i]);
        }else{
            printf("_ ");
        }
    }
    printf("\n");
}

int enforcou(){
    int erros = 0;

    for(int i = 0; i < chutes_dados; i++){
        int existe = 0;
        for(int j = 0; j < strlen(palavra_secreta); j++){
            if(chutes[i] == palavra_secreta[j]){
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
            
    }
    return erros >= 5;
}

void imprimi_ganhador(){
    printf("\nParabens, voce ganhou!  \n");
    printf("       ___________        \n");
    printf("      '._==_==_=_.'       \n");
    printf("      .-\\:      /-.      \n");
    printf("     | (|:.     |) |      \n");
    printf("      '-|:.     |-'       \n");
    printf("        \\::.    /        \n");
    printf("         '::. .'          \n");
    printf("           ) (            \n");
    printf("         _.' '._          \n");
    printf("        '-------'       \n\n");

}

void imprimi_perdedor(){
    printf("\n  Poxa, voce foi enforcado! \n");
    printf("\nA palavra era %s.\n", palavra_secreta); 
    printf("    _______________            \n");
    printf("   /               \\          \n");
    printf("  /                 \\         \n");
    printf("//                   \\/\\     \n");
    printf("\\|   XXXX     XXXX   | /      \n");
    printf(" |   XXX       XXX   |         \n");
    printf(" |                   |         \n");
    printf(" \\__      XXX      __/        \n");
    printf("   |\\     XXX     /|          \n");
    printf("   | |           | |           \n");
    printf("   | I I I I I I I |           \n");
    printf("   |  I I I I I I  |           \n");
    printf("   \\_             _/          \n");
    printf("     \\_         _/            \n");
    printf("       \\_______/            \n\n");

}

int acertou(){
    for(int i =0; i < strlen(palavra_secreta); i++){
        if(!ja_chutou(palavra_secreta[i])){
            return 0;
        }
    }
    return 1;

}

int main(){   

    escolha_palavra();
    abertura();

    do{
    
        desenha_forca();
        chuta();
               
    } while(!acertou() && !enforcou()); 

    if(acertou()){
        imprimi_ganhador();

    }else{
        imprimi_perdedor();


    }
    adiciona_palavra();
}