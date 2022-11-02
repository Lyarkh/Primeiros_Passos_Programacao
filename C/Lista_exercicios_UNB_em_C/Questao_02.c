#include <stdio.h>
#include <stdlib.h>


// Convertendo segundos em horas, minutos e segundos.

int main()
{
    int N;
    scanf("%d", &N);
    int horas, resto, minutos, segundos;

    horas = N / 3600;
    resto = N % 3600;
    minutos = resto / 60;
    segundos = resto % 60;

    printf("%d : %d : %d\n", horas, minutos, segundos);

    return 0;
}
