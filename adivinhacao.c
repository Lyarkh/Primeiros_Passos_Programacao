#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("********************************\n");
    printf("Bem vindo ao jogo de adivinhacao\n");
    printf("********************************\n");
    
    int seed = time(0);
    srand(seed);
    int numero = rand();
    int numero_secreto = (numero % 100);

    int chute;
    int tentativas = 1;
    double pontos_total = 1000;
    int nivel = 0;
    int tentativas_total;

    printf("----------Dificuldades------\n");
    printf("(1) facil (2) medio (3) dificil\n");

    int cod_nivel = (nivel != 1) && (nivel != 2) && (nivel != 3);
    int acertou = 0;

    while(cod_nivel){
        printf("Qual dificudade deseja? ");
        scanf("%d", &nivel);

        if(nivel == 1){
            tentativas_total = 20;
            break;
        }
        else if (nivel == 2){
            tentativas_total = 12;
            break;
        }
        else if (nivel == 3){
            tentativas_total = 6;
            break;
        }
        else{
            printf("Digite um codigo valido!\n");
            continue;
        }

    }

    for(int i = 1; i <= tentativas_total; i++){

        printf("Tentativa %d\n",tentativas);
        printf("Qual o seu chute: \n");
        scanf("%d", &chute);

        if(chute < 0){
            printf("Nao pode digitar numero negativo!\n");
            continue;
        }

        int acertou = (chute == numero_secreto);
        int maior = (chute > numero_secreto);

        if (acertou){
            break;
        }
        else if (maior){
            printf("O numero e maior que o numero secreto\n");
            }
        else{
            printf("O numero e menor que o numero secreto\n");
            }
        tentativas++;

        double pontos_perdidos = abs(chute - numero_secreto) / (double)2;
        pontos_total = (pontos_total - pontos_perdidos);
    }

    if(acertou==0){
        printf("***************\n");
        printf("----Parabens, voce ganhou!!----\n");
        printf("Voce acertou em %d tentativas\n", tentativas - 1);
        printf("Voce fez %.1f pontos!\n", pontos_total);
    }
    else {
        printf("***************\n");
        printf("Voce Perdeu!\n");

    }
    printf("***************\n");
    printf("*Fim de Jogo!!*\n");
    printf("***************\n");

    return 0;

}
